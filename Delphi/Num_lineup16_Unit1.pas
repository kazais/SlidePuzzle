unit Num_lineup16_Unit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes,
  System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs,
  FMX.Controls.Presentation, FMX.StdCtrls, FMX.Layouts, FMX.Ani, FMX.TabControl,
  FMX.Edit, FMX.EditBox, FMX.SpinBox, FMX.Effects, FMX.ListBox, FMX.ScrollBox,
  FMX.Memo, System.Actions, FMX.ActnList, FMX.Gestures, FMX.Objects,
  FMX.MultiView;

type
  TmyPosition = record
    X: Single;
    Y: Single;
  end;

type
  TForm1 = class(TForm)
    ScaledLayout1: TScaledLayout;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    FlButtonAnimation: TFloatAnimation;
    Button10: TButton;
    Button11: TButton;
    Button12: TButton;
    Button13: TButton;
    Button14: TButton;
    Button15: TButton;
    Button16: TButton;
    TabControlSetting: TTabControl;
    Tile: TTabItem;
    Setting: TTabItem;
    GlowEffectTile: TGlowEffect;
    FloatAnimationTileGrow: TFloatAnimation;
    tbSetting: TToolBar;
    tbTile: TToolBar;
    Label1: TLabel;
    Label2: TLabel;
    btnNewGame: TButton;
    GlowEffectNewGame: TGlowEffect;
    FloatAnimationNewGame: TFloatAnimation;
    SpinBox1: TSpinBox;
    cbTileRect: TComboBox;
    lbSetting: TListBox;
    ListBoxItem1: TListBoxItem;
    ListBoxItem2: TListBoxItem;
    ListBoxItem3: TListBoxItem;
    btnGotoSetting: TButton;
    btnGotoTile: TButton;
    GlowEffectGotoSetting: TGlowEffect;
    FloatAnimationGotoSetting: TFloatAnimation;
    GestureManager1: TGestureManager;
    ActionList1: TActionList;
    NextTabAction1: TNextTabAction;
    PreviousTabAction1: TPreviousTabAction;
    ListBoxGroupHeader1: TListBoxGroupHeader;
    ListBoxGroupHeader2: TListBoxGroupHeader;
    ListBoxItem4: TListBoxItem;
    Switch1: TSwitch;
    StyleBook1: TStyleBook;
    ListBoxGroupFooter1: TListBoxGroupFooter;
    MultiView1: TMultiView;
    btnMaster: TButton;
    ToolBar1: TToolBar;
    Label3: TLabel;
    TrackBar1: TTrackBar;
    Layout1: TLayout;
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure FlButtonAnimationFinish(Sender: TObject);
    procedure btnNewGameClick(Sender: TObject);
    procedure cbTileRectChange(Sender: TObject);
    procedure btnGotoSettingClick(Sender: TObject);
    procedure btnGotoTileClick(Sender: TObject);
    procedure NextTabAction1Update(Sender: TObject);
    procedure PreviousTabAction1Update(Sender: TObject);
    procedure Switch1Switch(Sender: TObject);
    procedure ListBoxGroupFooter1Click(Sender: TObject);
    procedure TrackBar1Change(Sender: TObject);
    procedure MultiView1StartShowing(Sender: TObject);
    procedure MultiView1Hidden(Sender: TObject);
  private
    { private �錾 }
    procedure SetNewGame; //�V�K�Q�[���J�n�葱�Ăяo���̂��߂́A�ق��葱���܂Ƃ߂ČĂяo��
    procedure SetInitTilePos; //�^�C���ʒu�̏�������
    procedure SetInvisibleTile;  //�B���^�C������
    procedure ShuffleTiles;       //�^�C���ʒu�V���b�t��
    procedure ChangeBtnPlace(btnFirst: TButton; btnSecond: TButton); //�V���b�t�����Ƀ{�^���̈ʒu����ւ��̂��߂̎葱��

    procedure btnPushed(btn: TButton);     //�^�C�����N���b�N���ꂽ����|�W�V�����`�F�b�N���Ăяo�����߂̎葱��
    procedure NextPosChk(btn: TButton);     //���������Ȃ��^�C�����`�F�b�N
    procedure ButtonAni(btn: TButton; PName: string; StpValue: Single);   //�^�C���ړ��A�j���̎葱��
    function CheckFin: Boolean;     //�^�C���Ȃ�ׂ��������Ă��邩�`�F�b�N
    procedure CompleteSet;           //���������ꍇ�̏���

    procedure SetTileRect;    //�^�C���\�����@�̐؂�ւ��i�����`���t�B�b�g���j
    function FindTagBtn(tag: Integer): TButton;     //�{�^���̎����Ă���^�O��񂩂�Ώۂ̃{�^���I�u�W�F�N�g������
    function GetTilePosition(tag: Integer): TmyPosition;     //�^�O��񂩂�{�^���̍��W����������

  public
    { public �錾 }
  end;

var
  Form1: TForm1;

implementation

{$R *.fmx}

uses TilesVersionUnit2;�@//�G���o�J�f���@���S�t�H�[���Ăяo�����߂�Uses

var     //�O���[�o���ϐ�
  btnMoving, btnInvisibleTile: TButton;   //�����Ă���{�^���A�����Ă���{�^�����o���Ƃ�
  iNumOfBtn: Integer;      //�^�C�������o���Ă���
  FComp: Boolean;          //�������Ă��邩�t���O
  slpx, slpy: Single;

procedure TForm1.btnGotoSettingClick(Sender: TObject);
begin
//�ݒ��ʂւ̃{�^���������ꂽ��X���C�h
  TabControlSetting.SetActiveTabWithTransition(Setting, TTabTransition.Slide,
    TTabTransitionDirection.Reversed);
end;

procedure TForm1.btnGotoTileClick(Sender: TObject);
begin
//�^�C����ʂւ̃{�^���������ꂽ��X���C�h
  TabControlSetting.SetActiveTabWithTransition(Tile, TTabTransition.Slide,
    TTabTransitionDirection.Normal);
end;

procedure TForm1.Button1Click(Sender: TObject);
//�^�C���������ꂽ�C�x���g������A�{�^�����ƂƂ��Ƀ{�^�������ꂽ��̓��ꏈ���֑���
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button2Click(Sender: TObject);
//�ȉ�����
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.Button9Click(Sender: TObject);
begin
  btnPushed(TButton(Sender));
end;

procedure TForm1.cbTileRectChange(Sender: TObject);
begin
//�^�C���̕\�����@�R���{���ύX���ꂽ�Ƃ��̃C�x���g
  SetTileRect;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
//�t�H�[���N���G�C�g���̏����ݒ�
  TabControlSetting.ActiveTab := Setting;
  Tile.Enabled := False;
  btnGotoTile.Enabled := False;
end;

function TForm1.GetTilePosition(tag: Integer): TmyPosition;
//�I�u�W�F�N�g�̃^�O��񂩂�^�C���ʒu������o��
var
  iLine: Integer;
  myPos: TmyPosition;
  Y, X, iCount: Integer;
begin
  myPos.X := -1;
  myPos.Y := -1;
  // �͈͊O�Ȃ� -1   �Ԃ��Ƃ�
  if (tag <= 0) or (tag > iNumOfBtn) then
    Exit(myPos);

  // ���̐�������o��
  iCount := 1;
  iLine := round(sqrt(iNumOfBtn));

  for Y := 0 to (iLine - 1) do
  begin
    for X := 0 to (iLine - 1) do
    begin
      if iCount = tag then
      begin
        myPos.X := X;
        myPos.Y := Y;
        Exit(myPos);
      end;
      iCount := iCount + 1;
    end;
  end;
  Result := myPos;
end;

procedure TForm1.ListBoxGroupFooter1Click(Sender: TObject);
begin
//�G���o�J�f�����S�\��
  Form2.Height := Form1.Height;
  Form2.Width := Form1.Width;
  Form2.Top := Form1.Top + 50;
  Form2.Left := Form1.Left +50;
  Form2.Show;
end;

procedure TForm1.MultiView1Hidden(Sender: TObject);
begin
//�}���`�r���[���B���Ƃ��A�ݒ胊�X�g�����Ƃ̐ݒ�^�u�̕Ԃ�
  setting.AddObject(lbSetting);
end;

procedure TForm1.MultiView1StartShowing(Sender: TObject);
begin
// Multi View�������Ƃ��A�ݒ胊�X�g���}���`�r���[�ɏ悹������
 if lbSetting = nil then
 begin
   lbSetting.Create(self);
 end;

 Layout1.AddObject(lbSetting);
end;

procedure TForm1.ButtonAni(btn: TButton; PName: string; StpValue: Single);
begin
  // �{�^���̈ړ��̃A�j���[�V�����ݒ�
  slpx := btn.Position.X;
  slpy := btn.Position.Y; // �{�^���̈ꎞ�L��
  btnMoving := btn;
  btn.AddObject(TFmxObject(FlButtonAnimation)); // �A�j���[�V�������A�^�b�`
  FlButtonAnimation.PropertyName := PName;
  FlButtonAnimation.StopValue := StpValue;
  if SpinBox1.Value <> 0 then
    FlButtonAnimation.Duration := SpinBox1.Value / 10
  else
    FlButtonAnimation.Duration := 0.01;
  btn.Enabled := False;
  FlButtonAnimation.Start;
end;



procedure TForm1.ChangeBtnPlace(btnFirst, btnSecond: TButton);
//�����{�^���z��̂��߂̃{�^���V���b�t���p
var
  posTemp: TmyPosition;
  iTag: Integer;
begin
  // First�̏ꏊ���ꎞ�L��
  posTemp.X := btnFirst.Position.X;
  posTemp.Y := btnFirst.Position.Y;
  iTag := btnFirst.tag;

  // first��Second�̏ꏊ�Ɉړ�
  btnFirst.Position.X := btnSecond.Position.X;
  btnFirst.Position.Y := btnSecond.Position.Y;
  btnFirst.tag := btnSecond.tag;

  // Secound �� ��First�΂����
  btnSecond.Position.X := posTemp.X;
  btnSecond.Position.Y := posTemp.Y;
  btnSecond.tag := iTag;
end;

function TForm1.CheckFin: Boolean;
//�{�^���̃A�j���I����ɌĂ΂��\��́A�Q�[�������`�F�b�N
var
  I: Integer;
begin
  // tag �̐��l�ƃ{�^���̐��l���S��������Ă�Ί����I
  for I := 0 to ScaledLayout1.Children.Count - 1 do
  begin
    if (ScaledLayout1.Children.Items[I] is TButton) then
    begin
      if TButton(ScaledLayout1.Children.Items[I]).tag.ToString <>
        TButton(ScaledLayout1.Children.Items[I]).Text then
        Exit(False);
    end;
  end;
  Result := True;

end;

procedure TForm1.CompleteSet;
begin
  // �Q�[���B������
  btnInvisibleTile.Opacity := 0; // �����Ȃ����Ă���
  btnInvisibleTile.Visible := True;
  btnInvisibleTile.SetFocus;
  btnInvisibleTile.AddObject(TFmxObject(FlButtonAnimation)); // �A�j���[�V�������A�^�b�`
  FlButtonAnimation.PropertyName := 'Opacity';
  FlButtonAnimation.StopValue := 0.9;
  FlButtonAnimation.Duration := 1; // �Ō�̃^�C���o�����v����
  FlButtonAnimation.Start;
  FComp := True;

  // NewGame�{�^���s�J�s�J������
  GlowEffectNewGame.Enabled := True;
  FloatAnimationNewGame.Start;

  // �ݒ�s���{�^���s�J�s�J������
  GlowEffectGotoSetting.Enabled := True;
  FloatAnimationGotoSetting.Start;

  // �^�C���s�J-������
  FloatAnimationTileGrow.StartValue := 0;
  GlowEffectTile.Enabled := True;
  FloatAnimationTileGrow.Start;
end;

function TForm1.FindTagBtn(tag: Integer): TButton;
//�{�^���̎����Ă�^�O��񂩂玩���̈ʒu������o��
var
  I: Integer;
begin
  // �������{�^���͈̔͊O��������nil
  if (tag <= 0) or (tag > iNumOfBtn) then
    Exit(nil);
  // �X�P�[�����C�A�E�g���̎q���̐�������
  for I := 0 to ScaledLayout1.Children.Count - 1 do
  begin
    if (ScaledLayout1.Children.Items[I] is TButton) then // �{�^���Ȃ�
    begin
      if TButton(ScaledLayout1.Children.Items[I]).tag = tag then
        Exit(TButton(ScaledLayout1.Children.Items[I]));
    end;
  end;
  // �����܂ł��Č�����Ȃ������玸�s
  Result := nil;
end;

procedure TForm1.FlButtonAnimationFinish(Sender: TObject);
//�{�^���ړ��̃A�j���[�V����������̏���
var
  iTmpTag: Integer;
begin
  // �ړ���̃{�^���L�����ƁA�C���r�V�u���^�C���̈ړ�
  if (not FComp) then
  begin
    btnMoving.Enabled := True;
    // �ړ����������ł������`�F�b�N�i�C���r�W�̈ʒu�܂œ�������)
    if (btnMoving.Position.X = btnInvisibleTile.Position.X) and
      (btnMoving.Position.Y = btnInvisibleTile.Position.Y) then
    begin
      // �C���r�W�^�C���̈ړ�
      iTmpTag := btnMoving.tag;
      btnInvisibleTile.Position.X := slpx;
      btnInvisibleTile.Position.Y := slpy;
      btnMoving.tag := btnInvisibleTile.tag;
      btnInvisibleTile.tag := iTmpTag;
    end;

  end;
  // �R���v���[�g�`�F�b�N
  if CheckFin and (not FComp) then
    CompleteSet;
end;

procedure TForm1.NextPosChk(btn: TButton);
//�{�^�����N���b�N���ꂽ�Ƃ��A�C���r�W�^�C�������ɂ��邩�`�F�b�N���ē�����
var
  posTemp, myPos, InvPos: TmyPosition;
begin
  // �󂫃^�C���Ƃ̍������߂�
  myPos := GetTilePosition(btn.tag);
  InvPos := GetTilePosition(btnInvisibleTile.tag);

  posTemp.X := myPos.X - InvPos.X;
  posTemp.Y := myPos.Y - InvPos.Y;
  // X��̓��ꐫ�`�F�b�N& ���񂪗ׂ�
  if (posTemp.X = 0) and (posTemp.Y >= -1) and (posTemp.Y <= 1) then
  begin
    // �ׂȂ�{�^���ړ��A�j��
    ButtonAni(btn, 'Position.Y', btnInvisibleTile.Position.Y);
  end;
  // y��̓��ꐫ�`�F�b�N& ���񂪗ׂ�
  if (posTemp.Y = 0) and (posTemp.X >= -1) and (posTemp.X <= 1) then
  begin
    // �ׂȂ�{�^���ړ��A�j��
    ButtonAni(btn, 'Position.X', btnInvisibleTile.Position.X);
  end;
end;

procedure TForm1.NextTabAction1Update(Sender: TObject);
//�W�F�X�`���[�ŌĂяo�����A�N�V����
begin
  // �W�F�X�`���[�ŉE���獶�B�^�C����ʌĂяo��
  if (btnGotoTile.Enabled = True) and (TabControlSetting.TabIndex = 0) then
    TabControlSetting.SetActiveTabWithTransition(Tile, TTabTransition.Slide,
      TTabTransitionDirection.Normal);
end;

procedure TForm1.PreviousTabAction1Update(Sender: TObject);
//�W�F�X�`���[�ŌĂяo�����A�N�V����
begin
  // �W�F�X�`���[�ō�����E�B�ݒ��ʌĂяo��
  if (btnGotoSetting.Enabled = True) and (TabControlSetting.TabIndex = 1) then
    TabControlSetting.SetActiveTabWithTransition(Setting, TTabTransition.Slide,
      TTabTransitionDirection.Reversed);
end;

procedure TForm1.SetInitTilePos;
//�{�^���̈ʒu�̏����ݒ�ƃ{�^���ʒu������o���₷�����邽�߂̃^�O�ݒ�
var
  I: Integer;
  iTile: Integer;
  Pos: TmyPosition;
  iNum: Integer;
begin
  // �������{�^�����N���A
  // �^�C�������ꂢ�ɂȂ�ׂȂ���
  iNumOfBtn := 0;

  // �{�^���̐����擾
  for I := 0 to ScaledLayout1.Children.Count - 1 do
  begin
    if ScaledLayout1.Children.Items[I] is TButton then
      iNumOfBtn := iNumOfBtn + 1;
  end;

  // ���̐�������o��
  iTile := round(sqrt(iNumOfBtn));

  // �{�^���̈ʒu���m�F���邽�߂̔�rPosition
  Pos.X := 0;
  Pos.Y := 0;

  // �q������т����Ɗ�{�A�����ǂ��Ăяo��
  iNum := 1;
  for I := 0 to ScaledLayout1.Children.Count - 1 do
  begin
    // �{�^���Ȃ�
    if (ScaledLayout1.Children.Items[I] is TButton) then
    begin
      // �ʒu�ݒ�
      TButton(ScaledLayout1.Children.Items[I]).Position.X := Pos.X;
      TButton(ScaledLayout1.Children.Items[I]).Position.Y := Pos.Y;
      //
      TButton(ScaledLayout1.Children.Items[I]).Enabled := True;
      TButton(ScaledLayout1.Children.Items[I]).Visible := True;
      // ����
      TButton(ScaledLayout1.Children.Items[I]).Opacity := 0.7;
      // �ʒu���Ƃ��Ẵ^�O�f�[�^��ݒ�
      TButton(ScaledLayout1.Children.Items[I]).Text := iNum.ToString;
      TButton(ScaledLayout1.Children.Items[I]).tag := iNum;

      iNum := iNum + 1;
    end;
    if Pos.X < (iTile * 100 - 100) then // ���̃T�C�Y�m�F
    begin
      Pos.X := Pos.X + 100; // ����Ȃ�X�񑝂₷
    end
    else
    begin // ��񂤂߂���擪�ɖ߂�A�Q���
      Pos.X := 0;
      Pos.Y := Pos.Y + 100;
    end;
  end;
end;

procedure TForm1.SetInvisibleTile;
//�S�^�C�����烉���_���ŁA�B���i�C���r�W�j�^�C�������߂āA�����i�B���j
var
  luckey: Integer;
begin

  // �ǂ̃^�C�������������I
  Randomize;
  luckey := Random(iNumOfBtn) + 1;

  // �{�^���B��
  btnInvisibleTile := FindTagBtn(luckey);
  if btnInvisibleTile is TButton then
  begin
    btnInvisibleTile.Visible := False;
    btnInvisibleTile.Enabled := False;
  end
  else
  begin
    ShowMessage('�G���[�󂫃^�C����ݒ�ł��܂���B�A�v�����ċN�����Ă�������');
  end;
end;

procedure TForm1.SetNewGame;
begin
  // �V�����Q�[���̏����ꎮ
  SetInitTilePos; // �^�C���Ȃ��
  SetInvisibleTile; // �󂫃^�C���ݒ�
  ShuffleTiles; // �^�C���V���b�t��
  FComp := False; // �I���t���O������
  GlowEffectNewGame.Enabled := False;
  // �^�C���s�����̗L��
  Tile.Enabled := True;
  btnGotoTile.Enabled := True;
  // �^�C���̃s�J�s�J�Ƃ߂�
  if FloatAnimationTileGrow.Running then
    FloatAnimationTileGrow.Stop;
  GlowEffectTile.Enabled := False;
  // �ݒ�s�����s�J�s�J�~�߂�
  if FloatAnimationGotoSetting.Running then
    FloatAnimationGotoSetting.Stop;
  GlowEffectGotoSetting.Enabled := False;

end;

procedure TForm1.SetTileRect;
begin
  // �^�C���̕\�����@Fit�i�����`�j��Client ���ݒ�
  if cbTileRect.ItemIndex = 1 then
  begin
    ScaledLayout1.Align := TAlignLayout.Fit;
    ScaledLayout1.Margins.Top := 53;
    ScaledLayout1.Height := ScaledLayout1.Width;
  end
  else
  begin
    ScaledLayout1.Align := TAlignLayout.Client;
    ScaledLayout1.Margins.Top := 5;
  end;
end;

procedure TForm1.ShuffleTiles;
//�����^�C���ʒu�̕��בւ�
var
  iLoop: Integer;
  iloopHigh: Integer;
  iWay, iRep: Integer;
  iLine: Integer;
  myPos: TmyPosition;
  tmpbtnMove: TButton;
  I: Integer;
  Flg: Boolean;
begin
  // �C���r�W�u���^�C���������_���ɓ������ă^�C�����V���b�t������]
  iloopHigh := 2000; // �C���r�W�u���^�C���𓮂�����
  iLoop := 0;
  // ���̐�
  iLine := round(sqrt(iNumOfBtn));
  Randomize;
  while iLoop < iloopHigh do
  begin
    Flg := False;
    // �����_���ɕ������߂�
    iWay := Random(4);
    // ���������ɉ��񓮂��������߂�
    iRep := Random(iLine - 1) + 1;
    for I := 0 to iRep do
    begin
      // �����̈ʒu���`�F�b�N
      myPos := GetTilePosition(btnInvisibleTile.tag);

      case iWay of
        0: // ���
          begin
            if myPos.Y > 0 then // �ŏ�i�łȂ����
            begin
              // �����̏�̃{�^����T��
              tmpbtnMove := FindTagBtn(btnInvisibleTile.tag - iLine);
              ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
              Flg := True;
            end
          end;
        1: // ����
          begin
            if myPos.Y < (iLine - 1) then // �ŉ��i�łȂ����
            begin
              // �����̉��̃{�^����T��
              tmpbtnMove := FindTagBtn(btnInvisibleTile.tag + iLine);
              ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
              Flg := True;
            end;
          end;

        2: // ����
          begin
            if myPos.X > 0 then // �ō���łȂ����
            begin
              // �����̍��̃{�^����T��
              tmpbtnMove := FindTagBtn(btnInvisibleTile.tag - 1);
              ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
              Flg := True;
            end;
          end;

        3: // �E��
          begin
            if myPos.X < (iLine - 1) then // �ŉE��łȂ����
            begin
              // �����̉E�̃{�^����T��
              tmpbtnMove := FindTagBtn(btnInvisibleTile.tag + 1);
              ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
              Flg := True;
            end;
          end;
      end;
    end;
    if Flg then
      iLoop := iLoop + 1;
  end;
end;

procedure TForm1.Switch1Switch(Sender: TObject);
//�X�C�b�`�̃I���I�t�ŃX�^�C�� �̓K�p��؂�ւ���
begin
  if Switch1.IsChecked then
  begin
    Form1.StyleBook := StyleBook1;
  end
  else
  begin
    Form1.StyleBook := nil;
  end;
end;

procedure TForm1.TrackBar1Change(Sender: TObject);
//�g���b�N�o�[�̃X���C�h�̍��킹�ă}���`�r���[�̕���ς���
begin
 MultiView1.Width := 220 + TrackBar1.Value *2;
end;

procedure TForm1.btnNewGameClick(Sender: TObject);
begin
  ///  �j���[�Q�[���{�^���������ꂽ���̏���
  SetNewGame; // �Q�[���J�n�����ꎮ�̌Ăяo��
  SetTileRect;
  //�Q�[����ʂɃX���C�h
  TabControlSetting.SetActiveTabWithTransition(Tile, TTabTransition.Slide,
    TTabTransitionDirection.Normal);
end;

procedure TForm1.btnPushed(btn: TButton);
//�{�^�����N���b�N���ꂽ�Ƃ��ɌĂ΂�鏈��
begin
  // ���{�^���̃A�j���[�V�������s�����������߂Ă��珈���J�n
  if (not FlButtonAnimation.Running) and (not FComp) then
    NextPosChk(btn);
end;

end.

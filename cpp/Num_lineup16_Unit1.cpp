// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Num_lineup16_Unit1.h"
#include "TilesVersionUnit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::NextTabAction1Update(TObject *Sender) {
	// �W�F�X�`���[�ŉE���獶�B�^�C����ʌĂяo��
	if (btnGotoTile->Enabled == True && TabControlSetting->TabIndex == 0) {
		TabControlSetting->SetActiveTabWithTransition(Tile,
			TTabTransition::Slide, TTabTransitionDirection::Normal);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::PreviousTabAction1Update(TObject *Sender) {
	// �W�F�X�`���[�ō�����E�B�ݒ��ʌĂяo��
	if (btnGotoSetting->Enabled == True && TabControlSetting->TabIndex == 1) {
		TabControlSetting->SetActiveTabWithTransition(Setting,
			TTabTransition::Slide, TTabTransitionDirection::Reversed);
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FlButtonAnimationFinish(TObject *Sender) {
	// �{�^���ړ��̃A�j���[�V����������̏���
	// �ړ���̃{�^���L�����ƁA�C���r�V�u���^�C���̈ړ�
	if (!FComp) {
		btnMoving->Enabled = True;
		// �ړ����������ł������`�F�b�N�i�C���r�W�̈ʒu�܂œ�������)
		if (btnMoving->Position->X == btnInvisibleTile->Position->X &&
			btnMoving->Position->Y == btnInvisibleTile->Position->Y) {
			// �C���r�W�^�C���̈ړ�
			int iTmpTag = btnMoving->Tag;
			btnInvisibleTile->Position->X = slpx;
			btnInvisibleTile->Position->Y = slpy;
			btnMoving->Tag = btnInvisibleTile->Tag;
			btnInvisibleTile->Tag = iTmpTag;
		}

	}
	// �R���v���[�g�`�F�b�N
	if (CheckFin() && !FComp) {
		CompleteSet();
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::MultiView1Hidden(TObject *Sender) {
	// �}���`�r���[���B���Ƃ��A�ݒ胊�X�g�����Ƃ̐ݒ�^�u�̕Ԃ�
	Setting->AddObject(lbSetting);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::MultiView1StartShowing(TObject *Sender) {
	// Multi View�������Ƃ��A�ݒ胊�X�g���}���`�r���[�ɏ悹������
	Layout1->AddObject(lbSetting);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	// �t�H�[���N���G�C�g���̏����ݒ�
	TabControlSetting->ActiveTab = Setting;
	Tile->Enabled = False;
	btnGotoTile->Enabled = False;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender) {
	// �g���b�N�o�[�̃X���C�h�̍��킹�ă}���`�r���[�̕���ς���
	MultiView1->Width = 220 + TrackBar1->Value * 2;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ListBoxGroupFooter1Click(TObject *Sender) {
	// �G���o�J�f�����S�\��
	Form3->Height = Form1->Height;
	Form3->Width = Form1->Width;
	Form3->Top = Form1->Top + 50;
	Form3->Left = Form1->Left + 50;
	Form3->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btnNewGameClick(TObject *Sender) {
	///  �j���[�Q�[���{�^���������ꂽ���̏���
	SetNewGame(); // �Q�[���J�n�����ꎮ�̌Ăяo��
	SetTileRect();
	// �Q�[����ʂɃX���C�h
	TabControlSetting->SetActiveTabWithTransition(Tile, TTabTransition::Slide,
		TTabTransitionDirection::Normal);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::cbTileRectChange(TObject *Sender) {
	// �^�C���̕\�����@�R���{���ύX���ꂽ�Ƃ��̃C�x���g
	SetTileRect();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Switch1Switch(TObject *Sender) {
	// �X�C�b�`�̃I���I�t�ŃX�^�C�� �̓K�p��؂�ւ���
	if (Switch1->IsChecked == True) {
		Form1->StyleBook = StyleBook1;
	}
	else {
		Form1->StyleBook = NULL;
	}

}

void __fastcall TForm1::btnGotoSettingClick(TObject *Sender) {
	// �ݒ��ʂւ̃{�^���������ꂽ��X���C�h
	TabControlSetting->SetActiveTabWithTransition(Setting,
		TTabTransition::Slide, TTabTransitionDirection::Reversed);
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void __fastcall TForm1::btnGotoTileClick(TObject *Sender) {
	// �^�C����ʂւ̃{�^���������ꂽ��X���C�h
	TabControlSetting->SetActiveTabWithTransition(Tile, TTabTransition::Slide,
		TTabTransitionDirection::Normal);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	// �^�C���������ꂽ�C�x���g������A�{�^�����ƂƂ��Ƀ{�^�������ꂽ��̓��ꏈ���֑���
	btnPushed(dynamic_cast<TButton*>(Sender));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::btnPushed(TButton *pbtn)
	// �{�^�����N���b�N���ꂽ�Ƃ��ɌĂ΂�鏈��
{
	// ���{�^���̃A�j���[�V�������s�����������߂Ă��珈���J�n
	if (not FlButtonAnimation->Running && !FComp) {
		NextPosChk(pbtn);
	}
}
// ---------------------------------------------------------------------------

TmyPosition __fastcall TForm1::GetTilePosition(int tag)
	// �I�u�W�F�N�g�̃^�O��񂩂�^�C���ʒu������o��
{
	TmyPosition myPos;

	myPos.X = -1;
	myPos.Y = -1;
	// �͈͊O�Ȃ� -1   �Ԃ��Ƃ�
	if (tag <= 0 || tag > iNumOfBtn) {
		return (myPos);
	}
	// ���̐�������o��
	int iCount = 1;
	int iLine = round(sqrt(iNumOfBtn));

	for (int Y = 0; Y <= (iLine - 1); Y++) {
		for (int X = 0; X <= (iLine - 1); X++) {
			if (iCount == tag) {

				myPos.X = X;
				myPos.Y = Y;
				return myPos;
			}
			iCount = iCount + 1;
		}
	}
	return myPos;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAni(TButton *pbtn, String PName, Single StpValue)
{
	// �{�^���̈ړ��̃A�j���[�V�����ݒ�
	slpx = pbtn->Position->X;
	slpy = pbtn->Position->Y; // �{�^���̈ꎞ�L��
	btnMoving = pbtn;
	pbtn->AddObject(dynamic_cast<TFmxObject*>(FlButtonAnimation));
	// �A�j���[�V�������A�^�b�`
	FlButtonAnimation->PropertyName = PName;
	FlButtonAnimation->StopValue = StpValue;
	if (SpinBox1->Value != 0) {
		FlButtonAnimation->Duration = SpinBox1->Value / 10;
	}
	else {
		FlButtonAnimation->Duration = 0.01;
	}
	pbtn->Enabled = False;
	FlButtonAnimation->Start();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::ChangeBtnPlace(TButton *btnFirst, TButton *btnSecond)
	// �����{�^���z��̂��߂̃{�^���V���b�t���p
{
	TmyPosition posTemp;

	// First�̏ꏊ���ꎞ�L��
	posTemp.X = btnFirst->Position->X;
	posTemp.Y = btnFirst->Position->Y;
	int iTag = btnFirst->Tag;

	// first��Second�̏ꏊ�Ɉړ�
	btnFirst->Position->X = btnSecond->Position->X;
	btnFirst->Position->Y = btnSecond->Position->Y;
	btnFirst->Tag = btnSecond->Tag;

	// Secound �� ��First�΂����
	btnSecond->Position->X = posTemp.X;
	btnSecond->Position->Y = posTemp.Y;
	btnSecond->Tag = iTag;
}
// ---------------------------------------------------------------------------

bool __fastcall TForm1::CheckFin()
	// �{�^���̃A�j���I����ɌĂ΂��\��́A�Q�[�������`�F�b�N
{
	// tag �̐��l�ƃ{�^���̐��l���S��������Ă�Ί����I
	for (int I = 0; I <= ScaledLayout1->Children->Count - 1; I++) {
		if (NULL != dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])) {
			if (IntToStr(dynamic_cast<TButton*>
				(ScaledLayout1->Children->Items[I])->Tag)
				!= dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Text) {
				return false;
			}
		}
	}
	return true;
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::CompleteSet() {
	// �Q�[���B������
	btnInvisibleTile->Opacity = 0; // �����Ȃ����Ă���
	btnInvisibleTile->Visible = True;
	btnInvisibleTile->SetFocus();
	btnInvisibleTile->AddObject((TFmxObject*)FlButtonAnimation); // �A�j���[�V�������A�^�b�`
	FlButtonAnimation->PropertyName = L"Opacity";
	FlButtonAnimation->StopValue = 0.9;
	FlButtonAnimation->Duration = 1; // �Ō�̃^�C���o�����v����
	FlButtonAnimation->Start();
	FComp = true;

	// NewGame�{�^���s�J�s�J������
	GlowEffectNewGame->Enabled = True;
	FloatAnimationNewGame->Start();

	// �ݒ�s���{�^���s�J�s�J������
	GlowEffectGotoSetting->Enabled = True;
	FloatAnimationGotoSetting->Start();

	// �^�C���s�J-������
	FloatAnimationTileGrow->StartValue = 0;
	GlowEffectTile->Enabled = True;
	FloatAnimationTileGrow->Start();
}

// ---------------------------------------------------------------------------

TButton* __fastcall TForm1::FindTagBtn(int tag)
	// �{�^���̎����Ă�^�O��񂩂玩���̈ʒu������o��
{
	// �������{�^���͈̔͊O��������nil
	if (tag <= 0 || tag > iNumOfBtn) {
		return (NULL);
	}
	// �X�P�[�����C�A�E�g���̎q���̐�������
	for (int I = 0; I <= ScaledLayout1->Children->Count - 1; I++) {
		if (NULL != dynamic_cast<TButton*>
			(ScaledLayout1->Children->Items[I])) // �{�^���Ȃ�
		{
			if (dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Tag == tag) {
				return (dynamic_cast<TButton*>
					(ScaledLayout1->Children->Items[I]));
			}
		}
	}
	// �����܂ł��Č�����Ȃ������玸�s
	return (NULL);
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::NextPosChk(TButton *pbtn)
	// �{�^�����N���b�N���ꂽ�Ƃ��A�C���r�W�^�C�������ɂ��邩�`�F�b�N���ē�����
{
	TmyPosition posTemp, myPos, InvPos;

	// �󂫃^�C���Ƃ̍������߂�
	myPos = GetTilePosition(pbtn->Tag);
	InvPos = GetTilePosition(btnInvisibleTile->Tag);

	posTemp.X = myPos.X - InvPos.X;
	posTemp.Y = myPos.Y - InvPos.Y;
	// X��̓��ꐫ�`�F�b�N& ���񂪗ׂ�
	if (posTemp.X == 0 && posTemp.Y >= -1 && posTemp.Y <= 1) {
		// �ׂȂ�{�^���ړ��A�j��
		ButtonAni(pbtn, "Position.Y", btnInvisibleTile->Position->Y);
	}
	// y��̓��ꐫ�`�F�b�N& ���񂪗ׂ�
	if (posTemp.Y == 0 && posTemp.X >= -1 && posTemp.X <= 1) {
		// �ׂȂ�{�^���ړ��A�j��
		ButtonAni(pbtn, "Position.X", btnInvisibleTile->Position->X);
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::SetInitTilePos() {
	// �{�^���̈ʒu�̏����ݒ�ƃ{�^���ʒu������o���₷�����邽�߂̃^�O�ݒ�


	// �������{�^�����N���A
	// �^�C�������ꂢ�ɂȂ�ׂȂ���
	iNumOfBtn = 0;

	// �{�^���̐����擾
	for (int I = 0; I <= ScaledLayout1->Children->Count - 1; I++) {
		if (NULL != dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])) {
			iNumOfBtn = iNumOfBtn + 1;
		}
	}

	// ���̐�������o��
	int iTile = round(sqrt(iNumOfBtn));

	// �{�^���̈ʒu���m�F���邽�߂̔�rPosition
	TmyPosition Pos;

	// �q������т����Ɗ�{�A�����ǂ��Ăяo��
	int iNum = 1;
	for (int I = 0; I <= ScaledLayout1->Children->Count - 1; I++) {
		// �{�^���Ȃ�
		if (NULL != dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])) {
			// �ʒu�ݒ�
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Position->X = Pos.X;
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Position->Y = Pos.Y;
			//
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Enabled = True;
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Visible = True;
			// ����
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Opacity = 0.7;
			// �ʒu���Ƃ��Ẵ^�O�f�[�^��ݒ�
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])->Text =
				IntToStr(iNum);
			dynamic_cast<TButton*>(ScaledLayout1->Children->Items[I])
				->Tag = iNum;

			iNum = iNum + 1;
		}

		if (Pos.X < (iTile * 100 - 100)) { // ���̃T�C�Y�m�F
			Pos.X = Pos.X + 100; // ����Ȃ�X�񑝂₷
		}
		else { // ��񂤂߂���擪�ɖ߂�A�Q���
			Pos.X = 0;
			Pos.Y = Pos.Y + 100;
		}
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::SetInvisibleTile()
	// �S�^�C�����烉���_���ŁA�B���i�C���r�W�j�^�C�������߂āA�����i�B���j
{
	// �ǂ̃^�C�������������I
	Randomize();
	int luckey = Random(iNumOfBtn) + 1;

	// �{�^���B��
	btnInvisibleTile = FindTagBtn(luckey);
	if (NULL != dynamic_cast<TButton*>(btnInvisibleTile)) {
		btnInvisibleTile->Visible = False;
		btnInvisibleTile->Enabled = False;
	}
	else {
		ShowMessage("�G���[�󂫃^�C����ݒ�ł��܂���B�A�v�����ċN�����Ă�������");
	}
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::SetNewGame() {
	// �V�����Q�[���̏����ꎮ
	SetInitTilePos(); // �^�C���Ȃ��
	SetInvisibleTile(); // �󂫃^�C���ݒ�
	ShuffleTiles(); // �^�C���V���b�t��
	FComp = False; // �I���t���O������
	GlowEffectNewGame->Enabled = False;
	// �^�C���s�����̗L��
	Tile->Enabled = True;
	btnGotoTile->Enabled = True;
	// �^�C���̃s�J�s�J�Ƃ߂�
	if (FloatAnimationTileGrow->Running) {
		FloatAnimationTileGrow->Stop();
	}
	GlowEffectTile->Enabled = False;
	// �ݒ�s�����s�J�s�J�~�߂�
	if (FloatAnimationGotoSetting->Running) {
		FloatAnimationGotoSetting->Stop();
	}
	GlowEffectGotoSetting->Enabled = False;

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::SetTileRect() {
	// �^�C���̕\�����@Fit�i�����`�j��Client ���ݒ�
	if (cbTileRect->ItemIndex == 1) {
		ScaledLayout1->Align = TAlignLayout::Fit;
		ScaledLayout1->Margins->Top = 53;
		ScaledLayout1->Height = ScaledLayout1->Width;
	}
	else {
		ScaledLayout1->Align = TAlignLayout::Client;
		ScaledLayout1->Margins->Top = 5;
	}
}

void __fastcall TForm1::ShuffleTiles()
	// �����^�C���ʒu�̕��בւ�{
{
	TmyPosition myPos;
	TButton* tmpbtnMove;
	bool Flg;

	// �C���r�W�u���^�C���������_���ɓ������ă^�C�����V���b�t������]
	int iloopHigh = 2000; // �C���r�W�u���^�C���𓮂�����
	int iLoop = 0;
	// ���̐�
	int iLine = round(sqrt(iNumOfBtn));
	Randomize();
	while (iLoop < iloopHigh) {
		Flg = False;
		// �����_���ɕ������߂�
		int iWay = Random(4);
		// ���������ɉ��񓮂��������߂�
		int iRep = Random(iLine - 1) + 1;
		for (int I = 0; I <= iRep; I++) {
			// �����̈ʒu���`�F�b�N
			myPos = GetTilePosition(btnInvisibleTile->Tag);

			switch (iWay) {
			case 0: // ���
				{
					if (myPos.Y > 0) // �ŏ�i�łȂ����
					{
						// �����̏�̃{�^����T��
						tmpbtnMove = FindTagBtn(btnInvisibleTile->Tag - iLine);
						ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
						Flg = True;
					}
				} break;
			case 1: // ����
				{
					if (myPos.Y < (iLine - 1)) // �ŉ��i�łȂ����
					{
						// �����̉��̃{�^����T��
						tmpbtnMove = FindTagBtn(btnInvisibleTile->Tag + iLine);
						ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
						Flg = True;
					}
				} break;
			case 2: // ����
				{
					if (myPos.X > 0) // �ō���łȂ����
					{
						// �����̍��̃{�^����T��
						tmpbtnMove = FindTagBtn(btnInvisibleTile->Tag - 1);
						ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
						Flg = True;
					}
				} break;
			case 3: // �E��
				{
					if (myPos.X < (iLine - 1)) // �ŉE��łȂ����
					{
						// �����̉E�̃{�^����T��
						tmpbtnMove = FindTagBtn(btnInvisibleTile->Tag + 1);
						ChangeBtnPlace(tmpbtnMove, btnInvisibleTile);
						Flg = True;
					}
				} break;
			}
		}
		if (Flg) {
			iLoop = iLoop + 1;
		}
	}
}

// ---------------------------------------------------------------------------

#ifndef Num_lineup16_Unit1H
#define Num_lineup16_Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ActnList.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.EditBox.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.MultiView.hpp>
#include <FMX.SpinBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <System.Actions.hpp>

// ---------------------------------------------------------------------------
struct TmyPosition {
	Single X;
	Single Y;
public:
	TmyPosition() {
		X = 0;
		Y = 0;
	}
};

class TForm1 : public TForm {
__published: // IDE �ŊǗ������R���|�[�l���g
	TTabControl *TabControlSetting;
	TTabItem *Setting;
	TToolBar *tbSetting;
	TLabel *Label2;
	TButton *btnGotoTile;
	TButton *btnMaster;
	TListBox *lbSetting;
	TListBoxGroupHeader *ListBoxGroupHeader1;
	TListBoxItem *ListBoxItem1;
	TButton *btnNewGame;
	TGlowEffect *GlowEffectNewGame;
	TFloatAnimation *FloatAnimationNewGame;
	TListBoxGroupHeader *ListBoxGroupHeader2;
	TListBoxItem *ListBoxItem3;
	TComboBox *cbTileRect;
	TListBoxItem *ListBoxItem2;
	TSpinBox *SpinBox1;
	TListBoxItem *ListBoxItem4;
	TSwitch *Switch1;
	TListBoxGroupFooter *ListBoxGroupFooter1;
	TTabItem *Tile;
	TScaledLayout *ScaledLayout1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TGlowEffect *GlowEffectTile;
	TFloatAnimation *FloatAnimationTileGrow;
	TToolBar *tbTile;
	TLabel *Label1;
	TButton *btnGotoSetting;
	TGlowEffect *GlowEffectGotoSetting;
	TFloatAnimation *FloatAnimationGotoSetting;
	TMultiView *MultiView1;
	TToolBar *ToolBar1;
	TLabel *Label3;
	TTrackBar *TrackBar1;
	TLayout *Layout1;
	TStyleBook *StyleBook1;
	TActionList *ActionList1;
	TNextTabAction *NextTabAction1;
	TPreviousTabAction *PreviousTabAction1;
	TFloatAnimation *FlButtonAnimation;
	TGestureManager *GestureManager1;

	void __fastcall NextTabAction1Update(TObject *Sender);
	void __fastcall PreviousTabAction1Update(TObject *Sender);
	void __fastcall FlButtonAnimationFinish(TObject *Sender);
	void __fastcall MultiView1Hidden(TObject *Sender);
	void __fastcall MultiView1StartShowing(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall ListBoxGroupFooter1Click(TObject *Sender);
	void __fastcall btnNewGameClick(TObject *Sender);
	void __fastcall cbTileRectChange(TObject *Sender);
	void __fastcall Switch1Switch(TObject *Sender);
	void __fastcall btnGotoTileClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnGotoSettingClick(TObject *Sender);

private: // ���[�U�[�錾

	TButton *btnMoving, *btnInvisibleTile; // �����Ă���{�^���A�����Ă���{�^�����o���Ƃ�
	int iNumOfBtn; // �^�C�������o���Ă���
	bool FComp; // �������Ă��邩�t���O
	Single slpx, slpy;

	void __fastcall SetNewGame(); // �V�K�Q�[���J�n�葱�Ăяo���̂��߂́A�ق��葱���܂Ƃ߂ČĂяo��
	void __fastcall SetInitTilePos(); // �^�C���ʒu�̏�������
	void __fastcall SetInvisibleTile(); // �B���^�C������
	void __fastcall ShuffleTiles(); // �^�C���ʒu�V���b�t��
	void __fastcall ChangeBtnPlace(TButton *btnFirst, TButton *btnSecond); // �V���b�t�����Ƀ{�^���̈ʒu����ւ��̂��߂̎葱��
	void __fastcall btnPushed(TButton *pbtn); // �^�C�����N���b�N���ꂽ����|�W�V�����`�F�b�N���Ăяo�����߂̎葱��
	void __fastcall NextPosChk(TButton *pbtn); // ���������Ȃ��^�C�����`�F�b�N
	void __fastcall ButtonAni(TButton *pbtn, String PName, Single StpValue); // �^�C���ړ��A�j���̎葱��
	void __fastcall CompleteSet(); // ���������ꍇ�̏���
	void __fastcall SetTileRect(); // �^�C���\�����@�̐؂�ւ��i�����`���t�B�b�g���j
	bool __fastcall CheckFin(); // �^�C���Ȃ�ׂ��������Ă��邩�`�F�b�N
	TButton* __fastcall FindTagBtn(int tag); // �{�^���̎����Ă���^�O��񂩂�Ώۂ̃{�^���I�u�W�F�N�g������
	TmyPosition __fastcall GetTilePosition(int tag); // �^�O��񂩂�{�^���̍��W����������

public: // ���[�U�[�錾
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif

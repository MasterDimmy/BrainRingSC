//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <AppEvnts.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TServerSocket *ServerSocket1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TStringGrid *StringGrid1;
        TStringGrid *StringGrid2;
        TButton *Button1;
        TEdit *Edit1;
        TUpDown *UpDown1;
        TApplicationEvents *ApplicationEvents1;
        TEdit *Edit2;
        TUpDown *UpDown2;
        TLabel *Label1;
        TLabel *Label2;
        TBevel *Bevel1;
        TBevel *Bevel2;
        TStatusBar *StatusBar1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit3;
        TUpDown *UpDown3;
        TButton *Button2;
        TLabel *Label5;
        TTimer *Timer1;
        TButton *Button3;
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall ApplicationEvents1Exception(TObject *Sender,
          Exception *E);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall ServerSocket1ClientConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ServerSocket1ClientWrite(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ServerSocket1ClientDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall PageControl1Change(TObject *Sender);
        void __fastcall StringGrid1Exit(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

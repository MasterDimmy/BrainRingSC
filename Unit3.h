//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TClientSocket *ClientSocket1;
        TLabel *Label1;
        TImage *Image1;
        TLabel *StaticText1;
        TLabel *Label4;
        TLabel *StaticText2;
        TBitBtn *Panel1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ClientSocket1Error(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall ClientSocket1Connect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall ClientSocket1Disconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ClientSocket1Read(TObject *Sender,
          TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

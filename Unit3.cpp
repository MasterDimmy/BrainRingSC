//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
 StaticText2->Caption="";
 StaticText1->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
 Application->Terminate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ClientSocket1Error(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
 Form3->Visible = false;
 Form2->Visible = true;
 ShowMessage("������ �� �������!");
 (int*) ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ClientSocket1Connect(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form3->Visible = true;
 Form2->Visible = false;
 Label2->Caption = Form2->Edit1->Text;
 Socket->SendText(Form2->Edit1->Text+' '+Form2->Edit2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ClientSocket1Disconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
 Form3->Visible = false;
 Form2->Visible = true;
 Panel1->Caption = "��������!";
 Panel1->Enabled = false;
 Panel1->Visible = false;
 StaticText2->Caption ="";
 StaticText1->Caption ="���";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 if (ClientSocket1->Socket->Connected)
  ClientSocket1->Socket->SendText("touch! "+Form2->Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
 AnsiString s = Socket->ReceiveText();
 AnsiString c = s.SubString(1,1);
 if (c=="q")   // ����� �������
  {
   c=s.SubString(2,s.Length()-1);
   StaticText1->Caption = c;
   Panel1->Caption = "��������! ("+c+")";
   Panel1->Enabled = true;
   Panel1->Visible = true;
  };
 if (c=="s")   // ������ ������
  {
   Panel1->Enabled = false;
   Panel1->Visible = false;
   StaticText1->Caption = "���";
  };
 if (c=="e")  // �������� ������
  {
   ClientSocket1->Active = false;
   Form3->Visible = false;
   Form2->Visible = true;
   ShowMessage("�������� ������!");
  };
 if (c=="a")  // ��� ���������
  {
   ClientSocket1->Active = false;
   Form3->Visible = false;
   Form2->Visible = true;
   ShowMessage("������������ ��� ���������!");
  };
 if (c=="y")  // ���������
  {
   Panel1->Enabled = false;
   Panel1->Visible = false;
   c=s.SubString(2,s.Length()-1);
   StaticText2->Caption= "�� �������� " +c;
  }
 if (c=="r") // �������� ��� 
 {
  Panel1->Enabled = false;
  Panel1->Visible = false;
  StaticText2->Caption ="";
  StaticText1->Caption ="���";
 }
 if (s=="who are you?")  // ��� ��
  ClientSocket1->Socket->SendText("who are you?"+Form2->Edit1->Text);
}
//---------------------------------------------------------------------------


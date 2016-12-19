//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <iostream.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int run = 0;
int users = 10;
int questions = 10;
int num;
int rec;

int user[100];
int current=0;

DATE start;
DATE me;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 int i = StrToInt(Edit1->Text)+1;
 StringGrid1->RowCount = i;
 StringGrid2->ColCount = users+1;
 users = i-1;

 StringGrid1->Cells[0][0] = "пользователь";
 StringGrid1->Cells[1][0] = "пароль";
 StringGrid1->Cells[2][0] = "состояние";
 for (int j=1;j<i;j++)
  {
   StringGrid1->Cells[0][j] = "участник"+IntToStr(j);
   StringGrid1->Cells[2][j] = "не подключен";
  };

 for (int j=1;j<=users;j++)
  StringGrid2->Cells[j][0] = "ответил "+IntToStr(j)+"-ым";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
if (!ServerSocket1->Active)
{
 int i = StrToInt(Edit1->Text)+1;
 StringGrid1->RowCount = i;
 StringGrid2->ColCount = users+1;
 users = i-1;

 StringGrid1->Cells[0][0] = "пользователь";
 StringGrid1->Cells[1][0] = "пароль";
 StringGrid1->Cells[2][0] = "состояние";
 for (int j=1;j<i;j++)
  {
   StringGrid1->Cells[0][j] = "участник"+IntToStr(j);
   StringGrid1->Cells[2][j] = "не подключен";
  };


 for (int j=1;j<=users;j++)
  StringGrid2->Cells[j][0] = "ответил "+IntToStr(j)+"-ым";
}
else
 Edit1->Text = IntToStr(users);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Exception(TObject *Sender,
      Exception *E)
{
 Edit1->Text = "10";
 Edit2->Text = "10";
 run = 0;
 Button1->Caption = "Запустить сервер";
 ShowMessage("Внимание! Произошла ошибка: "+E->Message);
 ServerSocket1->Active = false;
 StatusBar1->Panels->Items[1]->Text = "Сервер не запущен";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 for (int i=0;i<users;i++)
  StringGrid1->Cells[2][i+1] = "не подключен";

 current=0;
 Button2->Caption = "Активизировать";
 for (int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
    ServerSocket1->Socket->Connections[i]->SendText("s");

 if (run==0)
{
 run = 1;
 Button1->Caption = "Остановить сервер";

 ServerSocket1->Active = true;
 StatusBar1->Panels->Items[1]->Text = "Сервер работает. Присоединено 0 клиентов";

}
else
{
 run = 0;
 Button1->Caption = "Запустить сервер";
 ServerSocket1->Active = false;
 StatusBar1->Panels->Items[1]->Text = "Сервер не запущен";
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Change(TObject *Sender)
{
 Edit1Change(Sender);
 
 int i = StrToInt(Edit2->Text)+1;
 questions = i-1;

 StringGrid2->RowCount = i;

 StringGrid2->Cells[0][0] = "№ вопроса";

 for (int j=1;j<questions+1;j++)
  {
   StringGrid2->Cells[0][j] = "вопрос №"+IntToStr(j);
  };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
// ShowMessage(Socket->RemoteAddress);
 StatusBar1->Panels->Items[1]->Text = "Сервер работает. Присоединено "+IntToStr(ServerSocket1->Socket->ActiveConnections)+" клиентов";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
 StatusBar1->Panels->Items[1]->Text = "Сервер работает. Присоединено "+IntToStr(ServerSocket1->Socket->ActiveConnections)+" клиентов";

// ShowMessage("Read");
 AnsiString s = Socket->ReceiveText();
 AnsiString pws;
 int k = s.Pos(" ")+1;
 pws = s.SubString(k,s.Length()-k+1);
 AnsiString rs = Socket->RemoteAddress;
// ShowMessage(s);
 AnsiString c;

 int found;

 c = s.SubString(1,s.Pos(" ")-1);
 if (s.SubString(1,12)!="who are you?")
 if (s.Pos("touch!")==0)
 {found=0;
  for (int i=0;i<users;i++)
   if (c==StringGrid1->Cells[0][i+1])
    {
     if (StringGrid1->Cells[1][i+1]==pws)
      if (StringGrid1->Cells[2][i+1]=="не подключен")
       {
       StringGrid1->Cells[2][i+1] = rs;
       found=1;
       }
      else
       Socket->SendText("a");
    }
   if (found==0)
     Socket->SendText("e");
   return;  
  }

 if (s.Pos("touch!")>0)
 {
     num++;
     rec++;
     me = Now();
     TDateTime nk = (start-me);
     unsigned short a,b,c,d;
     nk.DecodeTime(&a,&b,&c,&d);
     int msec = d;
     AnsiString forsend = IntToStr(num)+"-ым за "+IntToStr(c)+":"+IntToStr(msec);

     StringGrid2->Cells[num][current] = "("+IntToStr(num)+") :"+s.SubString(8,s.Length()-7)+" за "+IntToStr(c)+":"+IntToStr(msec);

     Socket->SendText("y"+forsend);
    }
    
if (rec==ServerSocket1->Socket->ActiveConnections)
// if (CheckBox1->Checked)
 {
  for (int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
   ServerSocket1->Socket->Connections[i]->SendText("s");
   current=0;
   Button2->Caption = "Активизировать";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ServerSocket1ClientWrite(TObject *Sender,
      TCustomWinSocket *Socket)
{
// ShowMessage("Write");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
num = 0;
rec = 0;
if (run==0)
 {
  ShowMessage("Сервер не запущен");
  return;
 }
if (current==0)
{
 start = Now();
 current = StrToInt(Edit3->Text);
 Button2->Caption = "Прекратить";

 Edit3->Text = IntToStr(current+1);

 for (int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
    ServerSocket1->Socket->Connections[i]->SendText("q"+IntToStr(current));
 for (int i=0;i<users;i++)
  StringGrid2->Cells[i+1][current]="";
}
else
{
 current=0;
 Button2->Caption = "Активизировать";
 for (int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
    ServerSocket1->Socket->Connections[i]->SendText("s");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ServerSocket1ClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{

if (ServerSocket1->Socket->ActiveConnections==0)
 if (current!=0)
  Button2->Click();

for (int j=0;j<users;j++)
 if (StringGrid1->Cells[2][j+1]==Socket->RemoteAddress)
  StringGrid1->Cells[2][j+1] = "не подключен";

 StatusBar1->Panels->Items[1]->Text = "Сервер работает. Присоединено "+IntToStr(ServerSocket1->Socket->ActiveConnections)+" клиентов";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 if (ServerSocket1->Active)
 StatusBar1->Panels->Items[1]->Text = "Сервер работает. Присоединено "+IntToStr(ServerSocket1->Socket->ActiveConnections)+" клиентов";
 else StatusBar1->Panels->Items[1]->Text ="Сервер не запущен";
}
//---------------------------------------------------------------------------




void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
 StringGrid2->ColCount = users+1;
 for (int j=1;j<=users;j++)
  StringGrid2->Cells[j][0] = "ответил "+IntToStr(j)+"-ым";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1Exit(TObject *Sender)
{
 StringGrid2->ColCount = users+1;
 for (int j=1;j<=users;j++)
  StringGrid2->Cells[j][0] = "ответил "+IntToStr(j)+"-ым";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
 Edit3->Text = "1";
 
 for (int i=1;i<=questions;i++)
  for (int j=1;j<=users;j++)
   StringGrid2->Cells[j][i]="";

 for (int i=0;i<ServerSocket1->Socket->ActiveConnections;i++)
    ServerSocket1->Socket->Connections[i]->SendText("renew");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 ServerSocket1->Active = true;
 AnsiString s = ServerSocket1->Socket->LocalHost+"\n"+IntToStr(ServerSocket1->Socket->LocalPort);
 freopen("scrci.ini","wt",stdout);
 printf(s.c_str());
 fclose(stdout);
 ServerSocket1->Active = false;
}
//---------------------------------------------------------------------------


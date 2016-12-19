//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>

#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button1Click(TObject *Sender)
{
 char s[20];
 int port;

 freopen("scrci.ini","rt",stdin);
 scanf("%20s %d",s,&port);
 fclose(stdin);

 AnsiString host = s;


 Form3->ClientSocket1->Host = host;
 Form3->ClientSocket1->Port = port;
 Form3->ClientSocket1->Active = true;
}
//---------------------------------------------------------------------------

object Form1: TForm1
  Left = 330
  Top = 203
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Brain - '#1088#1080#1085#1075'. '#1057#1077#1088#1074#1077#1088'.'
  ClientHeight = 490
  ClientWidth = 536
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000044444440000000000000000000000
    0044000004400444444440000000000000400000004440000000440000000000
    0004444440040000000004400000000000000000000400000000004000000000
    0000000000040000000000400000000000000000000400000000004000000000
    0000000000040000000000400000000000000000000400000000004000000000
    0044400000040000000000400000000004000000000400000000004000000000
    4000000000040000000000400000000400000000000400000000004000000004
    0000000000040000000000400000000400000000000440000000004000000004
    0000000000004000000000400000000400000000000040000000004000000000
    4000000000004000000004000000000040000000000040000000040000000000
    0400000000004000000040000000000000400000000040000044000000000000
    0004400000000000040000000000000000000044444444444000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE03FFFFFCF9807FFDFC7F3FFE06
    FF9FFFFEFFDFFFFEFFDFFFFEFFDFFFFEFFDFFFFEFFDFFC7EFFDFFBFEFFDFF7FE
    FFDFEFFEFFDFEFFEFFDFEFFE7FDFEFFF7FDFEFFF7FDFF7FF7FBFF7FF7FBFFBFF
    7F7FFDFF7CFFFE7FFBFFFFC007FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 503
    Top = 451
    Width = 21
    Height = 13
    Caption = 'v1.1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object PageControl1: TPageControl
    Left = 10
    Top = 7
    Width = 497
    Height = 423
    ActivePage = TabSheet1
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
      object Label1: TLabel
        Left = 105
        Top = 34
        Width = 121
        Height = 13
        Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081' ('#1076#1086' 100)'
      end
      object Bevel1: TBevel
        Left = 14
        Top = 11
        Width = 459
        Height = 371
      end
      object StringGrid1: TStringGrid
        Left = 72
        Top = 67
        Width = 337
        Height = 295
        ColCount = 3
        DefaultColWidth = 100
        FixedCols = 0
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        ScrollBars = ssVertical
        TabOrder = 0
        OnExit = StringGrid1Exit
      end
      object Edit1: TEdit
        Left = 248
        Top = 29
        Width = 89
        Height = 21
        TabOrder = 1
        Text = '10'
        OnChange = Edit1Change
      end
      object UpDown1: TUpDown
        Left = 337
        Top = 29
        Width = 16
        Height = 21
        Associate = Edit1
        Min = 1
        Position = 10
        TabOrder = 2
        Wrap = False
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1042#1086#1087#1088#1086#1089' / '#1054#1090#1074#1077#1090
      ImageIndex = 1
      object Label2: TLabel
        Left = 119
        Top = 20
        Width = 91
        Height = 13
        Caption = #1042#1086#1087#1088#1086#1089#1086#1074' ('#1076#1086' 100)'
      end
      object Bevel2: TBevel
        Left = 10
        Top = 12
        Width = 464
        Height = 365
      end
      object Label3: TLabel
        Left = 217
        Top = 45
        Width = 41
        Height = 13
        Caption = #1054#1090#1074#1077#1090#1099':'
      end
      object Label4: TLabel
        Left = 144
        Top = 344
        Width = 87
        Height = 13
        Caption = #1058#1077#1082#1091#1097#1080#1081' '#1074#1086#1087#1088#1086#1089':'
      end
      object StringGrid2: TStringGrid
        Left = 24
        Top = 62
        Width = 432
        Height = 260
        DefaultColWidth = 125
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
        RowHeights = (
          24
          24
          24
          24
          24)
      end
      object Edit2: TEdit
        Left = 241
        Top = 18
        Width = 76
        Height = 21
        TabOrder = 1
        Text = '10'
        OnChange = Edit2Change
      end
      object UpDown2: TUpDown
        Left = 317
        Top = 18
        Width = 16
        Height = 21
        Associate = Edit2
        Min = 1
        Position = 10
        TabOrder = 2
        Wrap = False
      end
      object Edit3: TEdit
        Left = 241
        Top = 338
        Width = 74
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '1'
      end
      object UpDown3: TUpDown
        Left = 315
        Top = 338
        Width = 16
        Height = 24
        Associate = Edit3
        Min = 1
        Position = 1
        TabOrder = 4
        Wrap = False
      end
      object Button2: TButton
        Left = 342
        Top = 335
        Width = 110
        Height = 29
        Caption = #1040#1082#1090#1080#1074#1080#1079#1080#1088#1086#1074#1072#1090#1100
        TabOrder = 5
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 33
        Top = 336
        Width = 101
        Height = 28
        Caption = #1053#1072#1095#1072#1090#1100' '#1079#1072#1085#1086#1074#1086
        TabOrder = 6
        OnClick = Button3Click
      end
    end
  end
  object Button1: TButton
    Left = 181
    Top = 438
    Width = 167
    Height = 27
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100' '#1089#1077#1088#1074#1077#1088
    TabOrder = 1
    OnClick = Button1Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 471
    Width = 536
    Height = 19
    Panels = <
      item
        Text = #1057#1090#1072#1090#1091#1089':'
        Width = 50
      end
      item
        Alignment = taCenter
        Text = #1057#1077#1088#1074#1077#1088' '#1085#1077' '#1079#1072#1087#1091#1097#1077#1085
        Width = 340
      end
      item
        Text = 'StavSU RCI Dimmy '#169' 2005'
        Width = 50
      end>
    SimplePanel = False
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 7979
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientWrite = ServerSocket1ClientWrite
    Left = 472
    Top = 53
  end
  object ApplicationEvents1: TApplicationEvents
    OnException = ApplicationEvents1Exception
    Left = 372
    Top = 54
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 472
    Top = 110
  end
end

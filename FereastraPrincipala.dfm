object mForm: TmForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = '0'
  ClientHeight = 726
  ClientWidth = 1064
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object btnZAR: TButton
    Left = 862
    Top = 128
    Width = 75
    Height = 25
    Caption = 'ZAR'
    TabOrder = 0
    OnClick = btnZARClick
  end
  object Text1: TStaticText
    Left = 862
    Top = 159
    Width = 67
    Height = 17
    Caption = 'First_number'
    TabOrder = 1
  end
  object Text2: TStaticText
    Left = 862
    Top = 182
    Width = 81
    Height = 17
    Caption = 'Second_number'
    TabOrder = 2
  end
  object AlegeZar1: TButton
    Left = 862
    Top = 205
    Width = 75
    Height = 25
    Caption = 'AlegeZar1'
    TabOrder = 3
    OnClick = AlegeZar1Click
  end
  object AlegeZar2: TButton
    Left = 862
    Top = 236
    Width = 75
    Height = 25
    Caption = 'AlegeZar2'
    TabOrder = 4
    OnClick = AlegeZar2Click
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 2000
    ServerType = stNonBlocking
    OnClientRead = ServerSocket1ClientRead
    Left = 56
    Top = 112
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 2000
    OnRead = ClientSocket1Read
    Left = 56
    Top = 192
  end
end

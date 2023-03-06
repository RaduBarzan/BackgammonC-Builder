object ServerForm: TServerForm
  Left = 0
  Top = 0
  Caption = 'ServerForm'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 144
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Yes'
    ModalResult = 6
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 392
    Top = 176
    Width = 75
    Height = 25
    Caption = 'No'
    ModalResult = 7
    TabOrder = 1
    OnClick = Button2Click
  end
  object StaticText1: TStaticText
    Left = 232
    Top = 104
    Width = 144
    Height = 17
    Caption = 'Do you want to be the host ?'
    TabOrder = 2
  end
end

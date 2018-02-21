object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Constru'#231#227'o EixoXYZ'
  ClientHeight = 154
  ClientWidth = 465
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 257
    Top = 59
    Width = 63
    Height = 13
    Caption = 'Pxyz{0,0,0};'
  end
  object Label2: TLabel
    Left = 257
    Top = 86
    Width = 64
    Height = 13
    Caption = 'Pxyx{0,0,0};'
    Transparent = False
  end
  object Label3: TLabel
    Left = 32
    Top = 29
    Width = 29
    Height = 13
    Caption = 'Eixo X'
  end
  object Label4: TLabel
    Left = 32
    Top = 54
    Width = 29
    Height = 13
    Caption = 'Eixo Y'
  end
  object Label5: TLabel
    Left = 32
    Top = 81
    Width = 29
    Height = 13
    Caption = 'Eixo Z'
  end
  object Edit1: TEdit
    Left = 88
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '0,0'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 88
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 1
    Text = '0,0'
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 88
    Top = 78
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '0,0'
    OnKeyPress = Edit3KeyPress
  end
  object Button1: TButton
    Left = 257
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Ponto XYZ'
    TabOrder = 3
    OnClick = Button1Click
  end
end

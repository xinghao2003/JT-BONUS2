object Form2: TForm2
  Left = 0
  Top = 0
  Width = 650
  Height = 493
  AutoScroll = True
  AutoSize = True
  BorderWidth = 10
  Caption = 'Knight Tour'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Label1: TLabel
    Left = 10
    Top = 11
    Width = 21
    Height = 15
    Caption = 'n = '
  end
  object Label2: TLabel
    Left = 9
    Top = 64
    Width = 128
    Height = 15
    Caption = '(x, y) = (             ,             )'
  end
  object Label3: TLabel
    Left = 0
    Top = 40
    Width = 87
    Height = 15
    Caption = 'Starting Position'
  end
  object Label4: TLabel
    Left = 8
    Top = 187
    Width = 51
    Height = 15
    Caption = 'Grid Size: '
  end
  object Label5: TLabel
    Left = 1
    Top = 323
    Width = 100
    Height = 15
    Alignment = taCenter
    Caption = 'r, g, b, graduation: '
  end
  object PageControl1: TPageControl
    Left = 156
    Top = 0
    Width = 456
    Height = 426
    ActivePage = tsMemo
    TabOrder = 0
    object tsMemo: TTabSheet
      Caption = 'Tour in Memo'
      object memo: TMemo
        Left = 3
        Top = 3
        Width = 442
        Height = 390
        Lines.Strings = (
          'memo')
        TabOrder = 0
        WordWrap = False
      end
    end
    object tsStringGrid: TTabSheet
      Caption = 'Tour in StringGrid'
      ImageIndex = 1
      object sgMatrix: TStringGrid
        Left = 3
        Top = 3
        Width = 442
        Height = 390
        DefaultColWidth = 32
        DefaultRowHeight = 32
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
      end
    end
    object tsAnimation: TTabSheet
      Caption = 'Tour in Animation'
      ImageIndex = 2
      object sgAnimation: TStringGrid
        Left = 3
        Top = 3
        Width = 442
        Height = 390
        DefaultColWidth = 32
        DefaultRowHeight = 32
        FixedCols = 0
        FixedRows = 0
        TabOrder = 0
        OnDrawCell = sgAnimationDrawCell
      end
    end
  end
  object cbRandomPosition: TCheckBox
    Left = 0
    Top = 90
    Width = 150
    Height = 17
    Caption = 'Random Position'
    TabOrder = 1
    OnClick = cbRandomPositionClick
  end
  object cbTrace: TCheckBox
    Left = 0
    Top = 153
    Width = 97
    Height = 17
    Caption = 'Trace'
    TabOrder = 2
    OnClick = cbTraceClick
  end
  object cbRandomColor: TCheckBox
    Left = 1
    Top = 385
    Width = 102
    Height = 17
    Caption = 'Random Color'
    TabOrder = 3
    OnClick = cbRandomColorClick
  end
  object editMatrixSize: TEdit
    Left = 37
    Top = 8
    Width = 50
    Height = 23
    NumbersOnly = True
    TabOrder = 4
    Text = '5'
    OnChange = editMatrixSizeChange
  end
  object editStartingX: TEdit
    Left = 57
    Top = 61
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 5
    Text = '1'
    OnChange = editStartingXChange
  end
  object editStartingY: TEdit
    Left = 93
    Top = 61
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 6
    Text = '1'
    OnChange = editStartingYChange
  end
  object editGridSize: TEdit
    Left = 65
    Top = 184
    Width = 72
    Height = 23
    NumbersOnly = True
    TabOrder = 7
    Text = '32'
    OnChange = editGridSizeChange
  end
  object editColorR: TEdit
    Left = 1
    Top = 352
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 8
    Text = '0'
    OnChange = editColorRChange
  end
  object editColorG: TEdit
    Left = 37
    Top = 352
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 9
    Text = '255'
    OnChange = editColorGChange
  end
  object editColorB: TEdit
    Left = 73
    Top = 352
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 10
    Text = '0'
    OnChange = editColorBChange
  end
  object editColorGraduation: TEdit
    Left = 120
    Top = 352
    Width = 30
    Height = 23
    NumbersOnly = True
    TabOrder = 11
    Text = '5'
    OnChange = editColorGraduationChange
  end
  object btnKnightTour: TButton
    Left = 0
    Top = 122
    Width = 150
    Height = 25
    Caption = 'Knight Tour'
    TabOrder = 12
    OnClick = btnKnightTourClick
  end
  object btnKnightTourAnimation: TButton
    Left = 0
    Top = 233
    Width = 150
    Height = 25
    Caption = 'Knight Tour Animation'
    TabOrder = 13
    OnClick = btnKnightTourAnimationClick
  end
  object tbAnimationSpeed: TTrackBar
    Left = 0
    Top = 264
    Width = 150
    Height = 45
    Max = 25
    Min = 1
    Position = 10
    TabOrder = 14
    OnChange = tbAnimationSpeedChange
  end
  object Timer1: TTimer
    Left = 104
    Top = 400
  end
end

//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>  // For std::rand and std::srand
#include <ctime>    // For std::time
#include <chrono>
#include <thread>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tsMemo;
	TTabSheet *tsStringGrid;
	TTabSheet *tsAnimation;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TCheckBox *cbRandomPosition;
	TCheckBox *cbTrace;
	TCheckBox *cbRandomColor;
	TEdit *editMatrixSize;
	TEdit *editStartingX;
	TEdit *editStartingY;
	TEdit *editGridSize;
	TEdit *editColorR;
	TEdit *editColorG;
	TEdit *editColorB;
	TEdit *editColorGraduation;
	TButton *btnKnightTour;
	TButton *btnKnightTourAnimation;
	TTrackBar *tbAnimationSpeed;
	TMemo *memo;
	TStringGrid *sgMatrix;
	TStringGrid *sgAnimation;
	TTimer *Timer1;
	void __fastcall editGridSizeChange(TObject *Sender);
	void __fastcall cbRandomPositionClick(TObject *Sender);
	void __fastcall cbTraceClick(TObject *Sender);
	void __fastcall cbRandomColorClick(TObject *Sender);
	void __fastcall editColorRChange(TObject *Sender);
	void __fastcall editColorGChange(TObject *Sender);
	void __fastcall editColorBChange(TObject *Sender);
	void __fastcall editColorGraduationChange(TObject *Sender);
	void __fastcall editStartingXChange(TObject *Sender);
	void __fastcall editStartingYChange(TObject *Sender);
	void __fastcall editMatrixSizeChange(TObject *Sender);
	void __fastcall tbAnimationSpeedChange(TObject *Sender);
	void __fastcall btnKnightTourClick(TObject *Sender);
	void __fastcall btnKnightTourAnimationClick(TObject *Sender);
	void __fastcall sgAnimationDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
private:	// User declarations
	void __fastcall displayToMemo(std::vector<std::vector<int>> &visited);
	void __fastcall displayToStringGrid(std::vector<std::vector<int>> &visited);
	void __fastcall animate(std::vector<std::vector<int>> &visited);
    bool __fastcall isValid(int x, int y, int n, std::vector<std::vector<int>> &visited);
	int __fastcall countValidMoves(int x, int y, int n, std::vector<std::vector<int>> &visited);
	bool __fastcall findKnightTour(int x, int y, int movei, int n,
					std::vector<std::vector<int>> &visited);
    void __fastcall knightTour();
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

bool randomPos = false;
bool trace = false;
bool randomColor = false;
bool animation = false;
int r = 0;
int g = 255;
int b = 0;
int graduation = 5;
int size = 5;
int startX = 1;
int startY = 1;                                                    
float delay = 0.5;    // seconds
bool resultGenerated = false;
bool result = false;
// The 8 possible movements for a knight
int row[] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};
void __fastcall TForm2::displayToMemo(std::vector<std::vector<int>> &visited) {
	String line;

	for (int i = 0; i < visited.size(); i++) {
        line = ""; // Start a new line for each row
        for (int j = 0; j < visited[i].size(); j++) {
            line += IntToStr(visited[i][j]) + "\t"; // Convert each element to String and add a tab for spacing
        }
		memo->Lines->Add(line); // Add the constructed line to the memo
	}

	if (trace) {
        memo->Lines->Add("");
	}

	if (resultGenerated) {
		line = "(x, y) = (" + IntToStr(startX) + ", " + IntToStr(startY) + ") ";
		line += result ? "O" : "X";
		memo->Lines->Add(line); // Add the result and starting position
		memo->Lines->Add("");

		line = "";
		for (int i = 0; i < size; i++) {
			line += "----------";
		}
		memo->Lines->Add(line);
	}
}
void __fastcall TForm2::displayToStringGrid(std::vector<std::vector<int>> &visited) {
	// Set up the grid
	sgMatrix->RowCount = size;
	sgMatrix->ColCount = size;

	// Fill the grid with data from the visited matrix
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[i].size(); j++) {
			sgMatrix->Cells[j][i] = IntToStr(visited[i][j]);
		}
	}
	sgMatrix->Repaint();
}

void __fastcall TForm2::animate(std::vector<std::vector<int>> &visited) {
	// Set up the grid
	sgAnimation->RowCount = size;
	sgAnimation->ColCount = size;

	// Fill the grid with data from the visited matrix
	for (int i = 0; i < visited.size(); i++) {
		for (int j = 0; j < visited[i].size(); j++) {
			sgAnimation->Cells[j][i] = IntToStr(visited[i][j]);
		}
	}

	sgAnimation->Repaint();
}
// Check if (x, y) is a valid move
bool __fastcall TForm2::isValid(int x, int y, int n, std::vector<std::vector<int>> &visited) {
  return (x >= 0 && y >= 0 && x < n && y < n && visited[x][y] == 0);
}
// Count the number of valid moves from (x, y)
int __fastcall TForm2::countValidMoves(int x, int y, int n, std::vector<std::vector<int>> &visited) {
  int count = 0;
  for (int i = 0; i < 8; i++) {
	if (isValid(x + row[i], y + col[i], n, visited)) {
      count++;
    }
  }
  return count;
}
// Utility function to find the knight's tour using Warnsdorff's heuristic
// todo: animate the knight's tour
bool __fastcall TForm2::findKnightTour(int x, int y, int movei, int n,
					std::vector<std::vector<int>> &visited) {
  // If all squares are visited, return true
  if (movei > n * n)
	return true;
  // Try all next moves from the current coordinate x, y
  std::vector<std::pair<int, int>> moves;
  for (int i = 0; i < 8; i++) {
    int x_next = x + row[i];
	int y_next = y + col[i];
    if (isValid(x_next, y_next, n, visited)) {
	  moves.push_back({countValidMoves(x_next, y_next, n, visited), i});
    }
  }
  // Sort moves based on the number of onward moves
  sort(moves.begin(), moves.end());
  for (auto &move : moves) {
    int x_next = x + row[move.second];
    int y_next = y + col[move.second];
	visited[x_next][y_next] = movei;
	if (trace) {
	  displayToMemo(visited);
	}
	if (animation) {
	  Sleep(delay * 1000);
	  animate(visited);
	}
	if (findKnightTour(x_next, y_next, movei + 1, n, visited))
      return true;
	visited[x_next][y_next] = 0; // backtrack
  }
  return false;
}

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
    memo->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editGridSizeChange(TObject *Sender)
{
	if (editGridSize->Text == "") {
		editGridSize->Text = "0";
	}
	sgMatrix->DefaultColWidth = StrToInt(editGridSize->Text);
	sgMatrix->DefaultRowHeight = StrToInt(editGridSize->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::cbRandomPositionClick(TObject *Sender)
{
	randomPos = cbRandomPosition->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cbTraceClick(TObject *Sender)
{
	trace = cbTrace->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::cbRandomColorClick(TObject *Sender)
{
	randomColor = cbRandomColor->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::editColorRChange(TObject *Sender)
{
	if (editColorR->Text == "") {
		editColorR->Text = "0";
	}
	r = StrToInt(editColorR->Text);
	if (r > 255) {
		editColorR->Text = "255";
		r = 255;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editColorGChange(TObject *Sender)
{
	if (editColorG->Text == "") {
		editColorG->Text = "0";
	}
	g = StrToInt(editColorG->Text);
	if (g > 255) {
		editColorG->Text = "255";
		g = 255;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editColorBChange(TObject *Sender)
{
	if (editColorB->Text == "") {
		editColorB->Text = "0";
	}
	b = StrToInt(editColorB->Text);
	if (b > 255) {
		editColorB->Text = "255";
		b = 255;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editColorGraduationChange(TObject *Sender)
{
	if (editColorGraduation->Text == "") {
		editColorGraduation->Text = "0";
	}
	graduation = StrToInt(editColorGraduation->Text);
	if (graduation > 100) {
		editColorGraduation->Text = "100";
		graduation = 100;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::editMatrixSizeChange(TObject *Sender)
{
	if (editMatrixSize->Text == "") {
		editMatrixSize->Text = "0";
	}
	size = StrToInt(editMatrixSize->Text);
	if (startX >= size) {
		startX = size - 1;
		editStartingX->Text = IntToStr(startX);
	}
	if (startY >= size) {
		startY = size - 1;
		editStartingY->Text = IntToStr(startY);
	}
	sgMatrix->RowCount = size;
	sgMatrix->ColCount = size;
	sgAnimation->RowCount = size;
    sgAnimation->ColCount = size;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editStartingXChange(TObject *Sender)
{
	if (editStartingX->Text == "") {
		editStartingX->Text = "0";
	}
	startX = StrToInt(editStartingX->Text);
	if (startX >= size) {
		startX = size - 1;
		editStartingX->Text = IntToStr(startX);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::editStartingYChange(TObject *Sender)
{
	if (editStartingY->Text == "") {
		editStartingY->Text = "0";
	}
	startY = StrToInt(editStartingY->Text);
	if (startY >= size) {
		startY = size - 1;
		editStartingY->Text = IntToStr(startY);
	}
}
//--------------------------------------------------------------------------

void __fastcall TForm2::tbAnimationSpeedChange(TObject *Sender)
{
	float value = tbAnimationSpeed->Position;
	delay = 1 / value * 5;
	Timer1->Interval = delay * 1000;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::knightTour() {
	std::vector<std::vector<int>> visited(size, std::vector<int>(size, 0));
	resultGenerated = false;

	if(randomPos) {
		std::srand(std::time(0));
		startX = std::rand() % (size);
		editStartingX->Text = IntToStr(startX);
		startY = std::rand() % (size);
		editStartingY->Text = IntToStr(startY);
	}

	visited[startX][startY] = 1;

	if (trace) {
		displayToMemo(visited);
	}

	result = findKnightTour(startX, startY, 2, size, visited);
	resultGenerated = true;

	displayToMemo(visited);
	displayToStringGrid(visited);

	if (animation) {
		animate(visited);
	}
}

void __fastcall TForm2::btnKnightTourClick(TObject *Sender)
{
    knightTour();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnKnightTourAnimationClick(TObject *Sender)
{
	animation = true;

	if(randomColor) {
		std::srand(std::time(0));
		r = std::rand() % (256);
		editColorR->Text = IntToStr(r);
		g = std::rand() % (256);
		editColorG->Text = IntToStr(g);
		b = std::rand() % (256);
		editColorB->Text = IntToStr(b);
	}

	knightTour();

    animation = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::sgAnimationDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	TStringGrid *grid = dynamic_cast<TStringGrid*>(Sender);
	if (grid->Cells[ACol][ARow] == "") {
		return;
	}
	if (grid->Cells[ACol][ARow] == "0") {
		return;
	}
	if (grid != NULL) {
		// Default color
		grid->Canvas->Font->Color = clBlack;
		grid->Canvas->Brush->Color = clWhite;

		// Assume moveNumber is fetched correctly from the grid
		int moveNumber = StrToInt(grid->Cells[ACol][ARow]);

		// Calculate the final color based on move number
		int colorR = std::max(0, r - (moveNumber * graduation));
		int colorG = std::max(0, g - (moveNumber * graduation));
		int colorB = std::max(0, b - (moveNumber * graduation));       

		TColor color = (TColor) RGB(colorR, colorG, colorB);
		grid->Canvas->Brush->Color = color;

		// Fill cell and draw text
		grid->Canvas->FillRect(Rect);
		grid->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2, grid->Cells[ACol][ARow]);
	}
}
//----------------------------------------------------------------------------

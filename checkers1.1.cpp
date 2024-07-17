#include <iostream>
#include<Windows.h>
#include<string>
#include<cmath>
#include<math.h> 
#define step(x,x0,y,y0) sqrt(pow((x - x0),2) + pow((y - y0),2))
using namespace std;
int bQueen = 66;
int wQueen = 87;
int white = 119;
int black = 98;
bool player = true ; // true(1) - white , false(0) - black
int wCapturedCheckers = 0;
int bCapturedCheckers = 0;
bool attackPawn = false; //false - ирок не атакует , true - игрк хочет сделать атаку

struct Checkers {
	char stateOfTheCell = 46;
	char queen;           // false - шашка не является дамкой , true - шашка является дамкой
	bool absence = false; // false - в клетке нет шашки , true - в клетке есть шашка
	Checkers() {}
	Checkers(char stateOfTheCell, char queen, bool absence) :stateOfTheCell(stateOfTheCell), queen(queen), absence(absence) {}
};
void initialization(Checkers**& arr, int row, int column) {
	int var = 2;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (var % 2 == 0 && (i == 0 || i == 1 || i == 2)) {
				arr[i][j].stateOfTheCell = black;
				arr[i][j].absence = true;
			}
			else if (var % 2 == 0 && (i == 6 || i == 7 || i == 5)) {
				arr[i][j].stateOfTheCell = white;
				arr[i][j].absence = true;
			}
			var += 1;
		}
		var -= 1;
	}
}
void show(Checkers** arr, int row, int column) {
	char count = 97;
	for (int i = 0; i < row; i++)
	{
		cout << count++ << " |";
		for (int j = 0; j < column; j++)
		{
			cout << ' ' << arr[i][j].stateOfTheCell << ' ' << '|';
		}
		cout << endl << "-----------------------------------" << endl;
	}
	cout << "    " << 1 << " | " << 2 << " | " << 3 << " | " << 4 << " | " << 5 << " | " << 6 << " | " << 7 << " | " << 8 << " | ";
	cout << "\n\n";
}
void rules() {
	cout << "1.Простые шашки ходят только вперёд" << endl;
	cout << "2.но может бить назад, дамка может ходить на любое число полей" << endl;
	cout << "3.цель игры - съесть или запереть все шашки противника" << endl;
	cout << "4.бить можно произвольное количество шашек в любых направлениях" << endl;
	cout << "5.дамка может ходить по диагонали в любую клетку" << endl;


}
void queen(Checkers** &arr, int size) {

	if (player ==true)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[0][i].stateOfTheCell == white) {
				arr[0][i].stateOfTheCell = wQueen;
				arr[0][i].queen = true;
			}
		}
	}
	else if (player == false)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[7][i].stateOfTheCell == black){
				arr[7][i].stateOfTheCell = bQueen;
				arr[7][i].queen = true;
			}
		}
	}
}
int gameRowToInt(char gameRow) {
	if (gameRow == 97) return 0;
	else if (gameRow == 98) return 1;
	else if (gameRow == 99) return 2;
	else if (gameRow == 100) return 3;
	else if (gameRow == 101) return 4;
	else if (gameRow == 102) return 5;
	else if (gameRow == 103) return 6;
	else if (gameRow == 104) return 7;

}
void changeTheQueen(Checkers** &arr, char gameRow, int gameColumn, char nowRow, int nowColumn) {
	if (player == true){
		arr[gameRowToInt(nowRow)][nowColumn - 1].queen = false;
		arr[gameRowToInt(gameRow)][gameColumn - 1].queen = true;
		arr[gameRowToInt(gameRow)][gameColumn - 1].stateOfTheCell == wQueen;
	}
	else if (player == false) {
		arr[gameRowToInt(nowRow)][nowColumn - 1].queen = false;
		arr[gameRowToInt(gameRow)][gameColumn - 1].queen = true;
		arr[gameRowToInt(gameRow)][gameColumn - 1].stateOfTheCell == bQueen;

	}
 }
void needForAnAttack(Checkers** arr, int row, int column) {
	if (player == true)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (i == 0 || i == 1) {
					if (arr[i + 1][j - 1].stateOfTheCell == black && arr[i + 2][j - 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					if (arr[i + 1][j + 1].stateOfTheCell == black && arr[i + 2][j + 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
				}
				else if (i == 7 || i == 6) {
					if (arr[i - 1][j + 1].stateOfTheCell == black && arr[i - 2][j + 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j - 1].stateOfTheCell == black && arr[i - 2][j - 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}

				}
				else {
					if (arr[i + 1][j - 1].stateOfTheCell == black && arr[i + 2][j - 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j - 1].stateOfTheCell == black && arr[i - 2][j - 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i + 1][j + 1].stateOfTheCell == black && arr[i + 2][j + 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j + 1].stateOfTheCell == black && arr[i - 2][j + 2].absence == false && arr[i][j].stateOfTheCell == white) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
				}


			}



		}
	}
	else if (player == false)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (i == 0 || i == 1) {
					if (arr[i + 1][j - 1].stateOfTheCell == white && arr[i + 2][j - 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i + 1][j + 1].stateOfTheCell == white && arr[i + 2][j + 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
				}
				else if (i == 7 || i == 6) {

					if (arr[i - 1][j - 1].stateOfTheCell == white && arr[i - 2][j - 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j + 1].stateOfTheCell == white && arr[i - 2][j + 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
				}
				else {
					if (arr[i + 1][j - 1].stateOfTheCell == white && arr[i + 2][j - 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j - 1].stateOfTheCell == white && arr[i - 2][j - 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i + 1][j + 1].stateOfTheCell == white && arr[i + 2][j + 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
					else if (arr[i - 1][j + 1].stateOfTheCell == white && arr[i - 2][j + 2].absence == false && arr[i][j].stateOfTheCell == black) {
						cout << "необходимо съeсть шашку для того чтобы продолжить игру" << endl;
						attackPawn = true;
					}
				
				}
			}
		}

	}
}
int canAPqwnWalkQueen(Checkers** arr, char gameRow, int gameColumn, char nowRow, int nowColumn) {
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false  && (gameRow - nowRow == 1 || gameRow - nowRow == -1) && (gameColumn - nowColumn == 1 || gameColumn - nowColumn == -1))return 1;
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2))return 1;
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false && (gameRow - nowRow == 3 || gameRow - nowRow == -3) && (gameColumn - nowColumn == 3 || gameColumn - nowColumn == -3))return 1;
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false && (gameRow - nowRow == 4 || gameRow - nowRow == -4) && (gameColumn - nowColumn == 4 || gameColumn - nowColumn == -4))return 1;
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false  && (gameRow - nowRow == 5 || gameRow - nowRow == -5) && (gameColumn - nowColumn == 5 || gameColumn - nowColumn == -5))return 1;
	if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false && (gameRow - nowRow == 6 || gameRow - nowRow == -6) && (gameColumn - nowColumn == 6 || gameColumn - nowColumn == -6))return 1;
	else return 0;
}
void canAMoveBeAnAttackQueen(Checkers** &arr, char gameRow, int gameColumn, char nowRow, int nowColumn) {
	if (player == true)
	{
		if (gameRow<nowRow && gameColumn>nowColumn) {
			if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 1][gameColumn - 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 2][gameColumn - 3].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 2][gameColumn - 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 2][gameColumn - 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 3][gameColumn - 4].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 3][gameColumn - 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 3][gameColumn - 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 4][gameColumn - 5].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 4][gameColumn - 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 4][gameColumn - 5].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 5][gameColumn - 6].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 5][gameColumn - 6].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 5][gameColumn - 6].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 6][gameColumn - 7].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 6][gameColumn - 7].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 6][gameColumn - 7].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow < nowRow && gameColumn < nowColumn)
		{
			if (arr[gameRowToInt(gameRow) + 1][gameColumn ].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 1][gameColumn ].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 1][gameColumn ].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 2][gameColumn + 1].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 2][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 2][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 3][gameColumn + 2].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 3][gameColumn + 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 3][gameColumn + 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 4][gameColumn + 3].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 4][gameColumn + 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 4][gameColumn + 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 5][gameColumn + 4].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 5][gameColumn + 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 5][gameColumn + 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 6][gameColumn + 5].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) + 6][gameColumn + 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 6][gameColumn + 5].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow > nowRow && gameColumn < nowColumn)
		{
			if (arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 1][gameColumn].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 2][gameColumn + 1].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 2][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 2][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 3][gameColumn + 2].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 3][gameColumn + 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 3][gameColumn + 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 4][gameColumn + 3].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 4][gameColumn + 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 4][gameColumn + 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 5][gameColumn + 4].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 5][gameColumn + 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 5][gameColumn + 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 6][gameColumn + 5].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 6][gameColumn + 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 6][gameColumn + 5].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow > nowRow && gameColumn > nowColumn)
		{
			if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 1][gameColumn - 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 2][gameColumn - 3].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 2][gameColumn - 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 2][gameColumn - 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 3][gameColumn - 4].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 3][gameColumn - 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 3][gameColumn - 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 4][gameColumn - 5].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 4][gameColumn - 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 4][gameColumn - 5].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 5][gameColumn - 6].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 5][gameColumn - 6].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 5][gameColumn - 6].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 6][gameColumn - 7].stateOfTheCell == black)
			{
				arr[gameRowToInt(gameRow) - 6][gameColumn - 7].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 6][gameColumn - 7].absence = false;
				wCapturedCheckers += 1;
			}
		}
	}
	else if (player = false) {
		if (gameRow<nowRow && gameColumn>nowColumn) {
			if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 1][gameColumn - 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 2][gameColumn - 3].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 2][gameColumn - 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 2][gameColumn - 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 3][gameColumn - 4].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 3][gameColumn - 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 3][gameColumn - 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 4][gameColumn - 5].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 4][gameColumn - 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 4][gameColumn - 5].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 5][gameColumn - 6].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 5][gameColumn - 6].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 5][gameColumn - 6].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 6][gameColumn - 7].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 6][gameColumn - 7].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 6][gameColumn - 7].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow < nowRow && gameColumn < nowColumn)
		{
			if (arr[gameRowToInt(gameRow) + 1][gameColumn].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 1][gameColumn].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 1][gameColumn].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 2][gameColumn + 1].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 2][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 2][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 3][gameColumn + 2].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 3][gameColumn + 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 3][gameColumn + 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 4][gameColumn + 3].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 4][gameColumn + 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 4][gameColumn + 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 5][gameColumn + 4].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 5][gameColumn + 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 5][gameColumn + 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) + 6][gameColumn + 5].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) + 6][gameColumn + 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) + 6][gameColumn + 5].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow > nowRow && gameColumn < nowColumn)
		{
			if (arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 1][gameColumn].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 2][gameColumn + 1].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 2][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 2][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 3][gameColumn + 2].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 3][gameColumn + 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 3][gameColumn + 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 4][gameColumn + 3].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 4][gameColumn + 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 4][gameColumn + 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 5][gameColumn + 4].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 5][gameColumn + 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 5][gameColumn + 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 6][gameColumn + 5].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 6][gameColumn + 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 6][gameColumn + 5].absence = false;
				wCapturedCheckers += 1;
			}
		}
		else if (gameRow > nowRow && gameColumn > nowColumn)
		{
			if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 1][gameColumn - 2].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 2][gameColumn - 3].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 2][gameColumn - 3].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 2][gameColumn - 3].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 3][gameColumn - 4].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 3][gameColumn - 4].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 3][gameColumn - 4].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 4][gameColumn - 5].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 4][gameColumn - 5].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 4][gameColumn - 5].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 5][gameColumn - 6].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 5][gameColumn - 6].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 5][gameColumn - 6].absence = false;
				wCapturedCheckers += 1;
			}
			if (arr[gameRowToInt(gameRow) - 6][gameColumn - 7].stateOfTheCell == white)
			{
				arr[gameRowToInt(gameRow) - 6][gameColumn - 7].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow) - 6][gameColumn - 7].absence = false;
				wCapturedCheckers += 1;
			}
		}
	}
}
int canAPawnwWalkAttack(Checkers** arr, char gameRow, int gameColumn, char nowRow, int nowColumn) {
	if (player == true) {
		if (gameRowToInt(gameRow) == 0)
		{
			if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow) + 1][gameColumn].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
		}
		else if (gameRowToInt(gameRow) == 7) {
		    if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
		    }
		    else return 0;
		}
		else{
			if (arr[gameRowToInt(gameRow )+ 1][gameColumn - 2].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2 ) && ( gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )- 1][gameColumn - 2].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )+ 1][gameColumn ].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )- 1][gameColumn ].stateOfTheCell == black && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else return 0;
		}
	}
	else if (player == false) {
		if (gameRowToInt(gameRow) == 7) {
			if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else return 0;
		}
		else if (gameRowToInt(gameRow) == 0)
		{
			if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow) + 1][gameColumn].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
		}
		else{
			if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )- 1][gameColumn - 2].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )+ 1][gameColumn].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else if (arr[gameRowToInt(gameRow )- 1][gameColumn ].stateOfTheCell == white && (gameRow - nowRow == 2 || gameRow - nowRow == -2) && (gameColumn - nowColumn == 2 || gameColumn - nowColumn == -2)) {
				attackPawn = true;
				return 1;
			}
			else return 0;
		}

	}
}

int сanAPawnWalk(Checkers** arr, char gameRow, int gameColumn, char nowRow, int nowColumn) {
	int countW = 0;
	if (attackPawn == true)
	{
		if (canAPawnwWalkAttack(arr, gameRow, gameColumn, nowRow, nowColumn) == 1)return 1;

	}
	else if (arr[gameRowToInt(nowRow)][nowColumn -1].queen == true)
	{
		if (canAPqwnWalkQueen(arr, gameRow, gameColumn, nowRow, nowColumn) == 1)return 1;
	}
	else{
		if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false)countW += 1;
		if (arr[gameRowToInt(nowRow)][nowColumn - 1].queen == true) countW += 1;
	    if ((gameRow - nowRow == 1 || gameRow - nowRow == -1) && (gameColumn - nowColumn == 1 || gameColumn - nowColumn == -1))countW += 1;
		if (player == true) {
			if (nowRow - 1 == gameRow && (nowColumn + 1 == gameColumn || nowColumn - 1 == gameColumn)) countW += 1;
		}
		else if (player == false) {
			if (nowRow + 1 == gameRow && (nowColumn + 1 == gameColumn || nowColumn - 1 == gameColumn)) countW += 1;
		}

	}
	if (canAPawnwWalkAttack(arr, gameRow, gameColumn, nowRow, nowColumn) == 1)return 1;
		
	if (countW == 3 || countW == 4) return 1;
	else return 0;
	
	
	
	
}
int areTheSymbolsNecessary(char gameRow, int gameColumn, char nowRow, int nowColumn) {
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gameRow >= 97 && gameRow <= 104) count += 1;
		else if (nowRow >= 97 && nowRow <= 104) count += 1;
		else if (gameColumn >= 1 && gameColumn <= 8) count += 1;
		else if (nowColumn >= 1 && nowColumn <= 8) count += 1;
	}
	

	if (count == 4)return 1;
	else return 0;
 }
void attack(Checkers **& arr,char gameRow,int gameColumn, char nowRow,int nowColumn) {
	if (player == true) {
		if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == black && arr[gameRowToInt(nowRow) - 1][nowColumn].stateOfTheCell == black) {
			arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) + 1][gameColumn - 2].absence = false;
			wCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == black && arr[gameRowToInt(nowRow) + 1][nowColumn].stateOfTheCell == black) {
			arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) - 1][gameColumn - 2].absence = false;
			wCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) + 1][gameColumn ].stateOfTheCell == black && arr[gameRowToInt(nowRow) - 1][nowColumn - 2].stateOfTheCell == black) {
			arr[gameRowToInt(gameRow) + 1][gameColumn ].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) + 1][gameColumn].absence = false;
			wCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) - 1][gameColumn ].stateOfTheCell == black && arr[gameRowToInt(nowRow) + 1][nowColumn - 2].stateOfTheCell == black) {
			arr[gameRowToInt(gameRow) - 1][gameColumn ].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) - 1][gameColumn ].absence = false;
			wCapturedCheckers += 1;

		}
	}
	else if (player == false) {
		if (arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell == white && arr[gameRowToInt(nowRow) - 1][nowColumn].stateOfTheCell == white) {
			arr[gameRowToInt(gameRow) + 1][gameColumn - 2].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) + 1][gameColumn - 2].absence = false;
			bCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell == white && arr[gameRowToInt(nowRow) + 1][nowColumn].stateOfTheCell == white) {
			arr[gameRowToInt(gameRow) - 1][gameColumn - 2].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) - 1][gameColumn - 2].absence = false;
			bCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) + 1][gameColumn].stateOfTheCell == white && arr[gameRowToInt(nowRow) - 1][nowColumn - 2].stateOfTheCell == white) {
			arr[gameRowToInt(gameRow) + 1][gameColumn ].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) + 1][gameColumn].absence = false;
			bCapturedCheckers += 1;

		}
		else if (arr[gameRowToInt(gameRow) - 1][gameColumn ].stateOfTheCell == white && arr[gameRowToInt(nowRow) + 1][nowColumn - 2].stateOfTheCell == white) {
			arr[gameRowToInt(gameRow) - 1][gameColumn].stateOfTheCell = '.';
			arr[gameRowToInt(gameRow) - 1][gameColumn ].absence = false;
			bCapturedCheckers += 1;

		}
	}
	
}

void pawnWalk(Checkers**& arr, int row, int column, char gameRow, int gameColumn, char nowRow, int nowColumn) {

	if (player == true)
	{
		if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false) {

			arr[gameRowToInt(gameRow)][gameColumn - 1].absence = true;
			arr[gameRowToInt(gameRow)][gameColumn - 1].stateOfTheCell = white;
			arr[gameRowToInt(nowRow)][nowColumn - 1].stateOfTheCell = '.';
			arr[gameRowToInt(nowRow)][nowColumn - 1].absence = false;
			
			

		}
		else if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == true) cout << " клетка в которую вы хотите переместить шашку уже заната!" << endl;
	}
	else if (player == false) {

		if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false)
		{
			arr[gameRowToInt(gameRow)][gameColumn - 1].absence = true;
			arr[gameRowToInt(gameRow)][gameColumn - 1].stateOfTheCell = black;
			arr[gameRowToInt(nowRow)][nowColumn - 1].stateOfTheCell = '.';
			arr[gameRowToInt(nowRow)][nowColumn - 1].absence = false;
			
			
		}
		else if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == true) cout << " клетка в которую вы хотите переместить шашку уже заната!" << endl;
	}
	if(attackPawn == true){
	attack(arr, gameRow, gameColumn, nowRow, nowColumn);
	attackPawn = false;
	}
}
void game(Checkers**& arr, int row, int column) {


	while (wCapturedCheckers != 12 || bCapturedCheckers != 12)
	{
		cout << attackPawn << endl;
		cout << "СЧЕТ:"<<endl;
		cout << "Игрок с белыми шашками:" <<wCapturedCheckers <<endl;
		cout << "Игрок с чеными шашками:" << bCapturedCheckers <<"\n\n";
		
		show(arr, row, column);
		char gameRow, nowRow;
		int gameColumn, nowColumn;
		if (player == true) cout << "Сейчас ход должен сделать игрок с белыми шашками" << "\n\n";
		else if (player == false) cout << "Сейчас ход должен сделать игрок с черными шашками" << "\n\n";
		needForAnAttack(arr,row,column);
		cout << "Введите букву ряда, той шашки которой хотите сходить:" << endl;
		cin >> nowRow;
		cout << "Введите номер колонны, той шашки которой хотите сходить:" << endl;
		cin >> nowColumn;

		cout << "Введите букву ряда, той клетки куда хотите перемести шашку:" << endl;
		cin >> gameRow;
		cout << "Введите номер колонны, той клетки куда хотите перемести шашку:" << endl;
		cin >> gameColumn;
		

		if (сanAPawnWalk(arr,gameRow, gameColumn, nowRow, nowColumn) == 1 && areTheSymbolsNecessary(gameRow,gameColumn,nowRow,nowColumn)==1 )
		{
		
		pawnWalk(arr, row, column, gameRow, gameColumn, nowRow, nowColumn);
		queen(arr, row);
		if (arr[gameRowToInt(nowRow)][nowColumn -1].queen == true){
			canAMoveBeAnAttackQueen(arr, gameRow, gameColumn, nowRow, nowColumn);
			changeTheQueen(arr, gameRow, gameColumn, nowRow, nowColumn);
		}
		queen(arr, row);
		cout << "queen:" << arr[gameRowToInt(gameRow)][gameColumn - 1].queen << endl;
		player = !player;
		}
		else  cout << "ВОЗМОЖНО ВЫ НЕ ПРАВЕЛНО ВВЕЛИ, ПОПРОБУЙТЕ ЕЩЕ РАЗ!" << endl;
		
		Sleep(2000);
		system("cls");


	}
	if (wCapturedCheckers == 12) cout << "ВЫИГРАЛ ИГРОК С БЕЛЫМИ ШАШКАМИ!";
	else if (bCapturedCheckers == 12) cout << "ВЫИГРАЛ ИГРОК С ЧЕРНЫМИ ШАШКАМИ!";
}




int main()
{
	setlocale(LC_ALL, "rus");
	int row = 8, column = 8;
	Checkers** damBrod = new Checkers * [row];
	for (int i = 0; i < row; i++)
	{
		damBrod[i] = new Checkers[column];
	}
	initialization(damBrod, row, column);


	int choice;
	bool work = true;
	while (work)
	{
		cout << endl << "Правила : 1" << endl;
		cout << "Начать новую игру : 2 " << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
		{
			rules();
			Sleep(7000);
			system("cls");
			break;
		}
		case 2: {
			game(damBrod, row, column);
			break;
		}
		default:
			break;
		}
	}

}
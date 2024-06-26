#include <iostream>
#include<Windows.h>
#include<string>
#include<fstream>
using namespace std;
int bQueen = 66;
int wQueen = 87;
int white = 119;
int black = 98;
bool player = true; // true(1) - white , false(0) - black
int wCapturedCheckers = 0;
int bCapturedCheckers = 0;

struct Checkers {
	char stateOfTheCell = 46;
	char queen;
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
	cout << "1.Простые шашки ходят только вперёд,но может бить назад" << endl;
	cout << "2.дамка может ходить на любое число полей" << endl;
	cout << "3.цель игры - съесть или запереть все шашки противника" << endl;
	cout << "4.бить можно произвольное количество шашек в любых направлениях" << endl;

}
void queen(Checkers** arr, int row, int column) {

	for (int i = 0; i < row; i++)
	{
		if (arr[7][i].stateOfTheCell == black)
		{
			arr[7][i].stateOfTheCell = bQueen;
		}
		else if (arr[0][i].stateOfTheCell == white)
		{
			arr[0][i].stateOfTheCell = wQueen;
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
//int сanAPawnWalk( char gameRow, int gameColumn, char nowRow, int nowColumn) {
//	if ((gameRow + 1 |gameRow - 1) == nowRow && nowColumn == (gameColumn + 1 | gameColumn - 1))
//	{
//		return 1;
//	}
//	else return 0;
//
//
//}
void pawnWalk(Checkers**& arr, int row, int column, char gameRow, int gameColumn, char nowRow, int nowColumn) {

	if (player == true)
	{
		if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == false) {

			arr[gameRowToInt(gameRow)][gameColumn - 1].absence = true;
			arr[gameRowToInt(gameRow)][gameColumn - 1].stateOfTheCell = white;
			arr[gameRowToInt(nowRow)][nowColumn - 1].stateOfTheCell = '.';
			arr[gameRowToInt(nowRow)][nowColumn - 1].absence = false;
			player = !player;
			if (arr[gameRowToInt(gameRow + 1)][gameColumn - 1].stateOfTheCell == black) {
				arr[gameRowToInt(gameRow + 1)][gameColumn - 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow + 1)][gameColumn - 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yeees";
			}
			else if (arr[gameRowToInt(gameRow - 1)][gameColumn - 1].stateOfTheCell == black) {
				arr[gameRowToInt(gameRow - 1)][gameColumn - 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow - 1)][gameColumn - 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yees";
			}
			else if (arr[gameRowToInt(gameRow + 1)][gameColumn + 1].stateOfTheCell == black) {
				arr[gameRowToInt(gameRow + 1)][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow + 1)][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yeees";
			}
			else if (arr[gameRowToInt(gameRow - 1)][gameColumn + 1].stateOfTheCell == black) {
				arr[gameRowToInt(gameRow - 1)][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow - 1)][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yees";
			}
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
			player = !player;
			if (arr[gameRowToInt(gameRow + 1)][gameColumn - 1].stateOfTheCell == white) {
				arr[gameRowToInt(gameRow + 1)][gameColumn - 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow + 1)][gameColumn - 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yeees";
			}
			else if (arr[gameRowToInt(gameRow - 1)][gameColumn - 1].stateOfTheCell == white) {
				arr[gameRowToInt(gameRow - 1)][gameColumn - 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow - 1)][gameColumn - 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yees";
			}
			else if (arr[gameRowToInt(gameRow + 1)][gameColumn + 1].stateOfTheCell == white) {
				arr[gameRowToInt(gameRow + 1)][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow + 1)][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yeees";
			}
			else if (arr[gameRowToInt(gameRow - 1)][gameColumn + 1].stateOfTheCell == white) {
				arr[gameRowToInt(gameRow - 1)][gameColumn + 1].stateOfTheCell = '.';
				arr[gameRowToInt(gameRow - 1)][gameColumn + 1].absence = false;
				wCapturedCheckers += 1;
				cout << "yees";
			}
		}
		else if (arr[gameRowToInt(gameRow)][gameColumn - 1].absence == true) cout << " клетка в которую вы хотите переместить шашку уже заната!" << endl;
	}
}
void game(Checkers**& arr, int row, int column) {


	while (wCapturedCheckers != 8 || bCapturedCheckers != 8)
	{
		show(arr, row, column);
		char gameRow, nowRow;
		int gameColumn, nowColumn;
		cout << "Введите букву ряда, той шашки которой хотите сходить:" << endl;
		cin >> nowRow;
		cout << "Введите номер колонны, той шашки которой хотите сходить:" << endl;
		cin >> nowColumn;

		cout << "Введите букву ряда, той клетки куда хотите перемести шашку:" << endl;
		cin >> gameRow;
		cout << "Введите номер колонны, той клетки куда хотите перемести шашку:" << endl;
		cin >> gameColumn;
		//if (сanAPawnWalk(gameRow, gameColumn, nowRow, nowColumn) == 1)
		//{
		pawnWalk(arr, row, column, gameRow, gameColumn, nowRow, nowColumn);
		queen(arr, row, column);
		//}
		//else cout << "возможно вы не правельно ввели знвчение попробуйте еще раз!" << endl;


	}
}

void needForAnAttack(Checkers** arr, int row, int column) {
	if (player == true)
	{
		for (int i = 0; i < row; i++)
		{
			for (int i = 0; i < column; i++)
			{
				/*if ()
				{

				}*/
			}
		}
	}
	else if (player == false)
	{

	}

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

#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);

int main() {
	char playAgain = 'y';
	cout << "=========================\n";
	cout << "     TIC TAC TOE\n";
	cout << "=========================\n";

	while (playAgain == 'y' || playAgain == 'Y') {
		char board[3][3] = {
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
		};

		char currentPlayer = 'X';
		int row, col;
		bool gameOver = false;

		while (!gameOver) {
			printBoard(board);
			cout << "Player " << currentPlayer << " turn\n";
			cout << "Enter row (0-2): ";
			cin >> row;
			cout << "Enter column (0-2): ";
			cin >> col;

			if (makeMove(board, row, col, currentPlayer)) {
				if (checkWin(board, currentPlayer)) {
					printBoard(board);
					cout << "Player " << currentPlayer << " wins!\n";
					gameOver = true;
				}
				else if (checkDraw(board)) {
					printBoard(board);
					cout << "It's a draw!\n";
					gameOver = true;
				}
				else {
					currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
				}
			}
			else {
				cout << "Invalid move! Try again.\n";
			}
		}

		bool validInput = false;

		while (!validInput) {
			cout << "Play again? (y/n): ";
			cin >> playAgain;

			if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') {
				validInput = true;
			} else {
				cout << "Invalid input! Please enter y or n.\n";
			}
		}
	}
	cout << "Thanks for playing!\n";
	return 0;
}

void printBoard(char board[3][3]) {
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";	
		if (i < 2) {
			cout << "---|---|---\n";
		}
	}
	cout << "\n";
}

bool makeMove(char board[3][3], int row, int col, char player) {
	if (row < 0 || row > 2 || col < 0 || col > 2) {
		return false;
	}
	if (board[row][col] != ' ') {
		return false;
	}
	board[row][col] = player;
	return true;
}

bool checkWin(char board[3][3], char player) {
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
			return true;
		}
	}
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
		return true;
	}
	return false;
}

bool checkDraw(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

#include<__msvc_all_public_headers.hpp>
using namespace std;
/*
* The selected code is a C++ program that simulates a 6x6 version of the classic game Connect Four. 
The game board is represented by a 2D array map[6][6], where each element can hold a value of 0 (empty), 1 (player 1's piece), or 2 (player 2's piece). 
The game proceeds in turns, allowing players to drop their pieces into the columns of the board.
The game checks for win conditions (horizontal, vertical, and diagonal lines of four consecutive pieces) and a draw condition (when all columns are filled).
Here's a brief overview of the selected code:
1.The program includes necessary libraries and defines the main function.
2.It initializes variables such as iswin and draw flags, the game board map, the current player, and the user's choice.
3.The game loop continues until a win or draw condition is met.
4.Inside the loop, the program clears the console, displays the current game board, and prompts the current player to make a move.
5.It validates the user's choice and updates the game board accordingly.
6.The program then checks for win conditions by iterating through the game board and comparing adjacent pieces.
7.If a win condition is found, the program displays a win message, clears the console, and pauses the game.
8.After each move, the program checks for a draw condition by counting the number of filled columns.
9.If a draw condition is met, the program displays a draw message, clears the console, and pauses the game.
10.Finally, the program returns 0 to indicate successful execution.
The code is well-structured and functional, but it could benefit from more commentsexplaining the logic and purpose of each section.
*/
int main() {
	bool iswin = false, draw = false;
	int map[6][6] = {
	{ 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0}
	};
	int player = 1;
	int choice = 0;
	int upfilled = 0;
	while (!iswin&&!draw) {
		upfilled = 0;
		system("cls");
		cout << "玩家" << player << "执棋中\n      ";
		for (int i = 0; i < 6; i++) {
			cout << "-------------------------\n      | ";
			for (int j = 0; j < 6; j++) {
				cout << map[i][j] << " | ";
			}
			cout << "\n      ";
		}
		cout << "-------------------------\n";
		cin >> choice;
		if (choice > 0 && choice < 7) {
			if (map[0][choice - 1] == 0) {
				map[0][choice - 1] = player;
				for (int i = 1; i < 6; i++) {
					if (map[i][choice - 1] == 0) {
						map[i][choice - 1] = map[i - 1][choice - 1];
						map[i - 1][choice - 1] = 0;
					}
				}
				player = 3 - player;
			}
			else {
				cout << "该编号已占满，请重新输入！\n";
				system("pause");
			}
		}
		else {
			cout << "请输入正确的序号！\n";
			system("pause");
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] == map[i][j+1] && map[i][j+1] == map[i][j+2] && map[i][j+2] == map[i][j+3] && map[i][j] != 0) {
					system("cls");
					cout << "玩家" << map[i][j] << "已获胜\n      ";
					for (int i = 0; i < 6; i++) {
						cout << "-------------------------\n      | ";
						for (int j = 0; j < 6; j++) {
							cout << map[i][j] << " | ";
						}
						cout << "\n      ";
					}
					cout << "-------------------------\n";
					iswin = true;
					system("pause");
				}
			}
		}
		for (int j = 0; j < 6; j++) {
			for (int i = 0; i < 3; i++) {
				if (map[i][j] == map[i + 1][j] && map[i + 1][j]== map[i + 2][j] && map[i + 2][j] == map[i + 3][j] && map[i][j] != 0) {
					system("cls");
					cout << "玩家" << map[i][j] << "已获胜\n      ";
					for (int i = 0; i < 6; i++) {
						cout << "-------------------------\n      | ";
						for (int j = 0; j < 6; j++) {
							cout << map[i][j] << " | ";
						}
						cout << "\n      ";
					}
					cout << "-------------------------\n";
					iswin = true;
					system("pause");
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] == map[i + 1][j + 1] && map[i + 1][j + 1] == map[i + 2][j + 2] && map[i + 2][j + 2] == map[i + 3][j + 3] && map[i][j] != 0) {
					system("cls");
					cout << "玩家" << map[i][j] << "已获胜\n      ";
					for (int i = 0; i < 6; i++) {
						cout << "-------------------------\n      | ";
						for (int j = 0; j < 6; j++) {
							cout << map[i][j] << " | ";
						}
						cout << "\n      ";
					}
					cout << "-------------------------\n";
					iswin = true;
					system("pause");
				}
			}
		}
		for (int i = 3; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] == map[i - 1][j + 1] && map[i - 1][j + 1] == map[i - 2][j + 2] && map[i - 2][j + 2] == map[i - 3][j + 3] && map[i][j] != 0) {
					system("cls");
					cout << "玩家" << map[i][j] << "已获胜\n      ";
					for (int i = 0; i < 6; i++) {
						cout << "-------------------------\n      | ";
						for (int j = 0; j < 6; j++) {
							cout << map[i][j] << " | ";
						}
						cout << "\n      ";
					}
					cout << "-------------------------\n";
					iswin = true;
					system("pause");
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			upfilled += (map[0][i] != 0);
		}
		if (upfilled == 6) {
			system("cls");
			cout << "已平局\n      ";
			for (int i = 0; i < 6; i++) {
				cout << "-------------------------\n      | ";
				for (int j = 0; j < 6; j++) {
					cout << map[i][j] << " | ";
				}
				cout << "\n      ";
			}
			cout << "-------------------------\n";
			draw = true;
			system("pause");
		}
	}
	return 0;
}

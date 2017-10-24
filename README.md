#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

 ///////////////////////////////////////
 // UTILITY FUNCTIONS //////////////////
 ///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (board[i][k] == 0) {
				count = count + 1;
			}
		}
	}
	return count;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
	int count = 0;

	for (int i = 0; i < size; i++) {

		if (board[row][i] == color) {
			count = count + 1;
			if (count == 3) {
				return false;
			}
		}
		else {
			count = 0;
		}
	}
	
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
	int count = 0;

	for (int i = 0; i < size; i++) {

		if (board[i][col] == color) {
			count = count + 1;
			if (count == 3) {
				return false;
			}
		}
		else {
			count = 0;
		}
	}

	return true;
}


bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
	for (int i = 0; i < size; i++) {
		if (row_has_no_threes_of_color(board, size, i, RED)) {
		}
		else { return false;
		}
	}
	for (int i = 0; i < size; i++) {
		if (col_has_no_threes_of_color(board, size, i, RED)) {
		}
		else {
			return false;
		}
	}
	for (int i = 0; i < size; i++) {
		if (row_has_no_threes_of_color(board, size, i, BLUE)) {
		}
		else {
			return false;
		}
	}
	for (int i = 0; i < size; i++) {
		if (col_has_no_threes_of_color(board, size, i, BLUE)) {
		}
		else {
			return false;
		}
	}
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
	int size,
	int row1,
	int row2) {

	for (int i = 0; i < size; i++) {
		if (board[i][row1] != RED || BLUE) {
			return true;
		}
		if (board[i][row2] != RED || BLUE) {
			return true;
		}

		for (int i = 0; i < size; i++) {
			if (board[row1][i] != board[row2][i]) {
				return true;
			}
		}
		return false;
	}
}


	bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
		int size,
		int col1,
		int col2) {


		for (int i = 0; i < size; i++) {
			if (board[i][col1] != RED || BLUE) {
				return true;
			}
			if (board[i][col2] != RED || BLUE) {
				return true;
			}


			for (int i = 0; i < size; i++) {
				if (board[i][col1] != board[i][col2]) {
					return true;
				}
			}
			return false;
		}
	}
	

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {

	bool noDuplicate = true;

	for (int k = 0; k < size; k++) {
		for (int j = 1; (j < k || j > k && j < size); j++) {
			if (rows_are_different(board, size, k, j)) {
				noDuplicate = true;
			}
			else {
				return false;
			}
		}
	}
	for (int k = 0; k < size; k++) {
		for (int j = 1; (j < k || j > k && j < size); j++) {
			if (cols_are_different(board, size, k, j)) {
				noDuplicate = true;
			}
			else {
				return false;
			}
		}
		
	}
	return noDuplicate;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////


void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int row,
	bool announce) {
	for (int j = 0; j < size; j++) {

		if (board[row][j] == RED && board[row][j] == board[row][j + 1]) {
			if ((j + 2) < size) {
				mark_square_as(board, size, row, j + 2, BLUE, true);
			}
			if ((j - 1) >= 0) {
				mark_square_as(board, size, row, j - 1, BLUE, true);
			}
		}
		else if (board[row][j] == RED && board[row][j] == board[row][j + 2]) {
			mark_square_as(board, size, row, j + 1, BLUE, true);
		}

		if (board[row][j] == BLUE && board[row][j] == board[row][j + 1]) {
			if ((j + 2) < size) {
				mark_square_as(board, size, row, j + 2, RED, true);
			}
			if ((j - 1) >= 0) {
				mark_square_as(board, size, row, j - 1, RED, true);
			}
		}
		else if (board[row][j] == BLUE && board[row][j] == board[row][j + 2]) {
			mark_square_as(board, size, row, j + 1, RED, true);
		}
	}
}


void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int col,
	bool announce) {

	for (int i = 0; i < size; i++) {

		if (board[i][col] == RED && board[i][col] == board[i + 1][col]) {
			if ((i + 2) < size) {
				mark_square_as(board, size, i + 2, col, BLUE, true);
			}
			if ((i - 1) >= 0) {
				mark_square_as(board, size, i - 1, col, BLUE, true);
			}
		}
		else if (board[i][col] == RED && board[i][col] == board[i + 2][col]) {
			mark_square_as(board, size, i + 1, col, BLUE, true);
		}

		if (board[i][col] == BLUE && board[i][col] == board[i + 1][col]) {
			if ((i + 2) < size) {
				mark_square_as(board, size, i + 2, col, RED, true);
			}
			if ((i - 1) >= 0) {
				mark_square_as(board, size, i - 1, col, RED, true);
			}
		}
		else if (board[i][col] == BLUE && board[i][col] == board[i + 2][col]) {
			mark_square_as(board, size, i + 1, col, RED, true);
		}
	}


}



void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int row,
	bool announce) {

	int numRed = 0;
	for (int j = 0; j < size; j++) {

		if (board[row][j] == RED) {
			numRed += 1;
		}

	}
	if (numRed == size / 2) {
		for (int j = 0; j < size; j++) {
			if (board[row][j] == UNKNOWN) {
				mark_square_as(board, size, row, j, BLUE, true);
			}
		}
	}
	int numBlue = 0;
	for (int j = 0; j < size; j++) {

		if (board[row][j] == BLUE) {
			numBlue += 1;
		}

	}
	if (numBlue == size / 2) {
		for (int j = 0; j < size; j++) {
			if (board[row][j] == UNKNOWN) {
				mark_square_as(board, size, row, j, RED, true);
			}
		}

	}
}


void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int col, bool announce) {

	int numRed = 0;

	for (int i = 0; i < size; i++) {

		if (board[i][col] == RED) {
			numRed += 1;
		}

	}
	if (numRed == size / 2) {
		for (int i = 0; i < size; i++) {
			if (board[i][col] == UNKNOWN) {
				mark_square_as(board, size, i, col, BLUE, true);
			}
		}
	}
	int numBlue = 0;
	for (int i = 0; i < size; i++) {

		if (board[i][col] == BLUE) {
			numBlue += 1;
		}

	}
	if (numBlue == size / 2) {
		for (int i = 0; i < size; i++) {
			if (board[i][col] == UNKNOWN) {
				mark_square_as(board, size, i, col, RED, true);
			}
		}

	}
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {


	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {

			if (board[i][j] == UNKNOWN) {
				return false;
			}
		}
	}


	if (board_has_no_threes(board, size) == false) {
		return false;
	}
	if (board_has_no_duplicates(board, size) == false) {
		return false;
	}




	return true;
}


bool check_valid_input(int size, int row_input, char col_input,
	char color_char, int &row, int &col) {
	if (row_input < 1 && row_input > size) {
		cout << "Sorry, that's not a valid input." << endl;
		return false;
	}
	if ((col_input < 'A' && col_input >('A' + size - 1)) ||
		(col_input < 'a' && col_input >('a' + size - 1))) {
		cout << "Sorry, that's not a valid input." << endl;
		return false;
	}

	if (color_char != RED_LETTER && color_char != BLUE_LETTER && color_char != UNKNOWN_LETTER
		&& color_char != 'x' && color_char != 'o') {
		cout << "Sorry, that's not a valid input." << endl;
		return false;
	}

	row = row_input - 1;
	col = col_input - 1;
	return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
	const int current_board[MAX_SIZE][MAX_SIZE],
	int size, int row, int col, int color) {



	if (original_board[row][col] == current_board[row][col]) {
		cout << "Sorry, that move violates a rule." << endl;
		return false;
	}
	if (current_board[row][col] == opposite_color(original_board[row][col])) {
		cout << "original squares cannot be changed." << endl;
		return false;
	}
	if (current_board[row][col] && !board_has_no_duplicates(current_board, size)) {
		cout << "Sorry, that move violates a rule." << endl;
		return false;
	}
	if (current_board[row][col] && !board_has_no_threes(current_board, size)) {
		cout << "Sorry, that move violates a rule." << endl;
		return false;

	}






	return true;
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int row,
	bool announce) {
	int numRed = 0;
	for (int j = 0; j < size; j++) {
		if (board[row][j] == RED) {
			numRed += 1;
		}
	}
	if (numRed == ((size / 2) - 1)) {
		for (int j = 0; j < size; j++) {
			if (board[row][j] == UNKNOWN) {
				if (board_has_no_threes(board, size) && board_has_no_duplicates(board, size)) {
					mark_square_as(board, size, row, j, RED, true);
				}

			}
		}
	}
	int numBlue = 0;
	for (int j = 0; j < size; j++) {
		if (board[row][j] == BLUE) {
			numBlue += 1;
		}
	}
	if (numBlue == ((size / 2) - 1)) {
		for (int j = 0; j < size; j++) {
			if (board[row][j] == UNKNOWN) {
				if (board_has_no_threes(board, size) && board_has_no_duplicates(board, size)) {
					mark_square_as(board, size, row, j, BLUE, true);
				}
			}
		}
	}
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
	int size,
	int col,
	bool announce) {

	int numRed = 0;
	for (int i = 0; i < size; i++) {
		if (board[i][col] == RED) {
			numRed += 1;
		}
	}
	if (numRed == ((size / 2) - 1)) {
		for (int i = 0; i < size; i++) {
			if (board[i][col] == UNKNOWN) {
				if (board_has_no_threes(board, size) && board_has_no_duplicates(board, size)) {
					mark_square_as(board, size, i, col, RED, true);

				}
			}
		}
	}


	int numBlue = 0;
	for (int i = 0; i < size; i++) {
		if (board[i][col] == BLUE) {
			numBlue += 1;
		}
	}
	if (numBlue == ((size / 2) - 1)) {
		for (int i = 0; i < size; i++) {
			if (board[i][col] == UNKNOWN) {
				if (board_has_no_threes(board, size) && board_has_no_duplicates(board, size)) {
					mark_square_as(board, size, i, col, BLUE, true);
				}
			}
		}
	}
}

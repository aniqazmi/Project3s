/**
 * test.cpp
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2017
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_cols_are_different();
void test_board_has_no_duplicates(); 
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();


/*
int main() {
	test_board_has_no_duplicates();



	

    return 0;
}
*/

void test_count_unknown_squares() {
	int board[MAX_SIZE][MAX_SIZE];

	// test case 1
	string test_board_1[] = { "O-OX",
							 "OO--",
							 "X---",
							 "-O--" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << count_unknown_squares(board, size_1) << endl;

	//test case 2 
	string test_board_2[] = { "O-----",
							 "OO----",
							 "---XX-",
							 "X-O---",
							 "XO----",
							 "--XO--"};
	int size_2 = 6;
	read_board_from_string(board, test_board_2, size_2);
	cout << count_unknown_squares(board, size_2) << endl;
}

void test_row_has_no_threes_of_color() {
	int board[MAX_SIZE][MAX_SIZE];


	// test case 1
	string test_board_1[] = { "XX--",
							  "XXX-",
							  "X---",
							  "-O--" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << row_has_no_threes_of_color(board, size_1, 1, RED) << "  Should return a 0 for false" << endl;

	//test case 2 
	string test_board_2[] = { "O-----",
		"OO----",
		"---XX-",
		"X-O---",
		"XO----",
		"--XO--" };
	int size_2 = 6;
	read_board_from_string(board, test_board_2, size_2);
	cout << row_has_no_threes_of_color(board, size_1, 1, RED) << "  Should return a 1 for true" << endl;


}

void test_col_has_no_threes_of_color() {
	int board[MAX_SIZE][MAX_SIZE];


	// test case 1
	string test_board_1[] = { "-X--",
							  "XX--",
							  "X---",
							  "XO--" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << col_has_no_threes_of_color(board, size_1, 0, RED) << "  Should return a 0 for False" << endl;

	//test case 2 
	
	string test_board_2[] = { "O-----",
							  "OO-X--",
							  "---XX-",
							  "X-OX--",
		                      "XO----",
							  "--XO--" };
	int size_2 = 6;
	read_board_from_string(board, test_board_2, size_2);
	cout << col_has_no_threes_of_color(board, size_2, 3, RED) << "  Should return a 0 for False" << endl;
	
}
void test_board_has_no_threes() {
	int board[MAX_SIZE][MAX_SIZE];


	// test case 1
	string test_board_1[] = { "-X--",
							  "XX--",
							  "X---",
							  "XO--" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << board_has_no_threes(board, size_1) << " Should print 0 for False " << endl;

	//test case 2 

	string test_board_2[] = { "O-----",
							  "OO-X--",
							  "---XX-",
							  "X-OX--",
							  "XO----",
							  "--XO--" };
	int size_2 = 6;
	read_board_from_string(board, test_board_2, size_2);
	cout << board_has_no_threes(board, size_2) << " Should print 0 for False " << endl;
	// test case 3
	string test_board_3[] = { "-X--",
							  "XX--",
							  "O---",
							  "XO--" };
	int size_3 = 4;
	read_board_from_string(board, test_board_3, size_3);
	cout << board_has_no_threes(board, size_3) << " Should print 1 for True " << endl;

	//test case 4 

	string test_board_4[] = { "O-----",
							  "OO-X--",
							  "---OX-",
							  "X-OX--",
							  "XO----",
							  "--XO--" };
	int size_4 = 6;
	read_board_from_string(board, test_board_4, size_4);
	cout << board_has_no_threes(board, size_4) << " Should print 1 for True " << endl;
}
void test_cols_are_different() {
	int board[MAX_SIZE][MAX_SIZE];

// First 3 test cases are for a board of size 4.

	// test case 1
	string test_board_1[] = { "XX--",
							  "XX--",
						      "XX--",
							  "XX--" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	cout << cols_are_different(board, size_1, 0, 1) << " Should print 0 for False" << endl;

	// test case 2
	string test_board_2[] = { "XX--",
							  "XX--",
							  "XX--",
							  "XO--" };
	int size_2 = 4;
	read_board_from_string(board, test_board_2, size_2);
	cout << cols_are_different(board, size_2, 0, 1) << " Should print 1 for True" << endl;

	// test case 3
	string test_board_3[] = { "XO--",
							  "XX--",
							  "XX--",
							  "XX--" };
	int size_3 = 4;
	read_board_from_string(board, test_board_3, size_3);
	cout << cols_are_different(board, size_3, 0, 1) << " Should print 1 for True" << endl;

// The next 2 will test a board of size 6.

	//test case 4 

	string test_board_4[] = { "OO----",
							  "OO-X--",
							  "OO-XX-",
							  "XXOX--",
							  "XO----",
							  "XXXO--" };
	int size_4 = 6;
	read_board_from_string(board, test_board_4, size_4);
	cout << cols_are_different(board, size_4, 0, 1) << " Should print 1 for True" << endl;

	//test case 5 

	string test_board_5[] = { "OO----",
							  "OO-X--",
							  "OO-XX-",
							  "XXOX--",
							  "XX----",
							  "XXXO--" };
	int size_5 = 6;
	read_board_from_string(board, test_board_5, size_5);
	cout << cols_are_different(board, size_5, 0, 1) << " Should print 0 for False" << endl;

// The next 2 will test a board of size 8.


	//test case 6 

	string test_board_6[] = { "OO------",
							  "OO-X----",
							  "OO-XX---",
							  "XXOX----",
							  "XX------",
							  "XX------",
							  "XX------",
							  "XXXO--XX" };
	int size_6 = 8;
	read_board_from_string(board, test_board_6, size_6);
	cout << cols_are_different(board, size_6, 0, 1) << " Should print 0 for False" << endl;

	//test case 7 

	string test_board_7[] = { "OO------",
							  "OO-X----",
							  "OO-XX---",
							  "XXOX----",
							  "XO------",
							  "XO------",
							  "XX------",
							  "XXXO--XX" };
	int size_7 = 8;
	read_board_from_string(board, test_board_7, size_7);
	cout << cols_are_different(board, size_7, 0, 1) << " Should print 1 for True" << endl;
}
void test_board_has_no_duplicates() {


	int board[MAX_SIZE][MAX_SIZE];

	// First 3 test cases are for a board of size 4.

	// test case 1 
	// tests for columns
	string test_board_1[] = { "XX----",
							  "X----X",
							  "--O--X",
							  "--O---",
							  "X-----",
							  "---X--" };
	int size_1 = 6;
	read_board_from_string(board, test_board_1, size_1);
	cout << board_has_no_duplicates(board, size_1) << " Should print 0 for False" << endl;

	// test case 2
	// test for rows
	string test_board_2[] = { "XXOO",
							  "XXOO",
							  "XOXO",
							  "OOXX" };
	int size_2 = 4;
	read_board_from_string(board, test_board_2, size_2);
	cout << board_has_no_duplicates(board, size_2) << " Should print 0 for False" << endl;

	// test case 3
	// This case test for a mixed board
	string test_board_3[] = { "XXOO",
							  "OXOX",
							  "XOXO",
							  "OOXX" };
	int size_3 = 4;
	read_board_from_string(board, test_board_3, size_3);
	cout << board_has_no_duplicates(board, size_3) << " Should print 1 for True" << endl;

	// The next 2 will test a board of size 6.

	//test case 4 

	string test_board_4[] = { "OOXXOX",
							  "XOXOXO",
							  "OXOXXO",
							  "XOOXOX",
							  "XOXOOX",
							  "OXOXOX" };
	int size_4 = 6;
	read_board_from_string(board, test_board_4, size_4);
	cout << board_has_no_duplicates(board, size_4) << " Should print 1 for True" << endl;

	//test case 5 
	// This test case if targeting columns.

	string test_board_5[] = {	"OOXXOO",
								"OOXOXO",
								"OXOXXO",
								"XOOXOX",
								"XOXOOX",
								"OXOXOO" };
	int size_5 = 6;
	read_board_from_string(board, test_board_5, size_5);
	cout << board_has_no_duplicates(board, size_5) << " Should print 0 for False" << endl;

	// The next 2 will test a board of size 8.


	//test case 6 

	string test_board_6[] = {	"OOXXOXXX",
								"XOXOXOXO",
								"OXOXXOXX",
								"XOOXOXXX",
								"XOXOOXXX",
								"OXOXOXXX",
								"OXOXOXOX",
								"OXOXOXXO", };
	int size_6 = 8;
	read_board_from_string(board, test_board_6, size_6);
	cout << board_has_no_duplicates(board, size_6) << " Should print 1 for True" << endl;

}
void test_solve_three_in_a_row() {
	
	int board[MAX_SIZE][MAX_SIZE];
	// test case 1 
	
	string test_board_1[] = { "XX-O",
							  "X-X-",
							  "-XX-",
							  "--XX" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_three_in_a_row(board, size_1, 0, true);
	solve_three_in_a_row(board, size_1, 1, true);
	solve_three_in_a_row(board, size_1, 2, true);
	solve_three_in_a_row(board, size_1, 3, true);
	print_board(board, size_1);
}
void test_solve_three_in_a_column() {
	
	int board[MAX_SIZE][MAX_SIZE];
	// test case 1 
	
	string test_board_1[] = {	"XX-O",
								"X-X-",
								"-X--",
								"--XX"   };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_three_in_a_column(board, size_1, 0, true);
	solve_three_in_a_column(board, size_1, 1, true);
	solve_three_in_a_column(board, size_1, 2, true);
	solve_three_in_a_column(board, size_1, 3, true);
	print_board(board, size_1);
}


void test_solve_balance_row() {

	int board[MAX_SIZE][MAX_SIZE];
	// test case 1 

	string test_board_1[] = {	"XX-O",
								"X-X-",
								"-X--",
								"--XX" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_balance_row(board, size_1, 0, true);
	solve_balance_row(board, size_1, 1, true);
	solve_balance_row(board, size_1, 2, true);
	solve_balance_row(board, size_1, 3, true);
	print_board(board, size_1);

	string test_board_6[] = {	"OXXX---X",
								"-X-X-X-X",
								"O-O-O-O-",
								"XO---XXX",
								"XOXOOXXX",
								"OXOXOXXX",
								"OXOXOXOX",
								"OXOXOXXO", };
	int size_6 = 8;
	read_board_from_string(board, test_board_6, size_6);
	solve_balance_row(board, size_6, 0, true);
	solve_balance_row(board, size_6, 1, true);
	solve_balance_row(board, size_6, 2, true);
	solve_balance_row(board, size_6, 3, true);
	print_board(board, size_6);

}
void test_solve_balance_column()  {
	int board[MAX_SIZE][MAX_SIZE];
	// test case 1 

	string test_board_1[] = {	"XX-O",
								"X-X-",
								"-X--",
								"--XX" };
	int size_1 = 4;
	read_board_from_string(board, test_board_1, size_1);
	solve_balance_column(board, size_1, 0, true);
	solve_balance_column(board, size_1, 1, true);
	solve_balance_column(board, size_1, 2, true);
	solve_balance_column(board, size_1, 3, true);
	print_board(board, size_1);

	string test_board_6[] = {	"-OX----X",
								"-O---X-X",
								"X-XX--O-",
								"-----XXX",
								"OXOOOXX-",
								"XXOXOXXX",
								"XXOXOXOX",
								"XXOXOXXO", };
	int size_6 = 8;
	read_board_from_string(board, test_board_6, size_6);
	solve_balance_column(board, size_6, 0, true);
	solve_balance_column(board, size_6, 1, true);
	solve_balance_column(board, size_6, 2, true);
	solve_balance_column(board, size_6, 3, true);
	solve_balance_column(board, size_6, 4, true);

	print_board(board, size_6);
}

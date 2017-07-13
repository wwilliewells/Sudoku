/*
 * File: Sudoku_Generator.h
 * AUTHOR: William Willie Wells
 * DATE: July 2017 ...
 */

#ifndef _SUDOKU_GENERATOR_H_
#define _SUDOKU_GENERATOR_H_

// package message/structs include  
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


// namespace
using namespace std;

// class
//template <class Node>
class SudokuGenerator{
  public:
    // con(de)structors
	SudokuGenerator();
    ~SudokuGenerator();
	
    void reset();
	int pseudoRandomStart();
    int getDigit();
    bool checkUnique(int,int);
    bool checkGrid();
    int searchColumn(int,int);
    void swap(int, int);
	void fillGrid();
    void printGrid();
	
  private:
    // in(ex)ternal parameters
	bool uniqueRow[9][9];
    bool uniqueColumn[9][9];
    bool randDigit[9];
    int digit;
    int grid[9][9];
    int tmp;
};
#endif // sudoku_generator

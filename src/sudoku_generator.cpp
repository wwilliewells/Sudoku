/*
 * FILE: sudoku_generator.cpp
 * AUTHOR: William Willie Wells
 * DATE: July 2017 ...
 */
 
 // class include
#include "../include/sudoku_generator.h"

// constructor -- initializes matrices
SudokuGenerator::SudokuGenerator(){
  reset();

  while(!checkGrid()){ reset(); }
  printGrid();
}

// destructor
SudokuGenerator::~SudokuGenerator(){}

void SudokuGenerator::reset(){
  digit=0;
  for(int i=0; i<9; i++){ 
     randDigit[i]= 0;
     for( int j=0; j<9; j++){ 
        grid[i][j]= 0;
        uniqueRow[i][j]= 0;
        uniqueColumn[i][j]= 0;
     }
  }

  fillGrid();
}

bool SudokuGenerator::checkGrid(){
  for(int i=0; i<9; i++){ 
     for( int j=0; j<9; j++){
        if(grid[i][j] == 10){ return 0; }
     }
  }
  return 1;
}  

int SudokuGenerator::pseudoRandomStart(){
  srand(time(NULL));

  return getDigit(); 
}

bool SudokuGenerator::checkUnique(int row, int column){ 
  return uniqueRow[row][digit-1] | uniqueColumn[column][digit-1]; 
}

int SudokuGenerator::searchColumn(int column, int start){
  for(int i=start; i<9; i++){ if(!uniqueColumn[column][i]){ return i+1; } }
  return 10;
}

void SudokuGenerator::swap(int row, int column){
  tmp= searchColumn(column,0); 
  for(int i=0; i<9; i++){ 
     if(grid[row][i] == tmp){
       digit= 0; 
       do{
         digit= searchColumn(i,digit);
       }while(digit < 9 && uniqueRow[row][digit-1]);
       grid[row][i]= digit;
       uniqueRow[row][grid[row][i]-1]= 1;
       uniqueColumn[i][grid[row][i]-1]= 1;
       digit= tmp; 
       uniqueRow[row][digit-1]= 0;
       uniqueColumn[i][digit-1]= 0;
       break; 
    } 
  }
  digit=tmp;
}

int SudokuGenerator::getDigit(){ return rand() % 9 + 1; }

void SudokuGenerator::fillGrid(){
  digit= pseudoRandomStart();

  int count= 0;

  for(int i=0; i<9; i++){ 
     for( int j=0; j<9; j++){ 
		while(checkUnique(i,j)){ 
           digit= getDigit();
           if(!randDigit[digit-1]){ randDigit[digit-1]= 1; count++; }
           if(count == 8){ break; } 
        }
        if(count == 8 &&  checkUnique(i,j)){ swap(i,j); }
        count=0;
        uniqueRow[i][digit-1]= 1;
        uniqueColumn[j][digit-1]= 1;
        for(int k=0; k<9; k++){ randDigit[k]= 0; }
       
        grid[i][j]= digit;
    }
  }
}

void SudokuGenerator::printGrid(){
  for(int i=0; i<9; i++){ 
     for( int j=0; j<9; j++){ 
        cout<<grid[i][j]<<' ';
     }
     cout<<endl;
  }
}

#include <iostream>

int main () {

  // Decalre Variables
  int  rows, cols;
  char fillIn;
   
  std::cin >> rows;
  std::cin >> cols;

  while(rows != 0 && cols != 0){

    /* Start creating 2 dyn. 2d arrays
     1) Fill in field
     2) For mine count
    */
    
    char** field  = new char*[rows];
    int** mineField  = new int*[rows];

    for(unsigned int spot = 0; spot < rows; spot += 1) {
      field[spot] = new char[cols];
      mineField[spot] = new int[cols];
    }
    for (unsigned int row  = 0; row < rows; row += 1)
	 for (unsigned int col  = 0; col < cols; col += 1)
	   mineField[row][col] = 0;
    
    
    
    /* End creating dyn. 2d array */

    /* Start filling in 2d array */
    int totalSpots = cols*rows;
    for(unsigned int spot = 0; spot < totalSpots; spot += 1){
      // Get spot
      std::cin >> fillIn;
      // Fill
      field[spot/cols][spot%cols] = fillIn;
    }
    
    
    /* End filling in 2d array */
    
    /* Start Check
       The check will loop all spots until it finds a mine
       Once a mine is found loop through neighbors and increment mine count
    */

  
    for(unsigned int spot = 0; spot < totalSpots; spot += 1)
      if(field[spot/cols][spot%cols] == '*')
        for(int k = spot/cols-1; k <= spot/cols+1; k += 1)
	  for(int l = spot%cols-1; l <= spot%cols+1; l += 1)
	    if(k >= 0 && k < rows && l >= 0 && l < cols && field[k][l] != '*')
	      mineField[k][l] += 1;


    /* Start print changes */
    for (unsigned int row  = 0; row < rows; row += 1){
      for (unsigned int col  = 0; col < cols; col += 1){
	if (field[row][col] == '*'){
	  std::cout << "* ";
	}else{
	  std::cout << mineField[row][col] << ' ';
	}
      }
      	std::cout << std::endl;
    }
       
    // Get rows and columns
    
    std::cin >> rows;
    std::cin >> cols;
  }
}

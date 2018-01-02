//
//  main.cpp
//  Maze_Solver
//
//  Created by Ehud Adler on 9/28/17.
//  Copyright © 2017 Ehud Adler. All rights reserved.
//

#include <iostream>
#include "mazeSolver.hpp"

int main(int argc, const char * argv[]) {
    
    int maze[25] =  {
        
        0,  1,  1,  1,  1,
        0,  1,  0,  0,  0,
        0,  0,  0,  1,  0,
        1,  1,  0,  1,  0,
        0,  1,  0,  1,  0
        
    };
    
    mazeSolver mazeChecker = mazeSolver(maze);

    mazeChecker.DFS_Check(25, 5, 5, 24);

    if(mazeChecker.BFS_Check(25, 5, 5, 24)){
        std::cout<<"\n\nMaze is valid\n"<<std::endl;
    }else{
        std::cout<<"\nMaze is invalid\n"<<std::endl;
    }
    
    return 0;
}

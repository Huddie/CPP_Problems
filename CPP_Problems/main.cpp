//
//  main.cpp
//  CPP_Problems
//
//  Created by Ehud Adler on 9/19/17.
//  Copyright © 2017 Ehud Adler. All rights reserved.
//

#include <iostream>
#include "mazeSolver.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    int maze[25] =  {
        
                    0,  1,  1,  1,  1,
                    0,  1,  0,  0,  0,
                    0,  0,  0,  1,  0,
                    1,  1,  0,  1,  0,
                    0,  1,  0,  1,  0
        
                    };
    
    mazeSolver mazeChecker = mazeSolver(maze);
    
    if(mazeChecker.BFS_Check(25, 5, 5, 24)){
        cout<<"\n\nMaze is valid\n"<<endl;
    }else{
        cout<<"\nMaze is invalid\n"<<endl;
    }
    
    return 0;
}

//
//  mazeSolver.hpp
//  CPP_Problems
//
//  Created by Ehud Adler on 9/19/17.
//  Copyright © 2017 Ehud Adler. All rights reserved.
//

#ifndef mazeSolver_hpp
#define mazeSolver_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

/* BOARD
 
 0  1  1  0  1
 0  1  0  0  1
 0  0  0  1  1
 1  1  0  1  0
 0  1  0  0  0
 
 */

class mazeSolver {
    
private:
    int * maze;
    
public:
    
    mazeSolver(){
        maze = new int [25];
        for (int i = 0; i < 25; ++i){
            maze[i] = 0;
        }
    }
    
    mazeSolver(int * a){
        maze = a;
    }
    
    bool BFS_Check(int board_size, int width, int start, int end);
    
};

/* BFS ************ */
bool mazeSolver::BFS_Check(int board_size, int width, int start, int end){
    
    /* Check if start element is 0 (valid starting position) */
    
    if(maze[start] == 1){
        std::cout<<"Invalid start position"<<std::endl;
        return false;
    }
    

    // create visited array
    bool * visited = new bool[board_size];
    for(int i = 0; i < board_size; i++)
        visited[i] = false;
    
    // create queue
    std::queue<int> neighbors;
    
    // set node to equal the start node given by the user
    int node = start;


    visited[node] = true;
    neighbors.push(node);
    
    std::cout<<"Checked nodes"<<std::endl;

    while(!neighbors.empty())
    {
        
        node = neighbors.front();
        std::cout<<node<<' ';
        neighbors.pop();
        
        // Get all neighbors
        
        if ((node + 1) / width == node/width && node + 1 < board_size && !visited[node + 1] && maze[node + 1] == 0){
            visited[node + 1] = true;
            neighbors.push(node + 1);
        }
        if (node + width < board_size && !visited[node + width] && maze[node + width] == 0){
            visited[node + width] = true;
            neighbors.push(node + width);
        }
        if ((node - 1) / width == node/width && node - 1 >= 0 && !visited[node - 1] && maze[node - 1] == 0){
            visited[node - 1] = true;
            neighbors.push(node - 1);
        }
        if (node - width >= 0 && !visited[node - width] && maze[node - width] == 0){
            visited[node - width] = true;
            neighbors.push(node - width);
            
        }
        
        /* check if we have reached the end */
        if (node == end){
            return true;
        }
        
    }
    return false;
    
}
#endif /* mazeSolver_hpp */

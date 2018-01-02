//
//  mazeSolver.hpp
//  CPP_Problems
//
//  Created by Ehud Adler on 9/19/17.
//  Copyright © 2017 Ehud Adler. All rights reserved.
//

#ifndef mazeSolver_hpp
#define mazeSolver_hpp


/* mazeSolver class ++
 
 * This class takes in a maze (pointer to a 1D array) and returns either
     a) The maze is valid
     b) The maze is invalid
 Where valid means that there is a path from start (given by user) and end (given by user)
 
 * Each maze is made up of 0 and 1 where a 0 denotes an open space and a 1 denotes a wall
 
 * The maze is validated using BFS (breadth first search) TODO: DFS...etc
 
 ++ */


// Import required libraries

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

void DFS_Recursive_Check(int node, struct board maze, bool visited[], int mazeArray[]);
struct board {
    int board_size;
    int board_width;
    int end_Node;
}
board;
/* BOARD (visual example)
 
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
    
    // Default Constructor
    mazeSolver(){
        maze = new int [25];
        for (int i = 0; i < 25; ++i){
            maze[i] = 0;
        }
    }
    
    // 1st Constructor
    mazeSolver(int * a){
        maze = a;
    }
    
    // BFS function to be called by user and defined below
    bool BFS_Check(int board_size, int width, int start, int end);
    
    // DFS function to be called by user and defined below
    void DFS_Check(int board_size, int width, int start, int end);
    friend void DFS_Recursive_Check(int node, struct board maze, bool visited[], int mazeArray[]);

};

/* Breadth First Search */
bool mazeSolver::BFS_Check(int board_size, int width, int start, int end){
    
    /* Check if start element is 0 (valid starting position) */
    if(maze[start] == 1){
        
        // Check failed, inform user and end program
        std::cout<<"Invalid start position"<<std::endl;
        return false;
    }
    

    /*
     Create visited array
     
     Reason: The visited array will hold out visted nodes. This will make sure we only visit a node once and remove the possability for an infinite loop

     */
    
    bool * visited = new bool[board_size];
    
    // Initialize each element in the visited array to false - No nodes visited
    for(int i = 0; i < board_size; i++)
        visited[i] = false;
    
    /*
     Create Queue
     
     Reason: In order to perform a BFS, we need to use a Queue rather then a stack (DFS). A queue will allow us to check each node in the order that they were entered into the queue, in other terms, first in first out. I am calling the queue neighbors because this queue will hold the neighbors (that we havent already checked) of all the nodes we have already visisted.
     
     * A neighbor will be defined as any node that touches the current node from either above, below, right or left.
     
     Note: Because we are using a 1D array we must check for edge cases in which the right or left are in the next row and that neighboring node isnt below 0 or above N (length of array given by user) -- More of this is explained later
     
     */
    std::queue<int> neighbors;
    
    // Set node to equal the start node given by the user
    int node = start;

    // Set our start node to visited
    // TODO: Check if start node = end node. If so, return valid
    visited[node] = true;
    
    /* Push the node (Start node) into the queue
     Reason: This will allow us to pop the queue during the first iteration and test for all of the nodes neighbors, from that point on, the while loop (below) will add and pop the queue itself
     */
    
    neighbors.push(node);
    
    // Nice output for visual
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

/* Depth First Search */
void mazeSolver::DFS_Check(int board_size, int width, int start, int end){
    
    bool * visited = new bool[board_size];
    
    // Initialize each element in the visited array to false - No nodes visited
    for(int i = 0; i < board_size; i++)
        visited[i] = false;
    
    struct board mazeStruct = board;
    mazeStruct.board_size = board_size;
    mazeStruct.board_width = width;
    mazeStruct.end_Node = end;
    
    // Nice output for visual
    std::cout<<"Checked nodes"<<std::endl;
    
    // Recursive function
    DFS_Recursive_Check(start, mazeStruct, visited, maze);
    std::cout<<"\n\nMaze is invalid\n"<<std::endl;

}

void DFS_Recursive_Check(int node, struct board maze, bool visited[], int mazeArray[]) {
    
    std::cout<<node<<' ';

    /* BASE CASES */
    /* Check if start element is 0 (valid starting position) */
    if (mazeArray[node] == 1) {
        std::cout<<"\n\nInvalid starting node\n"<<std::endl;
    }
    /* check if we have reached the end */
    else if (node == maze.end_Node){
        std::cout<<"\n\nMaze is valid\n"<<std::endl;
        exit(1);
    }

    
    // Check all neighbors
    if ((node + 1) / maze.board_width == node/maze.board_width && node + 1 < maze.board_size && !visited[node + 1] && mazeArray[node + 1] == 0){
        visited[node + 1] = true;
        DFS_Recursive_Check(node + 1, maze, visited, mazeArray);
    }
    if (node + maze.board_width < maze.board_size && !visited[node + maze.board_width] && mazeArray[node + maze.board_width] == 0){
        visited[node + maze.board_width] = true;
        DFS_Recursive_Check(node + maze.board_width, maze, visited, mazeArray);
    }
    if ((node - 1) / maze.board_width == node/maze.board_width && node - 1 >= 0 && !visited[node - 1] && mazeArray[node - 1] == 0){
        visited[node - 1] = true;
        DFS_Recursive_Check(node - 1, maze, visited, mazeArray);
    }
    if (node - maze.board_width >= 0 && !visited[node - maze.board_width] && mazeArray[node - maze.board_width] == 0){
        visited[node - maze.board_width] = true;
        DFS_Recursive_Check(node - maze.board_width, maze, visited, mazeArray);
    }

}

#endif /* mazeSolver_hpp */

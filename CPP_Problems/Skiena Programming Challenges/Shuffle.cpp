  //
  //  main.cpp
  //  Skiena
  //
  //  Created by Ehud Adler on 12/27/17.
  //  Copyright © 2017 Ehud Adler. All rights reserved.
  //

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main(){
  std::vector< std::vector<int> > repVec;
  
    // Step 1: Copy and Paste :p
  std::string cards[52] =
  {
    "2 of Clubs",
    "3 of Clubs",
    "4 of Clubs",
    "5 of Clubs",
    "6 of Clubs",
    "7 of Clubs",
    "8 of Clubs",
    "9 of Clubs",
    "10 of Clubs",
    "Jack of Clubs",
    "Queen of Clubs",
    "King of Clubs",
    "Ace of Clubs",
    "2 of Diamonds",
    "3 of Diamonds",
    "4 of Diamonds",
    "5 of Diamonds",
    "6 of Diamonds",
    "7 of Diamonds",
    "8 of Diamonds",
    "9 of Diamonds",
    "10 of Diamonds",
    "Jack of Diamonds",
    "Queen of Diamonds",
    "King of Diamonds",
    "Ace of Diamonds",
    "2 of Hearts",
    "3 of Hearts",
    "4 of Hearts",
    "5 of Hearts",
    "6 of Hearts",
    "7 of Hearts",
    "8 of Hearts",
    "9 of Hearts",
    "10 of Hearts",
    "Jack of Hearts",
    "Queen of Hearts",
    "King of Hearts",
    "Ace of Hearts",
    "2 of Spades",
    "3 of Spades",
    "4 of Spades",
    "5 of Spades",
    "6 of Spades",
    "7 of Spades",
    "8 of Spades",
    "9 of Spades",
    "10 of Spades",
    "Jack of Spades",
    "Queen of Spades",
    "King of Spades",
    "Ace of Spades"
  };
  
  int rounds, numOfShuffles, temp;
  std::vector<int> tempV, shuffleV, placement, tempPlacement;
  
    // Get number of rounds
  std::cin >> rounds;
	     
  for(unsigned int i = 0; i < rounds; i+=1){

    // Reset::
    repVec.clear();
    tempV.clear();
    shuffleV.clear();
    placement.clear();
    tempPlacement.clear();
    
  std::cin >> numOfShuffles;
    
  for(unsigned int c = 0; c < numOfShuffles;  c++ /* LOL C++ */){
    for(unsigned int s = 0; s < 52;  s += 1){
      std::cin >> temp;
      tempV.push_back(temp-1);
    }
    repVec.push_back(tempV);
    tempV.clear();
  }

    // Step 1: Small Array
  for(unsigned int c = 0; c < 52;  c++){
    placement.push_back(c);
    tempPlacement.push_back(c);
  }

  int shuffleNum = 0;
  std::string line;
  std::cin.ignore();
  
  std::getline(std::cin, line);
  
  while (!line.empty()){
    
    shuffleNum = std::stoi(line);    
    shuffleV = repVec[shuffleNum-1];
    
    for(unsigned int c  = 0; c < shuffleV.size(); c++ /* HAHA AGAIN */){
      tempPlacement[c] =  placement[shuffleV[c]];
    }
    placement = tempPlacement;
    
    std::getline(std::cin, line);
  }
  
  for(auto el : placement){
    std::cout<<cards[el]<<std::endl;
  }
  std::cout<<std::endl;
  }
}

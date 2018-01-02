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

std::vector<std::string> CKVector;
std::vector<std::string> stackHolder[16];
std::map<char, char> reMap;


/* Okay function 
   - Checks if the encrypted word could be a match to a given decrypted word by testing each letter
   and seeing if that letter corrisponds to a different pre-set letter in the map
   - If no letter is set, assume that letter is good
   - If the set letter equals the testing letter, assume good
   - Once all letters have passed, return true
*/
bool okay(int word, std::string guess){
  // Loop through all letter of each word
  int index = 0;
  for(char letter : CKVector[word]){
    // Check if all letters are not in the map and/or the letters are in the map but the mapping is the same, return false
    if (reMap.find(letter) != reMap.end() && reMap[letter] != guess[index]) {
      return false;
    }
    index += 1;
  }
  
  // Create mapping and set true
  index = 0;
  for(char letter : CKVector[word]){
    reMap[letter] = guess[index];
    index += 1;
  }
  return true;
}
/* Backtracking Mapping Function 
   - Go word by word, testing to see if the sentence can be constructed using input words
   - If encrypted word cannot match decrypted word, backtrack
   - If backtracking yields incomplete match, return false
*/
bool findMapping(int word, int wordCount){
  // Check if all words have been tried
  if(word == wordCount){
    return true;
  }else{
    
    // Check all decrypted words of same length
    for(auto elm : stackHolder[CKVector[word].length()]){
      
      // Check if words can be mapped
      if(okay(word, elm)){
	
	// Try next encrypted word
        return (findMapping(word + 1, wordCount));
      }
    }
  }
  
  // Return false on complete failure
  return false;
}


int main() {
  
  std::string dictWord, encrypted;
  dictWord = encrypted = "";
  
  int wordCount = 0;
  
   // Fill array with vectors
  for(unsigned int k = 0; k < 16; k += 1){
    std::vector<std::string> vec;
    stackHolder[k] = vec;
  }

  // Get word count
  std::cin >> wordCount;

  // Fill vectors with words of same length as array of vectors  index
  for(unsigned int word = 0; word < wordCount; word += 1){
    
    std::cin >> dictWord;
    stackHolder[dictWord.length()].push_back(dictWord);
    
  }
  
  // Ignore whats left in the CIN
  std::cin.ignore();

  // INF Loop while getline 
  while(std::getline(std::cin, encrypted)){
    std::istringstream in(encrypted);

    // Clean up for next loop
    reMap.clear();
    CKVector.clear();
    
    // Fill encrypted Vector
    while(in >> dictWord){
      CKVector.push_back(dictWord);
    }

    // Create temp for proper order
    auto temp = CKVector;

    // Sort CKVector by size 
     std::sort(CKVector.begin(), CKVector.end(),
              [](const std::string& first, const std::string& second) -> bool {
               return first.length() > second.length();
     });

     // Start mapping and printing
    if(!findMapping(0,CKVector.size())){
      for(auto elem : temp){
        for(auto letter : elem){
          std::cout <<  '*';
        }
        std::cout << ' ';
      }
      
    }else{
      
      for(auto elem : temp){
        for(auto letter : elem){
          std::cout <<  reMap[letter];
        }
        std::cout << ' ';
      }
    }
    std::cout<<std::endl;
  }
}


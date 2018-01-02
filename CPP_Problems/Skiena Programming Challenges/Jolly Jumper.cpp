#include <iostream>
#include <iterator>
#include <sstream>
#include <map>


// The Jolly Jumper
/* Concept 

1) Loop through ints
2) Each loop add to dict
3) Check dict

*/

int main(){

   std::map<int, bool> JMap;
   
   std::string numLine;
   
   int pre, upTo, len;
   
   unsigned int interval = 0;
  
   while(std::getline(std::cin, numLine)){
     
     // Reset values
     JMap.clear();
     
     std::istringstream in(numLine);
     in >> len;
     in >> pre;
     
    while(in >> upTo){
      
      // Get jolly interval (Abs value)
      interval = pre - upTo < 0 ? upTo - pre : pre - upTo;

      // Add to dict
      JMap[interval] = true;

      // Update pre
      pre = upTo;
    
    }

    if(len == 1) std::cout<<"Jolly\n";
    
    //Loop through len checking dict
    for(unsigned int checkI = 1; checkI <= len-1; checkI += 1){
      // Check if key exists
      if (JMap.find(checkI) == JMap.end()) {
        std::cout<<"Not jolly\n";
        break;
      }
      // Check if we have completed the Jolly
      if(checkI == len-1){
       std::cout<<"Jolly\n";
      }
     }
    }
}

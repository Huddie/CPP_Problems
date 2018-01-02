#include <iostream>
#include <sstream>




int getScore()
int main(){

  int digit[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
  int suit[4]   = {0,0,0,0};
  
  char halfCard;
  std::string handLine;

  while(std::getline(std::cin, handLine)){
     std::istringstream in(numLine);
     
     // Get Black
     for(unsigned int card  = 0; card < 5; card += 1){
       
       // Digit
       in >> halfCard;
       switch(halfCard) {
       case: 'J':
	 digit[10] += 1;
	 break;
       case: 'Q':
	 digit[11] += 1;
	 break;
       case: 'K':
	 digit[12] += 1;
	 break;
       case: 'A':
	 digit[0] += 1;
       default:
	 digit[(halfCard - '0') % 48] += 1;
	 break;
       }
     }
       // Suit
       in >> halfCard;

     }
     
     // Get White
     for(unsigned int card  = 0; card < 5; card += 1){
       

     }

}

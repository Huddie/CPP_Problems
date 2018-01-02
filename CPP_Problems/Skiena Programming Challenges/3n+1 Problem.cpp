#include <iostream>


int main() {

  unsigned int  inNum, start = 1, end, count, highCount;
  
  while(std::cin >> start) {
    
    highCount = 0;

    std::cin >> end;

    std::cout << start;
    std::cout << " "  << end;

    for(; start <= end; start += 1) {
      unsigned int cycle = start;
      count = 0;
   
      while (cycle != 1) {
	if (cycle % 2 == 0) /* is even  */
	  cycle /= 2;
	else /* odd  */
	  cycle = (3 * cycle) + 1;

       count += 1;
       // q.enque(cycle);
      }
      if(count > highCount) highCount = count;
    }
    
    // Memo[q.front()] = q.size()
    // q.deque
    std::cout << " " << ++highCount << std::endl;
  }

  return 0;
  
}

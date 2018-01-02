//
//  sorter.hpp
//  Sort
//
//  Created by Ehud Adler on 10/15/17.
//  Copyright © 2017 Ehud Adler. All rights reserved.
//

#ifndef sorter_hpp
#define sorter_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>


class sorter {
    
private:
    std::vector<int> in_object;
    
public:
    
    // Default Constructor
//    sorter(){
//        in = new int [x];
//        for (int i = 0; i < x; ++i){
//            this.in_object[i] = 0;
//        }
//    }
    
    // 1st Constructor
    sorter(std::vector<int> a){
        in_object = a;
    }
    
    // quicksort sort function
    std::vector<int> quicksort(std::vector<int> v);
    
};

std::vector<int> sorter::quicksort(std::vector<int> v){
    
    // Find Pivot
    
    auto pivot
    
    // Partition
    
    std::partition(v.begin(), v.end(),[](auto x){ return x < pivot });
    std::partition(v.begin(), v.end(),[](auto x){ return x > pivot });

    // Base case check (iterators match up)
    if (p1 == p2) return

    // Quicksort the 2 new partition.
        sorter::quicksort(std::range)

}

#endif /* sorter_hpp */

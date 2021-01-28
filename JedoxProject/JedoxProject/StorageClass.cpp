//
//  StorageClass.cpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#include "StorageClass.hpp"
#include <iostream>
#include <cmath>

int StorageClass::info(void) {
    return count;
}

void StorageClass::CountUpdate(int count) {
    this->count = count;
}

int StorageClass::get_unique_value(void) {
    int uniq = 0;
    
    if(uv.size() == 0) {
        //create a unique value vector
        while(uv.size() != info()) {
            int rnd = rand() % info();
            if(std::find(uv.begin(), uv.end(), rnd) == uv.end()) {
                //we didn't find it, add to the vector
                uv.push_back(rnd);
            }
        }
    }
    
    uniq = *uv.begin();
    uv.erase(uv.begin());
    return uniq;
}

void StorageClass::print(void) {
    
    if(info() == 0) {
        std::cout << "end of storage reached" << std::endl;
        return;
    }

    class_mutex.lock();
    
    std::map<std::vector<int>, int>::iterator itr = SC.begin();
    print(itr);
    SC.erase(itr);
    CountUpdate(static_cast<int>(SC.size()));
    
    class_mutex.unlock();
}

void StorageClass::print(int idx) {
    
    if(info() == 0) {
        std::cout << "end of storage reached" << std::endl;
        return;
    }
    
    class_mutex.lock();
    
    std::map<std::vector<int>, int>::iterator itr = SC.begin();
    std::advance(itr, idx % SC.size());
    print(itr);
    SC.erase(itr);
    CountUpdate(static_cast<int>(SC.size()));
    
    class_mutex.unlock();
}

void StorageClass::print(std::map<std::vector<int>, int>::iterator &itr) const {
    
    std::cout << "key: [";
    for(int i=0; i<itr->first.size();) {
        std::cout << itr->first[i];
        if(++i != itr->first.size()) std::cout << ",";
    }
    std::cout << "] value: " << itr->second << std::endl;
}

void StorageClass::populate(int size, int dim) {
    int last = 0;
    std::vector<int> A(dim, 0);
    
    if(size == 0 || dim == 0) return;
    
/*
    calculate the total size
    PDF: size=10, dim=3 --> 1000
 */
    
    CountUpdate(pow(size, dim));
    
    //first key/value
    SC[A] = get_unique_value();
    
    for(int j=0; j<info(); j++) {
        for(int i=static_cast<int>(dim-1); i>=0; i--) {
            last = ++A[i] % (size-1);
            if(last != 1 || (last == 1 && A[i] == 1)) {
                break;
            }
            if(A[i] == size) A[i] = 0x00;
        }
        SC[A] = get_unique_value();
    }
}

//
//  StorageClassB.cpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#include "StorageClassB.hpp"
#include <iostream>

StorageClassB::StorageClassB():StorageClassB(0, 0) {
}

StorageClassB::StorageClassB(int size, int dim) {
    populate(size, dim);
}

void StorageClassB::read(void) {

    if(info() == 0) {
        std::cout << "end of storage reached" << std::endl;
        return;
    }
    
    print(rand() % info());
}

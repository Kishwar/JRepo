//
//  StorageClassA.cpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#include "StorageClassA.hpp"

StorageClassA::StorageClassA():StorageClassA(0, 0) {
}

StorageClassA::StorageClassA(int size, int dim) {
    populate(size, dim);
}

void StorageClassA::read(void) {
    print();
}

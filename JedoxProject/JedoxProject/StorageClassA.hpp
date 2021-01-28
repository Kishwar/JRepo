//
//  StorageClassA.hpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#ifndef StorageClassA_hpp
#define StorageClassA_hpp

#include "StorageClass.hpp"
#include <stdio.h>
#include <vector>
#include <map>

class StorageClassA : public StorageClass {
public:
    StorageClassA();
    StorageClassA(int size, int dim);
    void read(void);
};

#endif /* StorageClassA_hpp */

//
//  StorageClassB.hpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#ifndef StorageClassB_hpp
#define StorageClassB_hpp

#include "StorageClass.hpp"
#include <stdio.h>
#include <vector>
#include <map>

class StorageClassB : public StorageClass {
public:
    StorageClassB();
    StorageClassB(int size, int dim);
    void read(void);
};

#endif /* StorageClassB_hpp */

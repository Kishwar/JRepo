//
//  StorageClass.hpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#ifndef StorageClass_hpp
#define StorageClass_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include <mutex>

class StorageClass {
    int count = 0;
    std::vector<int> uv;
    std::mutex class_mutex;
    int get_unique_value(void);
    void print(std::map<std::vector<int>, int>::iterator &itr) const;
public:
    int info(void);
protected:
    std::map<std::vector<int>, int> SC;
    void CountUpdate(int count);
    void print(void);
    void print(int idx);
    void populate(int size, int dim);
};

#endif /* StorageClass_hpp */

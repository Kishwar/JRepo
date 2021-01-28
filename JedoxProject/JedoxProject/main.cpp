//
//  main.cpp
//  JedoxProject
//
//  Created by Kishwar Kumar on 26.01.21.
//

#include "StorageClassA.hpp"
#include "StorageClassB.hpp"

#include <iostream>
#include <thread>


void exec_StorageClassA(StorageClassA &SCA, std::string str) {
    
    std::cout << str << std::endl;
    
    for(int i=0; i<501; i++) {
        SCA.read();
    }
}
int main(int argc, const char * argv[]) {
    
    StorageClassA SCA(10,3);
    
    std::thread t1(exec_StorageClassA, std::ref(SCA), "thread_1");
    std::thread t2(exec_StorageClassA, std::ref(SCA), "thread_2");
    
    t1.join();
    t2.join();
    
    return 0;
}

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
#include <mutex>

std::mutex main_mutex;

void exec_StorageClassA(StorageClass *SC, std::string str) {
    
    main_mutex.lock();
    std::cout << str << std::endl;
    main_mutex.unlock();
    
    for(int i=0; i<501; i++) {
        main_mutex.lock();
        SC->read();
        main_mutex.unlock();
    }
}
int main(int argc, const char * argv[]) {
    
    StorageClassA SCA(10,3);
    StorageClassA SCB(10,3);
    
    std::thread t1(exec_StorageClassA, &SCA, "thread_1");
    std::thread t2(exec_StorageClassA, &SCA, "thread_2");
    
    std::thread t3(exec_StorageClassA, &SCB, "thread_3");
    std::thread t4(exec_StorageClassA, &SCB, "thread_4");
    
    t1.join();
    t2.join();
    
    t3.join();
    t4.join();
    
    return 0;
}

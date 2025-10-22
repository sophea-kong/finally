#include "./utils/SLL.hpp"
#include "./utils/Csll.hpp"
#include "./utils/DLL.hpp"
#include "./utils/CDLL.hpp"
#include "./utils/nodes.hpp"
#include <iostream>
#include <chrono>

using clk = std::chrono::high_resolution_clock;

int main() {
    auto t0 = clk::now();
    //measure time of allocate sll with 1000 nodes
    
    auto t1 = clk::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << ": " << duration.count() << " micro(s)" << std::endl;

    return 0;
}
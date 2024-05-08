#include <iostream>
#include <memory>

int main() {
    // 使用智能指针管理动态分配的内存
    std::unique_ptr<int> ptr(new int(10));
    std::cout << "Value: " << *ptr << std::endl;
    return 0;
}

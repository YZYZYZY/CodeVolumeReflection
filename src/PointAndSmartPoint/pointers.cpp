#include <iostream>

int main() {
    int x = 10;
    int *p = &x;  // 声明一个整数类型的指针p，并初始化为x的地址

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value at pointer p: " << *p << std::endl;
    std::cout << "Address stored in pointer p: " << p << std::endl;

    // 更改指针p指向的值
    *p = 20;
    std::cout << "New value of x: " << x << std::endl;

    return 0;
}

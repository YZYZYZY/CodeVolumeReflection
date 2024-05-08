// 就是C++程序员能够遇到的内存管理基本上就在这儿了
// 静态常量区、调用栈、堆

#include <cstdio>
#include <cstdint>
#include <memory.h>
#include <cstdlib>

// 静态常量区
const char *textSample1 = "hello,world!";
const char textSample2[] = "hello,world!";
const int VVVV = 0xBEAFBEAF; // 这个是16进制？这个内存地址的写法和电脑的位数有关吗？我们能够操作的最小单位与什么有关？一般是8位

// 定义结构体 结构体与类没有本质区别
struct StructSample
{
    uint32_t uValue; // uint32_t是什么类型？一般什么情况下使用？和int有什么区别？在需要精确控制整数宽度的情况下使用，保证在任何平台上都具有相同的大小（32位）
    float fValue;
    char carr[4];
    short sarr[2];
};
constexpr size_t StructSize = sizeof(StructSample); // 这句代码是什么意思？constexpr 编译时常量 在编译时确定StructSample的大小，编译时计算有助于优化性能，并可用于编译时验证 sizeof 运算符的结果是 size_t

// 定义联合体 联合体与结构体有什么区别？什么情况下用联合体？
union UnionSample
{
    StructSample s;
    uint32_t uarr[4];
};

uint32_t sampleSum(UnionSample _un)
{
    UnionSample u = _un;
    uint32_t s = u.uarr[0] + u.uarr[1] + u.uarr[2] + u.uarr[3];
    return s;
}

void funcAAA(uint32_t _value)
{
    uint32_t v = _value;
    printf("%p\n", &v); //%p是什么输出格式？还有什么其他的输出格式？以十六进制形式输出指针地址
}

void funcBBB(uint32_t _value)
{
    float s = _value;
    printf("%p\n", &s);
}

int main(int _argc, char **_argv)
{ // int _argc, char** _argv这两个参数有什么意义？在什么情况下传入？ _argc：命令行参数的数量  _argv：指向参数字符串数组的指针
    printf("%p\n", textSample1);

    StructSample sSample;                        // sizeof( StructSample ) == 16
    uint32_t arrSample[4];                       // sizeoof(uint32_t) * 4 == 16
    UnionSample uSample;                         // 也是16字节 在所有电脑里面都是8位1字节吗？
    UnionSample *usamplePtr = new UnionSample(); // 同样效果的方法还有 malloc,calloc 等 返回的是指针！

    memcpy(usamplePtr, &sSample, sizeof(StructSample)); // 给一个指针拷贝空间？

    uint32_t sum = sampleSum(*usamplePtr); // 都没有显式初始化啊 为什么最后的总和是8？

    printf("%u\n", sum);
    printf("%p\n %p\n %p\n %p\n %p\n",
           &sSample,
           &arrSample,
           &uSample,
           &usamplePtr,
           &sum);

    // 栈空间 被动分配，被动回收
    funcAAA(64);
    funcBBB(3.1415926f);

    // 变量作用域
    { // funcAAA
        uint32_t v = 64;
        printf("%p\n", &v);
    }
    { // func bbb
        float s = 3.1415926f;
        printf("%p\n", &s);
    }

    // 指针和多级指针
    int a = 5;
    // size_t ptr = (size_t)&a; //这里为什么要强制转换成size_t？
    // size_t pptr = (size_t)&ptr;
    // size_t ppptr = (size_t)&pptr;
    // printf("%d\n%d\n%d\n",
    //     ptr, pptr, ppptr
    // );

    int *ptr = &a;
    int **pptr = &ptr;
    int ***ppptr = &pptr;
    int b = *(*(*ppptr));
    printf("%d\n", b);

    struct MemLayoutSample
    {
        int a;
        int b;
        int c;
        int d;
    };

    MemLayoutSample memSample;
    int intArrSample[4];

    // 使用成员指针获取结构体成员偏移量
    int MemLayoutSample::*memoffset = &MemLayoutSample::a; // 这是什么写法？没有实例化结构体 使用成员指针的例子
    printf("MemLayoutSample data member offsets : \n");    // 使用成员指针获取成员偏移量
    printf("%u\n", memoffset);
    memoffset = &MemLayoutSample::b;
    printf("%u\n", memoffset);
    memoffset = &MemLayoutSample::c;
    printf("%u\n", memoffset);
    memoffset = &MemLayoutSample::d;
    printf("%u\n", memoffset);

    // 使用指针获取成员变量
    int v = memSample.a;
    int *membegin = (int *)&memSample;
    memSample.b = 16;
    int c = *(membegin + 1);
    printf("validate the 'c' == %d\n", c);

    int *pointer = &intArrSample[0];
    MemLayoutSample *memLayoutSamplePtr = (MemLayoutSample *)pointer;
    memLayoutSamplePtr->a = 0;
    memLayoutSamplePtr->b = 1;
    memLayoutSamplePtr->c = 2;
    memLayoutSamplePtr->d = 3;

    printf("array contents : \n");
    printf("%d\n%d\n%d\n%d\n",
           intArrSample[0],
           intArrSample[1],
           intArrSample[2],
           intArrSample[3]);
    //
    uSample;
    //
    union
    {
        size_t offset;
        int MemLayoutSample::*offsetT;
    } offsetu;
    offsetu.offsetT = &MemLayoutSample::b;
    size_t offsetA = offsetu.offset;
    //
    printf("offset b = %ul\n", offsetA);

    return 0;
}

#include <iostream>
using  namespace std;

class Parent
{
public:
    char data[20];
    void Function1();
    virtual void Function2();   // 这里声明Function2是虚函数

}parent;
void Parent::Function1()
{
    printf("This is parent,function1\n");
}
void Parent::Function2()
{
    printf("This is parent,function2\n");
}

class Child:public Parent
{
    void Function1();
    void Function2();

} child;
void Child::Function1()
{
    printf("This is child,function1\n");
}
void Child::Function2()
{
    printf("This is child,function2\n");
}

int main(int argc, char* argv[])
{
    Parent *p;// 定义一个基类指针
    printf("请输入一个字符:");
    if(getchar()=='c')// 如果输入一个小写字母c
        p=&child;// 指向继承类对象
    else
        p=&parent;// 否则指向基类对象
    printf("函数调用情况:\n");
    p->Function1();// 这里在编译时会直接给出Parent::Function1()的入口地址。
    p->Function2();// 注意这里，执行的是哪一个Function2
    return 0;
}

/*
为什么会有第一行的结果呢？
因为我们是用一个Parent类的指针调用函数Fuction1()，虽然实际上这个指针指向的是Child类的对象，但编译器无法知道这一事实（直到运行的时候，程序才可以根据用户的输入判断出指针指向的对象），它只能按照调用Parent类的函数来理解并编译，所以我们看到了第一行的结果。
那么第二行的结果又是怎么回事呢？我们注意到，Function2()函数在基类中被virtual关键字修饰，也就是说，它是一个虚函数。
*/
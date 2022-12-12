/*
将父类的析构函数声明为virtual是为了删除父类指针时可以调用到子类的析构函数
*/

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    Base() {}

    virtual void print()
    {
        cout << "base print" << endl;
    }
    virtual void func() = 0;
   virtual  ~Base()
    {
         cout << "Base 析构" << endl;
    }
};

class Inherit : public Base
{
public:
    Inherit() {}

    void print()
    {
        cout << "Inherit print" << endl;
    }

    virtual void func()
    {
        cout << "Inherit func" << endl;
    }
    ~Inherit()
    {
        cout << "Inherit 析构" << endl;
    }
};
int main()
{
    Base *point = new Inherit();
    point->func();
    point->print();
    delete point;
}
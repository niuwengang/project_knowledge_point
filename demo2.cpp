/*
demo3
std::move() 将对象的状态或者所有权从一个对象转移到另一个对象
只是转移，无内存搬迁或者内存拷贝
move将左值转换为右值引用则可以调用移动构造
均是出于增加效率
*/

#include <bits/stdc++.h>
using namespace std;

class demo
{
public:
    demo()
    {
        ptr = new int(0);

        cout << this << " 默认构造" << endl;
    }

    demo(int x) : ptr(new int(x))
    {
        cout << this << " 有参构造" << endl;
    }

    demo(const demo &obj) : ptr(new int(*obj.ptr))
    {
        cout << this << " 拷贝构造" << endl;
    }
    demo(demo &&obj) : ptr(obj.ptr)
    {
        obj.ptr = nullptr;
        cout << this << " 移动构造" << endl;
    }

    ~demo()
    {
        if (ptr != nullptr)
        {
            delete ptr;
        }

        cout << this << " 析构" << endl;
    }

    int *ptr;
};

int main(int argc, char **argv)
{

    demo s1(10);
    cout << "s1 ptr指向的地址" << &(*s1.ptr) << endl;
    demo s2(s1);
    demo s3(move(s1));
    cout << "s1 ptr指向的地址" << &(*s1.ptr) << endl;

    string str = "just a test";
    vector<string> vec_str;
    vec_str.push_back(str);
    cout << "str is " << str << endl;
    vec_str.push_back(move(str));
    cout << "str is " << str << endl;
}

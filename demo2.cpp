/*
demo2
std::move() 将对象的状态或者所有权从一个对象转移到另一个对象
只是转移，无内存搬迁或者内存拷贝
增加效率,为性能而生
*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    string str = "how to use move ?";
    vector<string> str_vec;

    str_vec.push_back(str);
    cout<<"before move str is:"<<str<<endl;

     str_vec.push_back(move(str));
    cout<<"before move str is:"<<str<<endl;
}
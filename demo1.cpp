/*
demo1
互斥锁保证了每次只有一个线程进行写入操作同一资源
从而保证了多线程情况下数据的正确性
*/

#include <thread>
#include <mutex>
#include <iostream>

int count = 0;

std::mutex mutex_;

void threadTaskWithLock()
{
    const std::lock_guard<std::mutex> lock(mutex_);
    for (int i = 0; i < 1e6; i++)
    {
        count++;
    }
    std::cout << count << std::endl;
}

void threadTaskWithOutLock()
{
    for (int i = 0; i < 1e6; i++)
    {
        count++;
    }
    std::cout << count << std::endl;
}

int main()
{
    std::cout << "使用互排锁" << std::endl;
    std::thread t1(threadTaskWithLock);
    std::thread t2(threadTaskWithLock);
    std::thread t3(threadTaskWithLock);
    t1.join();
    t2.join();
    t3.join();

    count = 0;
    std::cout << "不使用互排锁" << std::endl;
    t1 = std::thread(threadTaskWithOutLock);
    t2 = std::thread(threadTaskWithOutLock);
    t3 = std::thread(threadTaskWithOutLock);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
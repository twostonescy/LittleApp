#pragma once

#include "../common/head.h"

class Sync
{
public:

    /* 读写锁 */
    static shared_mutex lock2;
    static bool b2;

    static void print3()
    {
        lock2.lock_shared();//输出1234
        //lock2.lock();//输出1324
        po("1");
        Sleep(20);

        po("3");
        Sleep(30);

        lock2.unlock_shared();
        //lock2.unlock();//输出1324
    }

    static void print4()
    {
        Sleep(10);
        lock2.lock_shared();
        //lock2.lock();//输出1324
        po("2");
        Sleep(30);
        po("4");

        lock2.unlock_shared();
        //lock2.unlock();//输出1324
    }


    /*两个线程，轮流打印1，2*/

    //方法1：互斥量+一个线程休眠实现
    static mutex lock1;
    static bool b1 ;
    static void print1()
    {
        while (true)
        {
            lock1.lock();
            if (b1)
            {
                b1 = false;
                po("1");
            }
            lock1.unlock();
        }
    }

    static void print2()
    {
        while (true)
        {
            Sleep(1000);
            lock1.lock();
            if (!b1)
            {
                b1 = true;
                po("2");
            }
            lock1.unlock();
        }
    }

    void beginsy()
    {
        thread t1(&Sync::print3);
        thread t2(&Sync::print4);
        t1.join();
        t2.join();
    }

};
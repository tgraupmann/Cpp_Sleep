// Cpp_Sleep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

static int _sCount = 0;

void WorkerThread()
{
    while (true)
    {
        // count in the thread
        ++_sCount;

        // wait in the thread
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread* thread = new std::thread(&WorkerThread);
    thread->detach();

    int lastCount = 0;

    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(0));

        if (lastCount != _sCount)
        {
            auto timenow =
                chrono::system_clock::to_time_t(chrono::system_clock::now());

            char str[26];
            ctime_s(str, sizeof str, &timenow);

            cout << "Thread +" << (_sCount - lastCount) << " " << str;

            lastCount = _sCount;
        }

        this_thread::yield();
    }
}

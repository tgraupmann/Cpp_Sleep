// Cpp_Sleep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    auto timeStart =
        chrono::system_clock::to_time_t(chrono::system_clock::now());

    int count = 0;
    while (true)
    {
        ++count;
        this_thread::sleep_for(chrono::milliseconds(1000));

        auto timenow =
            chrono::system_clock::to_time_t(chrono::system_clock::now());

        char str[26];
        ctime_s(str, sizeof str, &timenow);

        cout << "Count: " << count << " " << str;
    }
}

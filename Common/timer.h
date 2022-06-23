#ifdef _WIN32
#ifndef _TIMER_H
#define _TIMER_H

#include <windows.h>
#pragma comment(lib, "winmm.lib")

class StopWatch
{
 
 private:
     
    LARGE_INTEGER frequency;
    LARGE_INTEGER prevTime, currTime;
    double LIToSecs( LARGE_INTEGER & L) ;
    UINT     wTimerRes;

 public:
     StopWatch() ;
     ~StopWatch();
     void startTimer();
     double getElapsedTime(); // get time in seconds since the last call to this function
     void waitUntil(long long time);  // wait until this time in milliseconds has passed
 };


#endif // _TIMER_H
#elif __linux__

#include <time.h>

class StopWatch
{
    private:
    timespec last, now, elapsed;
    timespec res;
    void GetElapsed(timespec last, timespec now, timespec &delta);

    public:
    StopWatch();
    ~StopWatch();
    void StartTimer();
    timespec TimeSinceStart(); // Returns a variable of type timespec containing the nanoseconds as a long and seconds in int since the start of the timer
    double GetMiliSec();
    void waitUntil(long time);
};

#endif
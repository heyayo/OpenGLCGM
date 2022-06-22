#ifdef _WIN32
#include "timer.h"

StopWatch::StopWatch()
{    
    QueryPerformanceFrequency( &frequency ) ;

    #define TARGET_RESOLUTION 1         // 1-millisecond target resolution
    TIMECAPS tc;
    

    if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR) 
    {
        // Error; application can't continue.
    }

    wTimerRes = min(max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
    timeBeginPeriod(wTimerRes); 
}

StopWatch::~StopWatch()
{
    timeEndPeriod(wTimerRes);
}

double StopWatch::LIToSecs( LARGE_INTEGER & L) {
     return ((double)L.QuadPart /(double)frequency.QuadPart) ;
 }
 
void StopWatch::startTimer( )
{
    QueryPerformanceCounter(&prevTime) ;
}
 
double StopWatch::getElapsedTime() 
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&currTime) ;
    time.QuadPart = currTime.QuadPart - prevTime.QuadPart;
    prevTime = currTime;
    return LIToSecs( time) ;
}

void StopWatch::waitUntil(long long time)
{
    LARGE_INTEGER nowTime;
    LONGLONG timeElapsed;
    while (true)
    {
        QueryPerformanceCounter(&nowTime);
        timeElapsed = ((nowTime.QuadPart - prevTime.QuadPart) * 1000 / frequency.QuadPart);
        if (timeElapsed > time)
            return;
        else if (time - timeElapsed > 1)
            Sleep(1);
    }
}

#elif __linux__
#include "timer.h"

StopWatch::StopWatch()
{
    clock_getres(CLOCK_MONOTONIC, &res); // Get the Resolution of the Clock
}

StopWatch::~StopWatch() {}

void StopWatch::StartTimer()
{
    clock_gettime(CLOCK_MONOTONIC, &last);
}

timespec StopWatch::TimeSinceStart()
{
    clock_gettime(CLOCK_MONOTONIC, &now);
    GetElapsed(last, now, elapsed);
    return elapsed;
}

void StopWatch::GetElapsed(timespec last, timespec now, timespec &delta)
{
    delta.tv_nsec = now.tv_nsec - last.tv_nsec;
    delta.tv_sec = now.tv_sec - last.tv_sec;
}

void StopWatch::waitUntil(long time)
{
    time = time * 1000;
    timespec NowTime;
    timespec LastTime;
    clock_gettime(CLOCK_MONOTONIC, &LastTime);
    long ElaspedTime;
    while (true)
    {
        clock_gettime(CLOCK_MONOTONIC, &NowTime);
        ElaspedTime = NowTime.tv_nsec - LastTime.tv_nsec;
        if (ElaspedTime > time)
            return;
    }
}

double StopWatch::GetMiliSec()
{
    return TimeSinceStart().tv_nsec / 1000;
}

#endif
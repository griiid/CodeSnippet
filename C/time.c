#include <stdarg.h>
#include <sys/time.h>
#include <time.h>
#include <sys/timeb.h>

unsigned long long time_ms(void) {
    // get current time
    struct timeval tv;
    gettimeofday(&tv, NULL);
    // convert to millisecond
    return tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL;
}

// The timeFormat can check this page: http://www.cplusplus.com/reference/ctime/strftime/
// It explains how to use the function strftime.
void print_current_time(const char *timeFormat = "%T", bool printNewLine = false) {
    struct timeb stTimeb;
    ftime(&stTimeb);

    struct tm *stTm = localtime(&stTimeb.time);

    char caTimeStamp[40];
    strftime(caTimeStamp, sizeof(caTimeStamp), timeFormat, stTm);
    printf("%s.%03d%s", caTimeStamp, stTimeb.millitm, printNewLine ? "\n" : "");
}
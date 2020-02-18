#include <sys/time.h>

unsigned long long time_ms(void) {
    // get current time
    struct timeval tv;
    gettimeofday(&tv, NULL);
    // convert to millisecond
    return tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL;
}

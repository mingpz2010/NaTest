#ifndef _MY_TIME_H_
#define _MY_TIME_H_     1

#include <cstdint>
#include <ctime>
#include <sys/time.h>
#ifdef __linux__
    #include <asm/unistd.h>
#endif

#if defined(__GNUC__) || defined(__GNUG__)
static inline uint64_t my_now(void)    __attribute__((always_inline));
#else
static inline uint64_t my_now(void);
#endif
static inline uint64_t my_now(void)
{
#if defined(__x86_64)
    uint32_t t_low, t_high;
    __asm__ __volatile__("rdtsc":"=a"(t_low),"=d"(t_high));

    return (uint64_t)t_high << 32 | t_low;
#elif defined(__aarch64__)
    uint64_t t;
    __asm__ __volatile__("mrs %0, cntvct_el0" : "=r" (t));
    return t;
#endif
}

#if defined(__GNUC__) || defined(__GNUG__)
static inline uint64_t my_us_gettimeofday(void)    __attribute__((always_inline));
#else
static inline uint64_t my_us_gettimeofday(void);
#endif
static inline uint64_t my_us_gettimeofday(void)
{
    struct timeval t;
    gettimeofday(&t, NULL);

    return t.tv_sec * 1000000ULL + t.tv_usec;
}

#if defined(__GNUC__) || defined(__GNUG__)
static inline uint64_t my_us_clockgettime(void)    __attribute__((always_inline));
#else
static inline uint64_t my_us_clockgettime(void);
#endif
static inline uint64_t my_us_clockgettime(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);

    return t.tv_sec * 1000000000ULL + t.tv_nsec;
}

#endif

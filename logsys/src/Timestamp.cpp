#include "Timestamp.hpp"
#include <sys/time.h>
#include <stdio.h>
#include <time.h>
namespace logsys {
    const int Buffsize = 128;
    Timestamp::Timestamp() : microSec(0) {}
    Timestamp::Timestamp(const int64_t ms) : microSec(ms) {}
    Timestamp::~Timestamp() {}
    void Timestamp::swap(Timestamp& other) {
        std::swap(microSec, other.microSec);
    }
    bool Timestamp::vaild() const {
        return microSec > 0;
    }
    std::string Timestamp::toString() const {
        char buff[Buffsize] = {0};
        return std::string(buff);
    }
    std::string Timestamp::toFormattedString(bool showMic) const {
        char buff[Buffsize] = {0};
        time_t second = microSec / kMicroSecPerSecond;
        int micsec = microSec % kMicroSecPerSecond;
        struct tm time;
        localtime_r(&second,&time); //本地时间
        //gmtime_r(&second,&time); //格林尼治时间
        sprintf(buff,"%04d/%02d/%02d %02d:%02d:%02d.%d",time.tm_year + 1900,time.tm_mon + 1,time.tm_mday,time.tm_hour,time.tm_min,time.tm_sec,micsec);
        return std::string(buff);
    }
    std::string Timestamp::toFileString() const {
        char buff[Buffsize] = {0};
        time_t second = microSec / kMicroSecPerSecond;
        int micsec = microSec % kMicroSecPerSecond;
        struct tm time;
        localtime_r(&second,&time); //本地时间
        //gmtime_r(&second,&time); //格林尼治时间
        sprintf(buff,"%04d%02d%02d-%02d%02d%02d.%d",time.tm_year + 1900,time.tm_mon + 1,time.tm_mday,time.tm_hour,time.tm_min,time.tm_sec,micsec);
        return std::string(buff);
    }
    int64_t Timestamp::getMicroSec() const {
        return microSec;
    }
    time_t Timestamp::getSeconds() const {
        return static_cast<time_t>(microSec / kMicroSecPerSecond);
    }
    Timestamp Timestamp::Now() { // 获取当前时间戳
        struct timeval time;
        gettimeofday(&time,NULL);
        int64_t micro = time.tv_sec*kMicroSecPerSecond + time.tv_usec;
        return Timestamp(micro);
    }
    Timestamp Timestamp::invalid() { // 获取一个无效的时间戳
        return Timestamp();
    }
}
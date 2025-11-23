#include <stdint.h>
#include <string>

#ifndef LOGSYS_TIMESTAMP_HPP
#define LOGSYS_TIMESTAMP_HPP

namespace logsys {
    class Timestamp {
    private:
        int64_t microSec; // 从 1970年1月1日 00:00:00 到现在的微秒数
    public:
        Timestamp();
        Timestamp(const int64_t ms);
        ~Timestamp();
        void swap(Timestamp& other);
        bool vaild() const;
        std::string toString() const; // 格式: 秒[.微秒]
        std::string toFormattedString(bool showMic = true) const; // 格式: YYYY/MM/DD HH:MM:SS[.微秒]
        std::string toFileString() const; // 格式: YYYYMMDD-HHMMSS[.微秒]
        int64_t getMicroSec() const;
        time_t getSeconds() const;
    public:
        static const int kMicroSecPerSecond = 1000*1000; // 每秒的微秒数
        static Timestamp Now(); // 获取当前时间戳
        static Timestamp invalid(); // 获取一个无效的时间戳
    };
}
#endif // LOGSYS_TIMESTAMP_HPP
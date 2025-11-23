#include <stdint.h>
#include <string>

#ifndef LOGSYS_TIMESTAMP_HPP
#define LOGSYS_TIMESTAMP_HPP

namespace logsys {
    /**
     * @brief 时间戳类
     * 封装了微秒级的时间戳，提供获取当前时间、格式化输出等功能。
     * 内部使用 int64_t 存储从 1970-01-01 00:00:00 UTC 开始的微秒数。
     */
    class Timestamp {
    private:
        int64_t microSec; // 从 1970年1月1日 00:00:00 到现在的微秒数
    public:
        /**
         * @brief 默认构造函数
         * 创建一个无效的时间戳（microSec = 0）
         */
        Timestamp();

        /**
         * @brief 构造函数
         * @param ms 微秒数
         */
        Timestamp(const int64_t ms);

        /**
         * @brief 析构函数
         */
        ~Timestamp();

        /**
         * @brief 交换两个 Timestamp 对象
         * @param other 另一个 Timestamp 对象
         */
        void swap(Timestamp& other);

        /**
         * @brief 判断时间戳是否有效
         * @return true 有效 (microSec > 0)
         * @return false 无效
         */
        bool vaild() const;

        /**
         * @brief 转换为字符串
         * @return std::string 格式: 秒[.微秒]
         */
        std::string toString() const;

        /**
         * @brief 转换为格式化字符串
         * @param showMic 是否显示微秒部分
         * @return std::string 格式: YYYY/MM/DD HH:MM:SS[.微秒]
         */
        std::string toFormattedString(bool showMic = true) const;

        /**
         * @brief 转换为适合文件名的字符串
         * @return std::string 格式: YYYYMMDD-HHMMSS[.微秒]
         */
        std::string toFileString() const;

        /**
         * @brief 获取微秒数
         * @return int64_t
         */
        int64_t getMicroSec() const;

        /**
         * @brief 获取秒数
         * @return time_t
         */
        time_t getSeconds() const;

    public:
        static const int kMicroSecPerSecond = 1000*1000; // 每秒的微秒数

        /**
         * @brief 获取当前时间戳
         * @return Timestamp 当前时间
         */
        static Timestamp Now();

        /**
         * @brief 获取一个无效的时间戳
         * @return Timestamp 无效时间戳
         */
        static Timestamp invalid();
    };
}
#endif // LOGSYS_TIMESTAMP_HPP
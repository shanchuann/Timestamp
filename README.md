# Timestamp 时间戳

一个轻量级的C++时间戳处理工具，提供时间戳的获取、格式化输出等功能，可用于日志系统、文件命名等场景中需要时间信息的地方。

> **格式化输出**
> `int a = 10,b = 20; printf("a = %d b = %d",a,b);`
>
> `OUTPUT: a = 10 b = 20`
>
> `char buff[128]; sprintf(buff,"a = %d b = %d",a,b);`
>
> `buff -> |a_=_10_b_=_20|` (用下划线代替空格)

## 功能特点

- 支持获取当前时间戳（精确到微秒）
- 提供多种时间格式化方式：
  
  标准格式化字符串（格式：`YYYY/MM/DD HH:MM:SS.微秒`）
  
  文件友好型字符串（格式：`YYYYMMDD-HHMMSS.微秒`）
- 支持时间戳有效性判断
- 提供时间戳的微秒级和秒级数值获取
- **跨平台支持**：支持 Windows 和 Linux 系统

## 文件结构

```txt
Timestamp/
├── logsys/
│   ├── include/
│   │   └── Timestamp.hpp    // 时间戳类头文件（声明）
│   └── src/
│       └── Timestamp.cpp    // 时间戳类实现文件
├── Timestamp.cpp            // 测试程序，演示Timestamp的使用
└── CMakeLists.txt          // CMake构建配置文件
```

## 编译与运行

### 编译步骤

1. 确保已安装CMake（版本≥3.10）和C++编译器（如g++或MSVC）
2. 在项目根目录创建构建目录(若没有)并进入：

   ```bash
   mkdir build && cd build
   ```

3. 配置项目：

   ```bash
   cmake ..
   ```

4. 编译项目：

   **Linux / macOS:**

   ```bash
   make
   ```

   **Windows:**

   ```powershell
   cmake --build .
   ```

   编译完成后，可执行文件`Timestamp`将生成在`bin`目录下（Windows下通常在`bin/Debug/`）。

### 运行测试

**Linux / macOS:**

```bash
./bin/Timestamp
```

**Windows:**

```powershell
.\bin\Debug\Timestamp.exe
```

运行后将输出类似以下内容（具体时间取决于运行时的系统时间）：

```txt
2025/11/23 17:45:09.812002
20251123-174509.812002
```

## 使用示例

以下是`Timestamp.cpp`中的核心使用示例，展示了Timestamp的基本用法：

```cpp
#include "Timestamp.hpp"
#include <iostream>
int main()
{
    // 获取当前时间戳
    logsys::Timestamp test = logsys::Timestamp::Now();
    // 输出标准格式化字符串
    std::cout << test.toFormattedString() << std::endl;
    // 输出文件友好型字符串
    std::cout << test.toFileString() << std::endl;
}
```

## 类方法说明

| 方法名                 | 功能描述                                                                 |
|------------------------|--------------------------------------------------------------------------|
| `Timestamp::Now()`     | 静态方法，返回当前时间的Timestamp对象（微秒级精度）                       |
| `Timestamp::invalid()` | 静态方法，返回一个无效的Timestamp对象（微秒数为0）                       |
| `vaild()`              | 判断时间戳是否有效（微秒数>0则有效）                                     |
| `toFormattedString()`  | 返回格式化字符串，格式为`YYYY/MM/DD HH:MM:SS.微秒`                       |
| `toFileString()`       | 返回适合作为文件名的时间字符串，格式为`YYYYMMDD-HHMMSS.微秒`              |
| `getMicroSec()`        | 返回时间戳的微秒级数值（从1970年1月1日00:00:00到当前的微秒数）           |
| `getSeconds()`         | 返回时间戳的秒级数值（从1970年1月1日00:00:00到当前的秒数，向下取整）     |
| `swap()`               | 交换两个Timestamp对象的时间戳数据                                         |

## 注意事项

- 时间计算基于Unix时间戳（起始时间为1970年1月1日00:00:00 UTC）
- 目前使用`localtime_r`（Linux）或 `localtime_s`（Windows）获取本地时间，若需要UTC时间，可修改源码中相关函数为`gmtime_r`
- Linux系统依赖`gettimeofday`，Windows系统使用`std::chrono`
- 微秒部分输出长度可能因系统时间精度略有差异，通常为6位数字

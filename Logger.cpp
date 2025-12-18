#include "Logger.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

namespace security
{
    Logger::Logger(const filesystem::path& logFile)
        : m_logFile(logFile)
    {
    }

    void Logger::log(const string& message)
    {
        lock_guard<std::mutex> lock(m_mutex);

        ofstream file(m_logFile, ios::app);
        if (!file) return;

        // Get current time
        auto now = chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);

        tm tm_info;
        localtime_s(&tm_info, &t);  // ✅ Thread-safe version

        file << std::put_time(&tm_info, "%Y-%m-%d %H:%M:%S") << " | " << message << endl;

        // Optional: also print to console
        std::cout << message << std::endl;
    }
}

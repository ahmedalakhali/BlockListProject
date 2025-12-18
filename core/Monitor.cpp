#include "Monitor.h"
#include "Scanner.h"
#include <windows.h>
#include <thread>
#include <iostream>
#include <chrono>
#include <filesystem>
using namespace std;

namespace security
{
    void monitor_folder(const filesystem::path& folder, Scanner& scanner)
    {
        //  directory handle
        HANDLE hDir = CreateFile(
            folder.wstring().c_str(),
            FILE_LIST_DIRECTORY,
            FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
            nullptr,
            OPEN_EXISTING,
            FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
            nullptr
        );

        if (hDir == INVALID_HANDLE_VALUE)
        {
            cerr << "Failed to open directory handle for monitoring\n";
            return;
        }

        char buffer[1024];
        DWORD bytesReturned;

        cout << "Monitoring folder in real-time...\n";

        while (true)
        {
            BOOL result = ReadDirectoryChangesW(
                hDir,
                buffer,
                sizeof(buffer),
                TRUE,
                FILE_NOTIFY_CHANGE_FILE_NAME |
                FILE_NOTIFY_CHANGE_SIZE |
                FILE_NOTIFY_CHANGE_LAST_WRITE,
                &bytesReturned,
                nullptr,
                nullptr
            );

            if (result)
            {
                //  only scan when changes happen
                scanner.scan_all();
            }

            // to  sleep the process so that to avoid CPU overuse
            this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        CloseHandle(hDir);
    }
}

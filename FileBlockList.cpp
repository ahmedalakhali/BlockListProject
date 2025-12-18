#include "Hasher.h"
#include "Blocklist.h"
#include "Logger.h"
#include "Scanner.h"
#include "Monitor.h"
#include <filesystem>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

namespace fs = filesystem;

int main()
{
    fs::path folderPath = "files";

    security::Blocklist blocklist("blocklist.txt");
    security::Logger logger("log.txt");
    security::Scanner scanner(folderPath, blocklist, logger);

    scanner.scan_all();

    thread([&scanner, &folderPath]()
        {
            security::monitor_folder(folderPath, scanner);
        }).detach();

    thread([&scanner]()
        {
            while (true)
            {
                this_thread::sleep_for(std::chrono::seconds(60));
                scanner.scan_all();
            }
        }).detach();

    cout << "Folder monitoring + periodic scan running...\n";
    while (true)
        this_thread::sleep_for(std::chrono::seconds(60));
}

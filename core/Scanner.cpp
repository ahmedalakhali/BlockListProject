#include "Scanner.h"
#include "Hasher.h"
#include <iostream>
using namespace std;

namespace security
{
    Scanner::Scanner(const filesystem::path& folder, Blocklist& blocklist, Logger& logger)
        : m_folder(folder), m_blocklist(blocklist), m_logger(logger)
    {
    }

    void Scanner::scan_file(const filesystem::path& file)
    {
        string hash = sha256_file(file);
        if (hash.empty()) return;

        cout << "HASH(\"" << file.filename() << "\") = " << hash << " ";

        if (m_blocklist.contains(hash))
        {
            cout << "[BLOCKED]\n";
            m_logger.log("[BLOCKED] " + file.filename().string());
            filesystem::remove(file);
        }
        else
        {
            cout << "[OK]\n";
            m_logger.log("[OK] " + file.filename().string());
        }
    }

    void Scanner::scan_all()
    {
        if (!filesystem::exists(m_folder))
        {
            cout << "Folder does not exist!\n";
            return;
        }

        for (const auto& entry : filesystem::directory_iterator(m_folder))
        {
            if (filesystem::is_regular_file(entry))
                scan_file(entry.path());
        }
    }
}

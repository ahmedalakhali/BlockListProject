# BlockListProject

A program developed to automatically detect and remove blocked files from a designated folder named files.
The program is implemented in C++ and makes use of Windows data types (typedefs) and Windows API functions, including ReadDirectoryChangesW and CreateFileW, to enable real-time file system monitoring.
The program uses the OpenSSL library to compute SHA-256 hashes of files. Each file detected in the monitored folder is scanned, its hash is calculated, and then compared against a predefined blocklist.
If a matching hash is found, the file is immediately deleted.
The utility continuously monitors the folder in real time, ensuring that any blocked or malicious files are removed as soon as they appear.  


# FileBlockList

<!-- Replace OWNER/REPO in the badge URL with your GitHub owner and repo -->
![Windows Build](https://github.com/OWNER/REPO/actions/workflows/windows-build.yml/badge.svg)

Lightweight Windows C++ utility to monitor a folder and detect files whose SHA-256 hashes appear in a blocklist.

---

## Fastest way to run the project

- Open Visual Studio updated version with "Desktop development with C++" workload
- Go to Git in Visual Studio
- Clone Repository
- Copy the project URL 
---

## Requirements

- Visual Studio 2019 / 2022 with "Desktop development with C++" workload (or MSVC toolchain)
- OpenSSL development libraries (the project uses OpenSSL for SHA-256)
---

## Recommended: Install OpenSSL 

- Go to (https://sourceforge.net/projects/openssl-for-windows/) and click install









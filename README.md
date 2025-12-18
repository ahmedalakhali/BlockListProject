# BlockListProject

## Overview

BlockListProject is a C++ utility program **monitors a folder named `files` in real time** and automatically **detects and deletes blocked files**. It uses **Windows APIs** for file system monitoring and **OpenSSL** to compute **SHA-256 hashes**, which are compared against a predefined blocklist.

If a file’s hash matches the blocklist, the file is **immediately removed**.

---

## Key Features

* Real-time folder monitoring (`files` directory)
* SHA-256 hash scanning using OpenSSL
* Automatic deletion of blocked or malicious files
* High-performance, Windows-native implementation

---

## Technologies Used

* **C++ (C++11 / C++17)**
* **Windows API** (`ReadDirectoryChangesW`, `CreateFileW`)
* **OpenSSL** (SHA-256 hashing)
* Standard libraries: `<filesystem>`, `<thread>`, `<windows.h>`

---

## Requirements

* **Visual Studio 2019 or 2022**
* **Desktop development with C++** workload (MSVC toolchain)
* **OpenSSL development libraries**

---

## Fastest Way to Run

1. Open **Visual Studio** (updated version)
2. Ensure **Desktop development with C++** workload is installed
3. Open **Git** → **Clone Repository**
4. Paste the project repository URL and clone
5. Build and run the project

---

## OpenSSL Installation (Recommended)

* Download OpenSSL for Windows from SourceForge
* Install the development libraries
* Ensure OpenSSL include and lib paths are configured in Visual Studio

---

## Notes

* The monitored folder must be named **`files`**
* The application runs continuously to ensure immediate file removal


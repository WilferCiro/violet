# Violet — HTTP and GraphQL Client (C++ / GTK4)

**Violet** is a graphical client (GUI) for HTTP and GraphQL written in **C++** using **GTK4**... ADD MORE

---

## ✨ Features

- Native GTK4 graphical interface
- Send HTTP requests
- Send Graphql requests
- Configure endpoint and request headers (via UI or environment variable)
- Open-source and simple to build with **CMake**

---

## 📁 Project structure

- `CMakeLists.txt` — build configuration
- `src/` — C++ source code
- `ui/` — UI files (e.g. `mainwindow.ui`)
- `resources/` — assets, icons, GResource
- `tests/` — test cases (if present)

---

## 🧩 Requirements

- C++ compiler with C++17 support (gcc/clang/MSVC)
- CMake ≥ 3.16
- **GTK4** development files / headers
- libcurl or another HTTP client library
- JSON library (e.g. `nlohmann/json`)
- `pkg-config` (recommended)

---

## 🔧 Build & Run

Follow the instructions for your platform.

### Linux (Debian/Ubuntu)

Install dependencies (example for Debian/Ubuntu):

```bash
sudo apt update
sudo apt install -y build-essential cmake pkg-config libgtk-4-dev libglib2.0-dev libcurl4-openssl-dev
```

Build and run:

```bash
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j$(nproc)
# Run the binary (usually ./violet)
./violet
```

### Fedora

```bash
sudo dnf install @development-tools cmake pkgconfig gtk4-devel libcurl-devel
```

### Arch Linux

```bash
sudo pacman -Syu base-devel cmake pkg-config gtk4 curl
```

### macOS (Homebrew)

```bash
brew update
brew install cmake pkg-config gtk4 libcurl
# Build
mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j$(sysctl -n hw.ncpu)
./violet
```

> Note: Install Xcode Command Line Tools if needed: `xcode-select --install`.

### Windows (MSYS2 / MinGW-w64) — recommended

1. Install MSYS2: https://www.msys2.org/
2. Open the *MSYS2 MinGW 64-bit* shell and install packages:

```bash
pacman -Syu
pacman -S mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-gtk4 mingw-w64-x86_64-libcurl mingw-w64-x86_64-pkg-config
```

3. Build:

```bash
mkdir build && cd build
cmake -G "MSYS Makefiles" -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j
./violet.exe
```

Alternative (Visual Studio + vcpkg):

- Install dependencies via `vcpkg`: `vcpkg install gtk4 libcurl nlohmann-json`
- Use vcpkg's toolchain with `-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake`

---

## 📝 License

This project is **open source**. A permissive license such as **MIT** is recommended — add a `LICENSE` file at the repository root.

---

## 🆘 Support

- Open an issue for bugs and feature requests
- Pull requests are welcome 👍

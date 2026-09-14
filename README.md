# Fibonacci C++ Project

WSL2 + VS Code + CMake + GoogleTest 기반의 Fibonacci 예제 프로젝트입니다.

## Features

- C++20 concept 기반 정수 타입 제한
- 헤더 전용 템플릿 구조
- GoogleTest 기반 테스트
- CMakePresets로 Debug / Release 분리

## Project Structure

```text
.
├─ CMakeLists.txt
├─ CMakePresets.json
├─ fibonacci.hpp
├─ main.cpp
├─ test.cpp
└─ .gitignore
```

## Requirements

- CMake 3.23+
- C++20 compiler
- Ninja
- WSL2 Ubuntu or compatible Linux environment

## Build

### Debug

```bash
cmake --preset debug
cmake --build --preset debug
```

### Release

```bash
cmake --preset release
cmake --build --preset release
```

## Run

```bash
./build/debug/hello 10
```

## Test

```bash
ctest --test-dir build/debug
```

## Notes

- `Fibonacci<double>` 같은 비정수 타입은 concept으로 컴파일 단계에서 차단됩니다.
- `FetchContent`로 GoogleTest를 내려받아 테스트를 구성합니다.

## GitHub Upload

원격 저장소 예시:

```bash
git remote add origin https://github.com/populous/fibonacci.git
git branch -M main
git push -u origin main
```

이미 `origin`이 있으면 아래처럼 바꿉니다.

```bash
git remote set-url origin https://github.com/populous/fibonacci.git
```

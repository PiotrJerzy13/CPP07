
# 🧩 C++ Module 07 – Templates

This module introduces **C++ templates**, covering **function templates**, **function pointers in templates**, and **class templates**.

You will:
✅ Write **generic functions** (`swap`, `min`, `max`)
✅ Implement a **template function that applies an operation to each element of an array**
✅ Create a **dynamic, bounds-checked array class** template

---

## 📌 Table of Contents

* [Overview](#overview)
* [Project Structure](#project-structure)
* [Exercises](#exercises)

  * [ex00 – Basic Function Templates](#ex00--basic-function-templates)
  * [ex01 – iter](#ex01--iter)
  * [ex02 – Array Class Template](#ex02--array-class-template)
* [Build & Run](#build--run)
* [Example Usage](#example-usage)
* [Key Concepts Learned](#key-concepts-learned)
* [License](#license)

---

## ✅ Overview

* **Language:** C++17
* **Core concepts:**

  * Function templates & template specialization
  * Passing function pointers as template arguments
  * Class templates & dynamic memory
  * Bounds-checking with exceptions
  * Const-correctness in templates

We’ll use **modern C++17 features** (e.g., `nullptr`, `constexpr`, structured bindings) for clarity and safety.

---

## 📂 Project Structure

```
📦 cpp_module_07/
 ├── ex00/
 │   ├── whatever.hpp   # swap, min, max templates
 │   ├── main.cpp
 │   └── Makefile
 ├── ex01/
 │   ├── iter.hpp       # generic iter() function template
 │   ├── main.cpp
 │   └── Makefile
 ├── ex02/
 │   ├── Array.hpp      # class template Array<T>
 │   ├── Array.tpp      # optional template definitions
 │   ├── main.cpp
 │   └── Makefile
 └── README.md
```

---

## 📝 Exercises

### **ex00 – Basic Function Templates**

Implement:

```cpp
template<typename T>
void swap(T& a, T& b);

template<typename T>
const T& min(const T& a, const T& b);

template<typename T>
const T& max(const T& a, const T& b);
```

They must work with **any type supporting comparison operators**.

Example usage:

```cpp
int a = 2, b = 3;
::swap(a, b);
std::cout << "a = " << a << ", b = " << b << '\n';
std::cout << "min(a, b) = " << ::min(a, b) << '\n';
std::cout << "max(a, b) = " << ::max(a, b) << '\n';

std::string x = "chaine1", y = "chaine2";
::swap(x, y);
std::cout << "x = " << x << ", y = " << y << '\n';
std::cout << "min(x, y) = " << ::min(x, y) << '\n';
std::cout << "max(x, y) = " << ::max(x, y) << '\n';
```

Expected output:

```
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
x = chaine2, y = chaine1
min(x, y) = chaine1
max(x, y) = chaine2
```

---

### **ex01 – iter**

Implement a **generic iter() function**:

```cpp
template<typename T, typename F>
void iter(T* array, size_t length, F func);
```

* `array` → pointer to an array
* `length` → number of elements
* `func` → function to apply to each element

It should work with:
✅ Non-const arrays
✅ Const arrays

Example usage:

```cpp
template<typename T>
void printElement(const T& elem) { std::cout << elem << " "; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printElement<int>);
}
```

Output:

```
1 2 3 4 5
```

---

### **ex02 – Array Class Template**

Create a **template class Array<T>** that mimics a minimal dynamic array with bounds checking:

```cpp
template<typename T>
class Array {
public:
    Array();                          // empty array
    explicit Array(unsigned int n);   // array of size n
    Array(const Array& other);        // copy constructor
    Array& operator=(const Array& other); // copy assignment
    ~Array();                         // destructor

    T& operator[](unsigned int index);       // access with bounds check
    const T& operator[](unsigned int index) const;
    unsigned int size() const;        // number of elements

private:
    T* _data;
    unsigned int _size;
};
```

* Must throw `std::out_of_range` if an invalid index is accessed.
* Copying must **deep copy** (changes to one array must not affect the other).

Example usage:

```cpp
int main() {
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); ++i)
        numbers[i] = i * 10;

    try {
        std::cout << numbers[2] << '\n'; // valid
        std::cout << numbers[10] << '\n'; // throws exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}
```

---

## 🛠 Build & Run

### Build

Inside any exercise folder:

```bash
make
```

### Run

```bash
./whatever
./iter
./array
```

For **C++17**, your Makefile should include:

```make
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
```

---

## ▶ Example Usage

```cpp
#include "Array.hpp"
#include "iter.hpp"
#include "whatever.hpp"

int main() {
    // ex00
    int a = 42, b = 99;
    ::swap(a, b);
    std::cout << "min = " << ::min(a, b) << ", max = " << ::max(a, b) << '\n';

    // ex01
    std::string strs[] = {"one", "two", "three"};
    iter(strs, 3, [](const std::string& s) { std::cout << s << "\n"; });

    // ex02
    Array<double> arr(3);
    arr[0] = 3.14; arr[1] = 2.71; arr[2] = 1.61;
    std::cout << "Array size: " << arr.size() << '\n';
}
```

---

## 🌟 Key Concepts Learned

* ✅ **Function templates** with generic arguments
* ✅ Passing **function pointers/lambdas** into template functions
* ✅ **Class templates** with deep copy & exception safety
* ✅ **Const-correctness** in templates
* ✅ **Bounds checking with exceptions**

---

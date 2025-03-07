# ConsoleStream

**ConsoleStream** is a lightweight, **single-header**, and **C++98-compatible** library that makes it easy to enhance console-based applications using ANSI escape codes. It provides simple yet powerful utilities for styling and formatting text with colors, effects, and backgrounds, all while integrating seamlessly with C++ streams (`std::ostream`).

---

## Features

- **Single-Header Library**: No installation required—just include the header file in your project.
- **C++98 Compatible**: Fully compatible with older and legacy systems.
- **Color Support**: Apply foreground and background colors with predefined palettes or custom RGB values.
- **Text Effects**: Add styles like **bold**, **italic**, **underline**, **blink**, and more.
- **Custom Styling Options**: Create unique styles with custom 24-bit RGB colors or 256 indexed palettes.
- **Stream Integration**: Works natively with `std::ostream` for seamless integration with standard C++ streams.
- **State Management**: Manage and restore console text styles easily.

---

## How It Works

### Core Components

1. **`ANSICode`**:
   - The foundation for adding ANSI codes for colors and effects.
   - Supports predefined colors (`red`, `green`, `blue`, etc.) and custom definitions (`rgb(r, g, b)`).

2. **Color Namespaces**:
   - **Foreground Colors**: `ktd::color` includes colors like `red`, `green`, `bright_red`, etc.
   - **Background Colors**: `ktd::background` applies backgrounds (e.g., `background::blue`).
   - **Custom Colors**: Use `palette(index)` or `rgb(r, g, b)` for more specific colors.

3. **Style Effects**:
   - `ktd::effect` enables styles like `bold`, `underline`, `italic`, and more for enhanced text formatting.

4. **Console State Management**:
   - Use the `ConsoleState` class to combine text foreground, background, and effects into reusable states.

5. **Stream Compatibility**:
   - All colors and effects are integrated into `std::ostream`, making them easy to use with `std::cout`.

---

## Installation

### Option 1: FetchContent (Recommended)
1. Add the following to your `CMakeLists.txt` to fetch the library:
   ```cmake
   include(FetchContent)
   FetchContent_Declare(
       ConsoleStream
       GIT_REPOSITORY https://github.com/kaniteru/CPP-ConsoleStream
       GIT_TAG main
   )
   FetchContent_MakeAvailable(ConsoleStream)
   ```
2. Link the library to your target:
   ```cmake
   target_link_libraries(MyProject PRIVATE ConsoleStream)
   ```

### Option 2: Manual
1. Clone the repository or download the source files:
   ```bash
   git clone https://github.com/kaniteru/CPP-ConsoleStream
   ```
2. Add the `include` directory to your project manually or with CMake:
   ```cmake
   target_include_directories(MyExecutable PRIVATE path/to/clone/include)
   ```

### Usage
1. Include the library header in your code:
   ```cpp
   #include "kani/console_stream.hpp"
   ```
2. Enable Virtual Terminal (Windows only):
   ```cpp
   ktd::enable_virtual_terminal();
   ```

---

## Example Code

```cpp
#include <iostream>
#include "console_stream.hpp"

int main() {
#ifdef _WIN32
    ktd::enable_virtual_terminal(); // Enable ANSI on Windows
#endif

    using namespace ktd;

    // Example with predefined colors and effects
    std::cout << color::red << effect::bold
              << "This is bold red text"
              << background::yellow << " with a yellow background"
              << endl;

    // Example with custom RGB colors
    std::cout << color::rgb(128, 0, 128) 
              << "Text in custom purple color" 
              << endl;

    // Example with palettes
    std::cout << color::palette(2) << background::palette(220)
              << "Text in dark green on a light yellow background"
              << endl;

    return 0;
}
```

### Result
The above code will produce styled terminal output like:

- Bold red text on a yellow background
- Custom text in a purple RGB color
- Dark green text on a light yellow background

---

## Compatibility

- **C++ Standard**: Compatible with C++98 and newer, ensuring broad support for older systems and compilers.
- **Platforms**: Supports most Unix-like systems and Windows consoles (with `virtual terminal` enabled).

---

## License

This project is released under the MIT License. See the [LICENSE](LICENSE) file for details.

---

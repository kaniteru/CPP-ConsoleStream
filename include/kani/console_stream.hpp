#ifndef KANITERU_CONSOLE_STREAM_HPP
#define KANITERU_CONSOLE_STREAM_HPP
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#ifdef _WIN32
    #include <windows.h>
#endif //_WIN32

#ifdef _MSVC_LANG
    #define KANI_CXX_VER _MSVC_LANG
#else
    #define KANI_CXX_VER __cplusplus
#endif //_MSVC_LANG

#define KANI_CXX17 201703L

#if KANI_CXX_VER >= KANI_CXX17
    #define KTD_INLINE_VARIABLE inline
#else
    #define KTD_INLINE_VARIABLE static
#endif

namespace ktd {

#ifdef _WIN32
/**
 * @brief Enables virtual terminal processing for the Windows console.
 */
inline
void enable_virtual_terminal() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;

    if (GetConsoleMode(hConsole, &mode)) {
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hConsole, mode);
    }
}
#endif //_WIN32

// ======================== C L A S S ========================
// ===    ANSICode
// ======================== C L A S S ========================

class ANSICode {
public:
    friend std::ostream& operator<<(std::ostream& os, const ANSICode& ansi);

public:
    /**
     * @param [in] c ANSI escape code.
     */
    explicit ANSICode(const char* c);
private:
    const char* m_code;  /* ANSI escape code. */
};

inline
ANSICode::ANSICode(const char* c)
    : m_code(c) { }

inline
std::ostream& operator<<(std::ostream& os, const ANSICode& ansi)  {
    return os << ansi.m_code;
}

namespace color {
// Basic 8 color definitions
KTD_INLINE_VARIABLE const ANSICode black("\033[30m");
KTD_INLINE_VARIABLE const ANSICode red("\033[31m");
KTD_INLINE_VARIABLE const ANSICode green("\033[32m");
KTD_INLINE_VARIABLE const ANSICode yellow("\033[33m");
KTD_INLINE_VARIABLE const ANSICode blue("\033[34m");
KTD_INLINE_VARIABLE const ANSICode magenta("\033[35m");
KTD_INLINE_VARIABLE const ANSICode cyan("\033[36m");
KTD_INLINE_VARIABLE const ANSICode white("\033[37m");

// Bright 8 colors definitions
KTD_INLINE_VARIABLE const ANSICode bright_black("\033[90m");
KTD_INLINE_VARIABLE const ANSICode bright_red("\033[91m");
KTD_INLINE_VARIABLE const ANSICode bright_green("\033[92m");
KTD_INLINE_VARIABLE const ANSICode bright_yellow("\033[93m");
KTD_INLINE_VARIABLE const ANSICode bright_blue("\033[94m");
KTD_INLINE_VARIABLE const ANSICode bright_magenta("\033[95m");
KTD_INLINE_VARIABLE const ANSICode bright_cyan("\033[96m");
KTD_INLINE_VARIABLE const ANSICode bright_white("\033[97m");

/**
 * @brief Generates an ANSI escape code for a 256-color palette index.
 *
 * @param index The 256-color palette index (range: 0-255).
 * @return An ANSICode object representing the ANSI escape code for the specified color.
 */
inline
ANSICode palette(const uint8_t index) {
    static char code[16];
    std::snprintf(code, sizeof(code), "\033[38;5;%dm", index);
    return ANSICode(code);
}

/**
 * @brief Generates an ANSI escape code for an RGB color.
 *
 * @param r The red component of the color (range: 0-255).
 * @param g The green component of the color (range: 0-255).
 * @param b The blue component of the color (range: 0-255).
 * @return An ANSICode object representing the ANSI escape code for the specified RGB color.
 */
inline
ANSICode rgb(const uint8_t r, const uint8_t g, const uint8_t b) {
    static char code[32];
    std::snprintf(code, sizeof(code), "\033[38;2;%d;%d;%dm", r, g, b);
    return ANSICode(code);
}
}  //namespace color

namespace background {
// Basic 8 background color definitions
KTD_INLINE_VARIABLE const ANSICode black("\033[40m");
KTD_INLINE_VARIABLE const ANSICode red("\033[41m");
KTD_INLINE_VARIABLE const ANSICode green("\033[42m");
KTD_INLINE_VARIABLE const ANSICode yellow("\033[43m");
KTD_INLINE_VARIABLE const ANSICode blue("\033[44m");
KTD_INLINE_VARIABLE const ANSICode magenta("\033[45m");
KTD_INLINE_VARIABLE const ANSICode cyan("\033[46m");
KTD_INLINE_VARIABLE const ANSICode white("\033[47m");

// Bright 8 background colors definitions
KTD_INLINE_VARIABLE const ANSICode bright_black("\033[100m");
KTD_INLINE_VARIABLE const ANSICode bright_red("\033[101m");
KTD_INLINE_VARIABLE const ANSICode bright_green("\033[102m");
KTD_INLINE_VARIABLE const ANSICode bright_yellow("\033[103m");
KTD_INLINE_VARIABLE const ANSICode bright_blue("\033[104m");
KTD_INLINE_VARIABLE const ANSICode bright_magenta("\033[105m");
KTD_INLINE_VARIABLE const ANSICode bright_cyan("\033[106m");
KTD_INLINE_VARIABLE const ANSICode bright_white("\033[107m");


/**
 * @brief Generates an ANSI escape code for a background color using the 256-color palette.
 *
 * @param index The 256-color palette index (range: 0-255). Values outside this range default to white.
 * @return An ANSICode object representing the ANSI escape code for the specified background color.
 */
inline
ANSICode palette(const uint8_t index) {
    static char code[16];
    std::snprintf(code, sizeof(code), "\033[48;5;%dm", index);
    return ANSICode(code);
}


/**
 * @brief Generates an ANSI escape code for a background color using the specified RGB values.
 *
 * @param r The red component of the color (range: 0-255).
 * @param g The green component of the color (range: 0-255).
 * @param b The blue component of the color (range: 0-255).
 * @return An ANSICode object representing the ANSI escape code for the specified background RGB color.
 */
inline
ANSICode rgb(const uint8_t r, const uint8_t g, const uint8_t b) {
    static char code[32];
    std::snprintf(code, sizeof(code), "\033[48;2;%d;%d;%dm", r, g, b);
    return ANSICode(code);
}
}  //namespace background

namespace effect {
// Basic text effects
KTD_INLINE_VARIABLE const ANSICode bold("\033[1m");
KTD_INLINE_VARIABLE const ANSICode dim("\033[2m");
KTD_INLINE_VARIABLE const ANSICode underline("\033[4m");
KTD_INLINE_VARIABLE const ANSICode blink("\033[5m");
KTD_INLINE_VARIABLE const ANSICode reverse("\033[7m");
KTD_INLINE_VARIABLE const ANSICode hidden("\033[8m");

// Extended text effects
KTD_INLINE_VARIABLE const ANSICode italic("\033[3m");
KTD_INLINE_VARIABLE const ANSICode strikethrough("\033[9m");
KTD_INLINE_VARIABLE const ANSICode frame("\033[51m");
KTD_INLINE_VARIABLE const ANSICode encircle("\033[52m");
KTD_INLINE_VARIABLE const ANSICode overline("\033[53m");
KTD_INLINE_VARIABLE const ANSICode double_underline("\033[21m");


/**
 * @brief Generates an ANSI escape code for a 256-color palette index.
 *
 * @param index The 256-color palette index (range: 0-255).
 * @return An ANSICode object representing the ANSI escape code for the specified color.
 */
inline
ANSICode palette(const uint8_t index) {
    static char code[16];
    std::snprintf(code, sizeof(code), "\033[38;5;%dm", index);
    return ANSICode(code);
}
}  //namespace effect

// ======================== C L A S S ========================
// ===    ConsoleState
// ======================== C L A S S ========================

class ConsoleState {
public:
    /**
     * @brief Applies the current console state, including foreground color, background color and text effects, to the output stream.
     */
    void apply() const;

public:
    /**
     * @brief Constructs a ConsoleState object with specified foreground color, background color, and text effect.
     *
     * @param [in] fg The foreground color to be applied.
     * @param [in] bg The background color to be applied.
     * @param [in] effect The text effect to be applied (e.g., bold, underline).
     */
    ConsoleState(const std::string& fg, const std::string& bg, const std::string& effect);
private:
    std::string m_foreground;
    std::string m_background;
    std::string m_effect;
};

inline
ConsoleState::ConsoleState(const std::string& fg, const std::string& bg, const std::string& effect)
    : m_foreground(fg), m_background(bg), m_effect(effect) { }

inline
void ConsoleState::apply() const {
    std::cout << m_foreground << m_background << m_effect;
}

// ======================== C L A S S ========================
// ===    Endl
// ======================== C L A S S ========================

class Endl {
public:
    friend std::ostream& operator<<(std::ostream& os, const Endl&);
};

inline
std::ostream& operator<<(std::ostream& os, const Endl&) {
    return os << "\n";
}

KTD_INLINE_VARIABLE Endl endl;
}  //namespace ktd


#endif // KANITERU_CONSOLE_STREAM_HPP

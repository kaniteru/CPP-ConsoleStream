#include "kani/console_stream.hpp"

int main(int argc, char* argv[]) {
#ifdef _WIN32
    ktd::enable_virtual_terminal();
#endif //_WIN32

    std::cout << ktd::background::white << ktd::color::red << "Hello, World!" << ktd::endl;


    return 0;
}
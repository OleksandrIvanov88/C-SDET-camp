#include <iostream>
#include <array>
#include "maze_solving.hpp"

int main()
{
    try
    {
        // true
        std::array<std::array<bool, 5>, 5> arr_5x5{{{1, 0, 1, 1, 1},
                                                    {1, 0, 1, 0, 1},
                                                    {1, 1, 1, 0, 1},
                                                    {0, 0, 0, 0, 1},
                                                    {0, 0, 0, 0, 1}}};
        std::cout << std::boolalpha;
        std::cout << maze_solving(arr_5x5) << std::endl;

        // false
        arr_5x5 = {{{1, 0, 1, 1, 1},
                    {1, 0, 1, 0, 1},
                    {1, 1, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1}}};
        std::cout << maze_solving(arr_5x5) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
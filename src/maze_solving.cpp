#include "maze_solving.hpp"

bool size_chek(size_t sz_1, size_t sz_2, const uint32_t MAX, const uint32_t MIN)
{
    if (sz_1 != sz_2)
    {
        return false;
    }
    if (sz_1 > MAX || sz_1 < MIN)
    {
        return false;
    }

    return true;
}

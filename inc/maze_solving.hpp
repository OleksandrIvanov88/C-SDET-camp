#pragma once

#include <iostream>
#include <array>
#include <exception>
#include <sstream>

#include "union_find.hpp"

/**
 * @brief checks if the matrix is square and within the MIN and MAX limits
 * @param sz_1 - amount of rows
 * @param sz_2 - amount of columns
 * @param MAX  - max amount of rows/columns 
 * @param MIN  - min amount of rows/columns
 * @return true if matrix meets requirements and false if not
 * */
bool size_chek(size_t sz_1, size_t sz_2, const uint32_t MAX, const uint32_t MIN);


/**
 * @brief process the provided matrix and solves if it is the route from the top 
 *        left to the lowest right one. Throw std::length_error() if matrix size is out of bounds
 * @param arr  - square boolean matrix to process 
 * @param MAX  - max amount of rows/columns 
 * @param MIN  - min amount of rows/columns
 * @return true if it is the way from the top left corner to the lowest right one
 * */
template <typename T, size_t size>
bool maze_solving(const std::array<T, size> &arr, const uint32_t MAX = 50, const uint32_t MIN = 2)
{
    if (!size_chek(arr.size(), arr.at(0).size(), MAX, MIN))
    {
        std::stringstream ss;
        ss << "Error!Maze must be the square matrix with maximum dimension "
           << MAX << "x" << MAX << " and minimum " << MIN << "x" << MIN << ".";
        throw std::length_error(ss.str());
    }

    if (arr.at(0).at(0) == 0 || arr.at(size - 1).at(size - 1) == 0)
    {
        return false;
    }

    UnionFind<size_t, size * size> subset;

    for (size_t i{0}; i < size; ++i)
    {
        for (size_t j{0}; j < size; ++j)
        {
            if (j + 1 < size && arr.at(i).at(j) == arr.at(i).at(j + 1))
            {
                subset.union_sets(i * size + j, i * size + j + 1);
            }

            if (i + 1 < size && arr.at(i).at(j) == arr.at(i + 1).at(j))
            {
                subset.union_sets(i * size + j, (i + 1) * size + j);
            }
        }
    }

    return subset.connected(0, size * size - 1);
}
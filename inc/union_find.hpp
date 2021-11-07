#pragma once

#include <stdio.h>

template <class T, size_t size>
class UnionFind
{
public:
    /**
     * @brief Ctor - initialize the array with 0 to size − 1
     * */
    UnionFind()
    {
        size_t cnt{0};
        for (auto &it : this->arr)
        {
            it = cnt++;
        }
    }

public:
    /**
     * @brief unites the elements first and second, as well as the sets to which they belong.
     * @param first  - element first
     * @param second - element second
     * */
    void union_sets(T first, T second)
    {
        T first_root{root(first)};
        T second_root{root(second)};
        arr.at(second_root) = first_root;
    }

    /**
     * @brief checks if the provided elements are in the same set.
     * @param entry  - first element
     * @param exit   - second element
     * */
    bool connected(T entry, T exit)
    {
        return root(entry) == root(exit);
    }

private:
    std::array<T, size> arr;

    /**
     * @brief provide the root of the element
     * @param element  - element for which root is required
     * @return root 
     * */
    T root(T element)
    {
        while (element != arr.at(element))
        {
            element = arr.at(element);
        }
        return element;
    }
};

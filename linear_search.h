#pragma once

#include <vector>
using namespace std;

// template function for finding the last occurrence of target int in a vector
template <typename Item_Type>
int linear_search_last(const vector<Item_Type>& items, Item_Type target, size_t pos) {
    // base case: If we've reached the end of the vector, return -1
    if (pos == items.size()) {
        return -1;
    }

    // recursive function step: searching the full vector index
    int index_in_rest = linear_search_last(items, target, pos + 1);

    // if target int is found later in the vector, return the index
    if (index_in_rest != -1) {
        return index_in_rest;
    }

    // if not, check current position
    if (items[pos] == target) {
        return pos;
    }

    // if no valid match with target int is found, return -1
    return -1;
}


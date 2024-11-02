#include <iostream>
#include <vector>

using namespace std;

int linear_search(const vector<int>& items, int target, size_t pos_first) {
    if (pos_first == items.size()) {
        return -1;
    }
    int result = linear_search(items, target, pos_first + 1);
    if (result == -1 && items[pos_first] == target) {
        return pos_first;
    }
    return result;
}
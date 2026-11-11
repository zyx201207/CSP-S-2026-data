#include <iostream>
#include <vector>
#include <algorithm>
char get_char(const std::vector<std::pair<size_t, char>>& segments, size_t segidx, size_t curoffset, size_t logic_total_size, size_t logic_current) {
    size_t target = logic_total_size - logic_current;
    size_t len = 0;
    size_t tar_segidx = 0;
    for(int i = segments.size() - 1; i >= 0; i--) {
        size_t length = segments[i].first;
        if(len + length > target) { x
            tar_segidx = i;
            break;
        }
        len += length;
    }
    return segments[tar_segidx].second;
}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    size_t L;
    std::cin >> L;
    std::vector<std::pair<size_t/*length*/, char/*repeat*/>> segments(L + 1);
    size_t logic_total_length = 0;
    for(const auto& segment : segments) logic_total_length += segment.first;
    for(size_t idx = 0; idx < L; idx++) {
        size_t repeat_time;
        char repeated;
        std::cin >> repeat_time >> repeated;
        segments[idx] = {repeat_time, repeated};
    }
    size_t modifies = 0;
    size_t cursor = 0;
    for(size_t x = 0; x < segments.size(); x++) {
        const auto& segment = segments[x];
        size_t len = segment.first;
        size_t ch = segment.second;
        for(size_t i = 0; i < len; i++) {
            cursor += 1;
            char across_from = get_char(segments, x, i, logic_total_length, cursor);
            if(across_from != ch) modifies++;
        }
    }
    std::cout << modifies;
}

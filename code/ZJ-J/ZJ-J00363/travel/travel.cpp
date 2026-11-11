#include <iostream>
#include <string>
#include <cctype>
bool check_same_side(char r, char x) {
    return (r == 'A' && x == 'A') ||
            (r == 'A' && x == 'B') ||
            (r == 'A' && x == 'C') ||
            (r == 'B' && x == 'A') ||
            (r == 'B' && x == 'B') ||
            (r == 'B' && x == 'C') ||
            (r == 'C' && x == 'A') ||
            (r == 'C' && x == 'B') ||
            (r == 'C' && x == 'C') ||

            (r == 'D' && x == 'D') ||
            (r == 'D' && x == 'F') ||
            (r == 'F' && x == 'D') ||
            (r == 'F' && x == 'F');
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::string r_page, r_offset, x_page, x_offset;
    std::cin >> r_page >> r_offset >> x_page >> x_offset;
    std::cout << (r_page == x_page);
    if(r_page != x_page) {
        std::cout << "000";
        return 0;
    }
    std::string row_num;
    char r_col, x_col;
    for(char c: r_offset) if(c >= '0' && c <= '9') row_num += c; else r_col = c;
    bool mismatched = false;
    for(size_t idx = 0; idx < x_offset.size(); idx++) {
        char c = x_offset[idx];
        if(::isdigit(c)) {
            if(row_num[idx] != c) {
                std::cout << 0;
                mismatched = true;
                break;
            }
        } else {
            x_col = c;
        }
    }
    if(!mismatched) std::cout << 1;
    if(check_same_side(r_col, x_col)) std::cout << 1;
    else {
            std::cout << 0;
            std::cout << 0;
            return 0;
    }
    std::cout << (abs(r_col - x_col) == 1);
    return 0;
}

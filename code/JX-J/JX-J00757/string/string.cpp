// main
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::freopen("string.in", "r", stdin);
    std::freopen("string.out", "w", stdout);

    int n;
    std::cin >> n;

    std::pair<int, char> left;
    std::pair<int, char> right;

    std::vector<std::pair<int, char>> all;
    for (int i = 0; i < n; ++i) {
        int a;
        char c;
        std::cin >> a >> c;
        all.emplace_back(a, c);
    }

    int i = 0, j = n - 1;
    left = all[i];
    right = all[j];
    int ans = 0;
    while (i < j) {
        if (left.second != right.second) {
            if (left.first > right.first) {
                left.first -= right.first;
                ans += right.first;

                --j;
                right = all[j];
            } else if (left.first < right.first) {
                right.first -= left.first;
                ans += left.first;

                ++i;
                left = all[i];
            } else {
                ans += left.first;
                ++i;
                --j;
                left = all[i];
                right = all[j];
            }
        } else {
            if (left.first > right.first) {
                left.first -= right.first;

                --j;
                right = all[j];
            } else if (left.first < right.first) {
                right.first -= left.first;

                ++i;
                left = all[i];
            } else {
                ++i;
                --j;
                left = all[i];
                right = all[j];
            }
        }
    }

    std::cout << ans;
    return 0;
}

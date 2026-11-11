#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

std::mt19937_64 rnd();

void sol() {
    std::cout << "0 1\n300 1\n";
    for (int i = 1; i <= 300; i++) {
        std::cout << i << " ";
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int T = 1;
    // std::cin >> T;
    while (T--) sol();

    return 0;
}
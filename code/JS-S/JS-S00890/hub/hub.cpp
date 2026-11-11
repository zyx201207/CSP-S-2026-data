#include <bits/stdc++.h>
int ttt, n, k;
int main() {
    freopen("hub.in", "r", stdin), freopen("hub.out", "w", stdout), std::cin >> n >> ttt;
    while (ttt--) {
        std::cin >> n >> k;
        if (n == k)
            std::cout << 0;
        else
            std::cout << (n - k) / 3;
    }
}

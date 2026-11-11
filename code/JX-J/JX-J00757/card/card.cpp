// main
#include <iostream>
#include <vector>
#include <stack>
int n, m;

void solve1() {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> cnt(m + 1, 0);
    for (int k = 0; k < n; ++k) {
        std::stack<int> s;
        std::vector<bool> instack(m + 1, false);
        for (int i = k; i < n; ++i) {
            if (!instack[a[i]]) {
                s.push(a[i]);
                instack[a[i]] = true;
            } else {
                while (!s.empty() && s.top() != a[i]) {
                    instack[s.top()] = false;
                    s.pop();
                }
                s.pop();
                s.push(a[i]);
            }
        }

        while (!s.empty()) {
            cnt[s.top()]++;
            s.pop();
        }
    }

    for (int i = 1; i <= m; ++i) {
        std::cout << cnt[i] << ' ';
    }
}

void solve2() {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::stack<int> s;
    std::vector<bool> flag(m + 1, false);
    for (int i = n - 1; i >= 0; --i) {
        if (!flag[a[i]]) {
            flag[a[i]] = true;
            s.push(i + 1);
        }
    }

    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
}
int main() {
    std::freopen("card.in", "r", stdin);
    std::freopen("card.out", "w", stdout);
    std::cin >> n >> m;

    if (n <= 5) {
        solve1();
    } else {
        solve2();
    }
}

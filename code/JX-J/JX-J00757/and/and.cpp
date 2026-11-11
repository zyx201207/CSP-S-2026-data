// main
#include <iostream>
#include <vector>
#include <algorithm>
int n, m;
int solve1_maxn = -1;

int cnt = 0;
void solve1_dfs(std::vector<int>& a, std::vector<int> ans, int now) {
    if (now == n && ans.size() != m) return;
    if (now == n) {
        int answer = ans[0];
        for (int i = 1; i < m; ++i) {
            answer &= ans[i];
        }
        solve1_maxn = std::max(solve1_maxn, answer);
        return;
    }

    solve1_dfs(a, ans, now + 1);
    if (ans.size() < m) {

        ans.push_back(a[now]);
        solve1_dfs(a, ans, now + 1);
    }
}
void solve1() {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> ans;
    solve1_dfs(a, ans, 0);

    std::cout << solve1_maxn;
}

void solve2() {
    int solve2_maxn = -1;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        solve2_maxn = std::max(solve2_maxn, a[i]);
    }
    std::cout << solve2_maxn;
}

void solve3() {
    std::vector<int> a(n);
    std::cin >> a[0];
    int ans = a[0];

    for (int i = 1; i < n; ++i) {
        std::cin >> a[i];
        ans &= a[i];
    }
    std::cout << ans;
}

void solve4() {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    int ans = a[n - 1];
    for (int i = n - 2; i >= n - m; --i) {
        ans &= a[i];
    }
    std::cout << ans;
}

int main() {
    std::freopen("and.in", "r", stdin);
    std::freopen("and.out", "w", stdout);

    std::cin >> n >> m;

    if (n <= 20) {
        solve1();
    } else if(m == 1) {
        solve2();
    } else if(m == n) {
        solve3();
    } else {
        solve4();
    }
}

#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 2e6 + 5;

i64 n, m, a[N];
i64 nxt[N], pre[N];
std::vector<int> cnxt[N], cpre[N];
i64 tol[N], tor[N];
i64 stol[N], stor[N];

void sol(int C) {
    std::cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        nxt[i] = pre[i] = tol[i] = tor[i] = stol[i] = stor[i] = 0;
        cnxt[i].clear();
        cpre[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    a[n + 1] = 4e18L;

    auto query = [&](i64 l, i64 r) -> std::pair<int, int> {
        return std::make_pair(std::lower_bound(a + 1, a + n + 1, l) - a, std::upper_bound(a + 1, a + n + 1, r) - a - 1);
    };

    for (int i = 1; i <= n; i++) {
        nxt[i] = std::upper_bound(a + i + 1, a + n + 1, a[i] + m) - a - 1;
        pre[i] = std::lower_bound(a + 1, a + i + 1, a[i] - m) - a;
        // std::cout << i << " " << nxt[i] << " " << pre[i] << "\n";
        if (i != nxt[i]) cnxt[nxt[i]].push_back(i);
        if (i != pre[i]) cpre[pre[i]].push_back(i);
    }

    auto N300 = [&]() -> void {
        i64 ans = 0;
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = i + 3; j <= n; j++) {
                std::vector<i64> v1, v2;
                i64 cur;
                cur = i;
                i64 flag = 1;
                while (cur < j) {
                    if (nxt[cur] == cur) {
                        flag = 0;
                        break;
                    }
                    cur = nxt[cur];
                    if (cur < j) v1.push_back(cur);
                }
                cur = j;
                while (cur > i) {
                    if (pre[cur] == cur) {
                        flag = 0;
                        break;
                    }
                    cur = pre[cur];
                    if (cur > i) v2.push_back(cur);
                }
                std::reverse(v2.begin(), v2.end());
                if (!flag) continue;
                if (v1.size() == v2.size()) {
                    i64 s1 = 0, s2 = 0;
                    for (i64 y = 0; y < (i64)v1.size(); y++) {
                        s1 += !!(v1[y] - v2[y]);
                        s2 += v1[y] - v2[y];
                    }
                    if (s1 == 1 && s2 == 1) {
                        ans++;
                        // std::cout << i << " " << j << "\n";
                    }
                }
            }
        }
        std::cout << ans << "\n";
    };

    if (C <= 6 && C >= 1) {
        N300();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (pre[nxt[i]] == i) {
            tor[i] = nxt[i];
            tol[nxt[i]] = i;
        }
    }
    // std::cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     std::cout << i << " " << tol[i] << " " << tor[i] << "\n";
    // }
    for (int i = 1; i <= n; i++) {
        stol[i] = cnxt[i].end() - std::lower_bound(cnxt[i].begin(), cnxt[i].end(), pre[i] + 1);
        stor[i] = std::lower_bound(cpre[i].begin(), cpre[i].end(), nxt[i]) - cpre[i].begin();
        // std::cout << i << ":\n  cnxt ";
        // for (auto j : cnxt[i]) {
        //     std::cout << j << " ";
        // }
        // std::cout << "\n  cpre ";
        // for (auto j : cpre[i]) {
        //     std::cout << j << " ";
        // }
        // std::cout << "\n";
        // std::cout << stol[i] << " " << stor[i] << "\n\n";
    }
    for (int i = 1; i <= n; i++) {
        if (i != tol[i]) {
            stol[i] += stol[tol[i]] + 1;
        } else {
            stol[i]++;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (i != tor[i]) {
            stor[i] += stor[tor[i]] + 1;
        } else {
            stor[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        // std::cout << i << " " << stol[i] << " " << stor[i] << "\n";
    }

    i64 ans = 0;
    for (int i = 2; i < n - 1; i++) {
        int j = i + 1;
        if (i == pre[i] || i == nxt[i] || j == pre[j] || j == nxt[j]) {
            continue;
        }
        if (nxt[i] == j) {
            continue;
        }
        // if (pre[nxt[j]] != i) {
        //     continue;
        // }
        // if (nxt[pre[i]] != j) {
        //     continue;
        // }
        // std::cout << i << " " << j << " " << stol[j] << " " << stor[i] << "\n";
        ans += (stol[j] - 1) * (stor[i] - 1);
    }
    std::cout << ans << "\n";
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    i64 c, T = 1;
    std::cin >> c >> T;
    while (T--) sol(c);

    return 0;
}
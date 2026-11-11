#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define __Debug

using namespace std;
typedef long long ll;
const int N = 1e3 + 10;

int c, T;
int n, m;

int maxn, root;
vector<int> e[N];
int dep[N];

void Dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    if (maxn < dep[u]) {
        maxn = dep[u];
        root = u;
    }
    for (int v : e[u]) {
        if (v == fa) continue;
        Dfs(v, u);
    }
}
bool Check(int mid) {
    int L = mid + 1, R = n - mid;
    if (R <= L) return true;
    int kkk = (R - L) / 2 + 1;
    int g = m - 2;
    if ((R - L) & 1) kkk -= (g + 1) / 2;
    else kkk -= g / 2;
    return kkk <= mid;
}
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    cin >> c >> T;
    if (c == 13 || c == 14) {
        while (T--) {
            cin >> n >> m;
            for (int i = 1; i < n; i++) {
                int u, v;
                cin >> u >> v;
            }
            if (m == n) {
                printf("0\n");
                continue;
            }
            if (m >= n / 2) {
                printf("1\n");
                continue;
            }
            int l = 2, r = n / 2, ans;
            while (l <= r) {
                int mid = l + r >> 1;
                if (Check(mid)) {
                    r = mid - 1;
                    ans = mid;
                } else l = mid + 1;
            }
            printf("%d\n", ans);
        }
    }
    // if (c == 7) {
    //     while (T--) {
    //         cin >> n >> m;
    //         for (int i = 1; i <= n; i++) e[i].clear();
    //         for (int i = 1; i < n; i++) {
    //             int u, v;
    //             cin >> u >> v;
    //             e[u].emplace_back(v);
    //             e[v].emplace_back(u);
    //         }
    //         maxn = 0;
    //         Dfs(1, 0); 
    //         maxn = 0;
    //         Dfs(root, 0); 
    //     }
    // }
    return 0;
}
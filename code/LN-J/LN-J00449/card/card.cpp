#include <bits/stdc++.h>
#define sfr return cout << "safe\n", 0;
#define sf_void return cout << "safe\n", void();
using namespace std;
using ll = long long;
using i128 = __int128;
using pr = pair<int, int>;
#define FILEIO "card"
const int N = 5e5 + 10;

int n, m, a[N], lst[N], ans[N], cnt[N];

auto main() -> signed {
    #ifdef FILEIO
        freopen(FILEIO ".in", "r", stdin);
        freopen(FILEIO ".out", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    bool spa = 1;
    for (int i = 1; i <= n; ++i) cin >> a[i], spa &= (a[i] >= a[i - 1]);
    if (n <= 10000) {
        stack<int> stk;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                if (lst[a[j]]) {
                    while (!stk.empty() && stk.top() != a[j]) {
                        lst[stk.top()] = 0;
                        stk.pop();
                    }
                    if (!stk.empty()) stk.pop();
                    // stk.pop();
                }
                stk.emplace(a[j]), lst[a[j]] = j;
            }
            while (!stk.empty()) ans[stk.top()]++, lst[stk.top()] = 0, stk.pop();
        }
        for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
        return 0;
    }
    if (spa) {
        for (int i = 1; i <= n; ++i) cnt[a[i]]++;
        for (int i = 1; i <= m; ++i) {
            cnt[i] += cnt[i - 1];
            cout << cnt[i] << " \n"[i == m];
        }
    }
}
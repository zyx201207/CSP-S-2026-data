#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
    int e[205];
} f[505];
map<int, int> dp, m1;
long long a[500005], n, m, t;

signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    t = n;
    for (int i = 1; i <= n; i++) cin >> a[t--];
    if (n <= 500 && m <= 200) {
        for (int i = 1; i <= n; i++) {
            if (m1[a[i]] != 0) f[i] = f[m1[a[i]]];
            else {
                f[i] = f[i - 1];
                f[i].e[a[i]] = 1;
            }
            m1[a[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) dp[i] += f[j].e[i];
        }
    } else for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) if (a[i] != a[j]) ++ dp[a[j]];
        ++ dp[a[i]];
    }
    for (int i = 1; i <= m; i++) cout << dp[i] << " ";
    return 0;
}
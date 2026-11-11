#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
int read() {
    int g = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        g = g * 10 + (ch ^ 48);
        ch = getchar();
    }
    return g * f;
}
int n, m, a[N], p[N], ans[N];
map<int, int> mp;
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) {
        mp.clear();
        int lmt = 0;
        for (int j = i; j <= n; j++) {
            if (mp.find(a[j]) != mp.end() && mp[a[j]] <= lmt && p[mp[a[j]]] == a[j]) {
                lmt = mp[a[j]];
            } else {
                p[++lmt] = a[j];
                mp[a[j]] = lmt;
            }
        }
        for (int j = 1; j <= lmt; j++) {
            ans[p[j]]++;
            // cout << p[j] << " ";
        }
        // cout << endl;
    }
    for (int i = 1; i < m; i++) {
        printf("%lld ", ans[i]);
    }
    printf("%lld", ans[m]);
    putchar('\n');
    return 0;
}
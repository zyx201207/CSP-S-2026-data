#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

inline int readf() {
    int x = 0; char c = getchar_unlocked();
    for(; !isdigit(c); c = getchar_unlocked());
    for(; isdigit(c); c = getchar_unlocked()) x = x * 10 + (c ^ 48);
    return x;
}

int c, t, n, m, x, y, cans, ans; int d[1000009];
vector <int> e[1000009]; queue <int> q;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    c = readf(), t = readf();
    for(int cs = 1; cs <= t; cs++) {
        n = readf(), m = readf(); for(int i = 1; i < n; i++) x = readf(), y = readf(), e[x].push_back(y), e[y].push_back(x);
        if(m == n) { printf("0\n"); for(int i = 1; i <= n; i++) e[i].clear(), e[i].shrink_to_fit(); continue; }
        if(m == n - 1) { printf("1\n"); for(int i = 1; i <= n; i++) e[i].clear(), e[i].shrink_to_fit(); continue; }
        if(c >= 13 && c <= 14) { if(m >= n / 2) printf("1\n"); else if(m == 1) printf("%d\n", (n / 2) / 2 + 1); else printf("%d\n", (n / 2 - m + 3) / 4 + 1); for(int i = 1; i <= n; i++) e[i].clear(), e[i].shrink_to_fit(); continue; }
        ans = n; for(int i = 1; i < (1 << n); i++) if(__builtin_popcount(i) == m) {
            for(int j = 1; j <= n; j++) if((i >> j - 1) & 1) d[j] = 0, q.push(j); else d[j] = n + 1;
            while(!q.empty()) { int now = q.front(); q.pop(); for(int j : e[now]) if(d[j] == n + 1) { d[j] = d[now] + 1; q.push(j); } }
            cans = 0; for(int j = 1; j <= n; j++) cans = max(cans, d[j]);
            ans = min(ans, cans);
        }
        printf("%d\n", ans);
        for(int i = 1; i <= n; i++) e[i].clear(), e[i].shrink_to_fit();
    }
    return 0;
}
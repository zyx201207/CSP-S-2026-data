#include <bits/stdc++.h>
#define re register
#define fir first
#define sec second
#define int long long
#define gc getchar
#define pc putchar
#define pck putchar(' ');
#define pcn putchar('\n');
#define mp make_pair
#define pb push_back
#define MAXN 2000005
#define INF 2000005
using namespace std;
int c, t;
int n, d;
int x[MAXN];
int minn, cnt;
inline void free() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
}
inline int rd() {
    int x = 0, sig = 1;
    char ch = gc();
    for (; ch > '9' || ch < '0'; ch = gc())
        if (ch == '-') sig = -1;
    for (; ch >= '0' && ch <= '9'; ch = gc())
        x = (x << 3) + (x << 1) + (ch ^ 48);
    return x * sig;
}
inline void write(int x) {
    if (x < 10) {
        pc(x ^ 48);
        return;
    }
    write(x / 10);
    pc(x % 10 ^ 48);
}
inline void wt(int x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    write(x);
    pcn;
}
inline void dfs(int now, int u, int v, int step) {
    if (now == v) {
        if (step < minn) {
            minn = step;
            cnt = 1;
            return;
        }
        if (step == minn) cnt++;
        return;
    }
    for (re int i = now + 1; i <= v; i++) {
        if (x[i] - x[now] <= d) dfs(i, u, v, step + 1);
        else break;
    }
}
signed main() {
    free();
    c = rd();
    t = rd();
    while (t--) {
        int ans = 0;
        n = rd();
        d = rd();
        for (re int i = 1; i <= n; i++)
            x[i] = rd();
        for (re int i = 1; i < n; i++)
            for (re int j = i + 1; j <= n; j++) {
                minn = INF;
                cnt = 0;
                dfs(i, i, j, 0);
                if (cnt == 2) ans++;
            }
        wt(ans);
    }
    return 0;
}

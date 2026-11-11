#include <bits/stdc++.h>
#define int long long
#define re register
#define gc getchar
#define pc putchar
#define pck putchar(' ');
#define pcn putchar('\n');
#define mp make_pair
#define pb push_back
#define MAXN 500005
#define INF 0x3f3f3f3f
using namespace std;
int n, m;
int a[MAXN], sum[MAXN];
inline void free() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
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
inline bool chk(int x) {
    for (re int i = 1; i + x - 1 <= n; i++)
        if ((a[i + x - 1] * x - (sum[i + x - 1] - sum[i - 1])) <= m) return 1;
    return 0;
}
signed main() {
    free();
    n = rd();
    m = rd();
    sum[0] = 0;
    for (re int i = 1; i <= n; i++)
        a[i] = rd();
    sort(a + 1, a + 1 + n);
    for (re int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int l = 1, r = n + 1;
    int mid = (l + r) >> 1;
    while (l < r - 1) {
        if (chk(mid)) l = mid;
        else r = mid;
        mid = (l + r) >> 1;
    }
    wt(l);
    return 0;
}

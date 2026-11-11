#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
    int x = 0, flg = 0;
    char c = getchar();
    while (!isdigit(c)) {
        flg |= c == '-';
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c ^ 48);
        c = getchar();
    }
    return flg ? -x : x;
}
inline void write(int x, char div = '\n') {
    if (!x) {
        putchar('0'), putchar(div);
        return;
    }
    string s = "";
    if (x < 0) {
        putchar('-'), x = -x;
    }
    while (x) {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    for (char c : s) {
        putchar(c);
    }
    putchar(div);
}
const int N = 5e5 + 5;
const int inf = 1e18;
int n, m, ans;
int a[N], S[N];
bool check(int k) {
    int ret = inf;
    for (int i = k; i <= n; i++) {
        ret = min(ret, (a[i] * k) - (S[i] - S[i - k]));
    }
    return ret <= m;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1, [&](int x, int y) {
         return x < y;
    });
    for (int i = 1; i <= n; i++) {
        S[i] = S[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid;
        }
    }
    write(ans);
    return 0;
}

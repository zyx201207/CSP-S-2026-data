#include <bits/stdc++.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define int long long
#define endl '\n'
using namespace std;
constexpr int N = 5e5 + 10;
inline int input() {
    char c = gc();
    int x = 0, f = 1;
    while (c < '0' or c > '9') {
        if (c == '-') f = -f;
        c = gc();
    }
    while (c >= '0' and c <= '9') x = x * 10 + c - '0', c = gc();
    return x * f;
}
void print(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) print(x / 10);
    pc(x % 10 + '0');
}
int n, m, ans = 1, a[N], pre[N];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = input(), m = input();
    for (int i = 1; i <= n; i++) a[i] = input();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i + 1] == a[i] and i + 1 <= n) continue;
        int l = 1, r = i, j, res = 0, x = a[i];
        while (l <= r) {
            j = (l + r) / 2;
            if (x * (i - j + 1) - (pre[i] - pre[j - 1]) <= m) {
                res = i - j + 1;
                r = j - 1;
            } else {
                l = j + 1;
            }
        }
        ans = max(ans, res);
    }
    print(ans);
    return 0;
}

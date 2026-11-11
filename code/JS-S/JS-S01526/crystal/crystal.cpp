#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define il inline
#define rg register
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
const int N = 500005;
const int INF = 0x7ffffffffff;

il int read() {
    short f = 1;
    int x = 0;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') f *= (-1);
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = gc();
    }
    return x * f;
}

void wit(int x) {
    if (x == 0) return ;
    wit(x / 10);
    pc(x % 10 + '0');
    return ;
}

void write(int x, bool edl) {
    if (x <= 0) {
        if (x == 0) pc('0');
        else {
            pc('-');
            wit(x * (-1));
        }
    }
    else wit(x);
    if (edl) pc('\n');
    else pc(' ');
    return ;
}

int n, m, a[N], s = 0, ans = 0;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    int i = 1, j = 1;
    while (j < n) {
        if (s + (j - i) * (a[j] - a[j - 1]) <= m) {
            s += (j - i) * (a[j] - a[j - 1]);
            j++;
        }
        else {
            s -= a[j - 1] - a[i];
            i++;
        }
        ans = max(ans, j - i);
    }
    write(ans, 0);
    return 0;
}

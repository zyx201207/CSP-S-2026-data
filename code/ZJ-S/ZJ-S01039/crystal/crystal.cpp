#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int, int>
#define pb push_back
#define mid (l + r) / 2
#define ls num << 1
#define rs num << 1 | 1

inline int read() {
    int x = 0, m = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') m = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * m;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

const int N = 5e5 + 5;

int a[N];

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    int sum = 0, l = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while ((i - l + 1) * a[i] - sum > m) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    write(ans);
    putchar('\n');
}
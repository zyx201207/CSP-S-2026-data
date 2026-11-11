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

const int N = 2e6 + 5;

int a[N], nxt[N], f[N][3];

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int synAKIOI = read(), T = read();
    while (T--) {
        int n = read(), d = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        int r = n;
        for (int i = n; i >= 1; i--) {
            while (a[r] - a[i] > d) r--;
            nxt[i] = r;
        }
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            int l = max(i + 1, nxt[i - 1] + 1), r = nxt[i];
            f[i][0] += r - l + 1;
            int L = (i > 1) ? max(i + 1, nxt[i - 2] + 1) : (i + 1), R = l - 1;
            f[i][1] += R - L + 1;
            if (nxt[i] > i) {
                if (nxt[i - 1] == nxt[i]) {
                    if (nxt[i - 2] != nxt[i - 1]) f[i][1] += f[nxt[i]][0];
                    ans += f[nxt[i]][2];
                    if (nxt[i] > i + 1) ans += f[nxt[i]][1];
                }
                else {
                    f[i][0] += f[nxt[i]][0];
                    f[i][2] += f[nxt[i]][2];
                    if (nxt[i] > i + 1) {
                        ans += f[nxt[i]][1];
                        if (nxt[i - 1] < nxt[i] - 1) f[i][2] += f[nxt[i]][1], ans -= f[nxt[i]][1];
                    }
                }
            }
            ans += f[i][2];
        }
        for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++) f[i][j] = 0;
        write(ans);
        putchar('\n');
    }
}
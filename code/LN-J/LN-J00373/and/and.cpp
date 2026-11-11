#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define gc getchar_unlocked
#define readT int

inline readT rd() {
    readT x = 0; int ch = gc(), f = 1;
    for (; ! isdigit(ch); ch = gc()) {if (ch == '-') {f = -1;}}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}

constexpr int N = 5005;

int n, m;
ll a[N];

ll f[N][N];
int fl = 1, fla = 1, fff;

inline void sol() {
    n = rd(), m = rd();
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
        if (a[i] != i - 1) {
            fl = 0;
        }
        int x = a[i], cnt = 0;
        while (x) {
            x -= x & -x;
            ++ cnt;
        }
        if ((1 << cnt) - 1 != a[i]) {
            fla = 0;
        }
        if (a[i] == 0) fff = 1;
    }

    if (fl) {
        int k = 1;
        while (k < m) {
            k <<= 1;
        }
        cout << n - (1 << k);
        return;
    }
    else if (fla || (m == n - 1 && fff)) {
        sort(a + 1, a + n + 1);
        ll res = LLONG_MAX;
        for (int i = n; n - i != m; -- i) {
            res &= a[i];
        }
        cout << res << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        f[i][1] = a[i];
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                f[i][j] = max(f[i][j], f[k][j - 1] & a[i]);
                // printf("%d %d %d: %d\n", i, j, k, f[i][j]);
            }
            // puts("");
        }
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                f[i][j] = max(f[i][j], f[k][j]);
            }
        }
        // puts("");
    }

    cout << f[n][m];
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int qwq = 1;
    // qwq = rd();
    while (qwq --) {
        sol();
    }

    return 0;
}

/*

3 15 12 12

0011 1111 

1111
1110
1011
1011
1100


1000
0111
0111
0111

1111
1110
1101
1100
1011
1010
1001
1000
0111
0110
0101
0100
0011
0010
0001
0000

5 3
31 3 1 15 7

*/
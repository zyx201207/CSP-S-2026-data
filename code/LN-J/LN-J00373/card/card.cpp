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

constexpr int N = 5e5 + 10;

int n, m;
int a[N];
int ans[N];
int c[N], t = 0;
int fl[N];

inline void sol() {
    n = rd(), m = rd();
    for (int i=1; i<=n; i++) {
        a[i] = rd();
        // cout << a[i];
    }
    for (int i=1; i<=n; i++) {
        t = 0;
        for (int j=i; j<=n; j++) {
            for (int it = t; it >= 1; -- it) {
                if (c[it] == a[j]) t = it - 1;
            }
            c[++ t] = a[j];
            // cout << c[t-1] << ' ';
        }
        memset(fl, 0, sizeof(fl[0]) * (m + 1));
        for (int j=1; j<=t; j++) {
            ++ fl[c[j]];
            // cout << c[j] << ' ';
        }
        for (int j=1; j<=m; j++) {
            ans[j] += (fl[j] >= 1);
        }
        // puts("");
    }

    for (int i=1; i<=m; i++) {
        cout << ans[i] << ' ';
    }

}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int qwq = 1;
    // qwq = rd();
    while (qwq --) {
        sol();
    }

    return 0;
}

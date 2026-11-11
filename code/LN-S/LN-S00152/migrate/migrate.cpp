#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fi first
#define se second
#define ll long long

#define readT ll
#define gc getchar_unlocked

inline readT rd() {
    readT x = 0; int f = 1, ch = gc();
    for (; !isdigit(ch); ch = gc()) {if (ch == '-') f = -1;}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}

constexpr int N = 2e6 + 10;

ll n, d;
ll x[N];

ll ans;
ll cnt[N], f[N], vis[N];
queue<int> qu;

inline void sol() {
    n = rd(), d = rd(); ans = 0;
    for (int i = 1; i <= n; i++) {
        x[i] = rd();
    }

    for (int i = 1; i <= n; i++) {
        memset(cnt, 0x3f, sizeof cnt);
        memset(f, 0, sizeof f);
        memset(vis, 0, sizeof vis);
        cnt[i] = 0;
        qu.push(i);
        f[i] = 1;
        // for (int j = i + 1; j <= n; j++) {
        //     if (x[j] - x[i] <= d) {
        //         if (cnt[j] == cnt[i] + 1) {
        //             f[j] += f[i];
        //         }
        //         else if(cnt[j] > cnt[i] + 1) {
        //             f[j] = 1;
        //             cnt[j] = cnt[i] + 1;
        //         }
        //     }
        // }
        while (qu.size()) {
            int u = qu.front();
            qu.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (int j = u + 1; j <= n; j++) {
                // cout << cnt[j] << ' ';
                if (x[j] - x[u] <= d) {
                    if (cnt[j] == cnt[u] + 1) {
                        f[j] += f[u];
                    }
                    else if(cnt[j] > cnt[u] + 1) {
                        f[j] = f[u];
                        cnt[j] = cnt[u] + 1;
                    }
                    qu.push(j);
                }
                else {
                    break;
                }
            }
        }
        for (int j = i + 1; j <= n; j++) {
            // cout << cnt[j] << ' ';
            // cout << f[j] << ' ';
            if (f[j] == 2) ++ ans;
        }
        // puts("");
    }
    cout << ans << '\n';
}

// inline void solA() {
//     cout << 1;
//     n = rd(), d = rd(); ans = 0;
//     ll pre = 0;
//     for (int i = 1; i <= n; i++) {
//         x[i] = rd();
//     }
//     if (n < 2 || d <= 2 * (x[2] - x[1])) {
//         puts("0");
//         return;
//     }
//     int k = x[1] - x[0], cnt1 = 1;
//     cout << 1;
//     while (k * cnt1 <= d) {
//         ++ cnt1;
//     }
//     -- cnt1;

//     for (int i = 2 + k; i <= n; i++) {
//         pre += ((cnt1 - ((i - 2 - cnt1) % cnt1)) == 2);
//         ans += pre;
//     }

//     cout << ans << '\n';
// }

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c = rd();
    int awa = 1;
    awa = rd();
    // if (c == 11 || c == 12) {
    //     while (awa --) {
    //         solA();cout << 1;
    //     }
    //     return 0;
    // }
    while (awa --) {
        sol();
    }

    return 0;
}

/*

0 1
10 3
0 3 6 7 8 9 10 11 14 17

  1 1 1 1 1  3  2  2  2

11 1
8 11
0 5 10 15 20 25 30 35

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define readT ll
#define gc getchar_unlocked

inline readT rd() {
    readT x = 0; int f = 1, ch = gc();
    for (; !isdigit(ch); ch = gc()) {if (ch == '-') f = -1;}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}

constexpr int N = 5e5 + 10;

ll n, m;
ll a[N];

ll pre[N];

// inline bool check(int x) {
//     ll cnt = 0;
//     for (int i = 1; i < x; i++) {
//         cnt += a[x] - a[i];
//         // cout << x << ' ' << i << ' ' << cnt << ' ';
//         if (cnt > m) return 0;
//     }
//     return 1;
// }

ll ans = -1;

inline void sol() {
    n = rd(), m = rd();
    // cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = rd();
        // cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    // int l = 1, r = n;
    // while (l < r) {
    //     int mid = (l + r + 1) >> 1;
    //     if (check(mid)) l = mid;
    //     else r = mid - 1;
    //     // puts("");
    // }

    // cout << l;

    // puts("");

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) > m) l = mid + 1;
            else r = mid;
            // puts("");
        }
        ans = max(ans, i - l + 1ll);
    }
    cout << ans << '\n';


}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int awa = 1;
    // awa = rd();

    while (awa --) {
        sol();
    }

    return 0;
}
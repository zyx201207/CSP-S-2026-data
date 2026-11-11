#include <bits/stdc++.h>
using namespace std;
#define int long long
int trash;
int T;
int n, m;
int a[1000010];
map <pair <int, int>, int> mp;
map <pair <int, int>, int> st;
inline void solve1 () {
    mp.clear();
    for (int s = 0; s < (1LL << n); s++) {
        int last = -1;
        int frount = -1;
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            int op = ((s >> (i - 1)) & 1);
            if (op == 1) {
                if (last == -1) {
                    frount = i;
                    last = i;
                }
                else {
                    int dis = a[i] - a[last];
                    last = i;
                    if (dis > m)
                        goto loop1;
                }
                tot++;
            }
        }
        if (tot >= 2) {
            if (mp.count({frount, last}) == true)
                mp[{frount, last}] = min (tot, mp[{frount, last}]);
            else
                mp[{frount, last}] = tot;
        }
        loop1:;
    }
    st.clear();
    for (int s = 0; s < (1LL << n); s++) {
        int last = -1;
        int frount = -1;
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            int op = ((s >> (i - 1)) & 1);
            if (op == 1) {
                if (last == -1) {
                    frount = i;
                    last = i;
                }
                else {
                    int dis = a[i] - a[last];
                    last = i;
                    if (dis > m)
                        goto loop2;
                }
                tot++;
            }
        }
        if (tot >= 2 && mp[{frount, last}] == tot)
            st[{frount, last}]++;
        loop2:;
    }
    int cnt = 0;
    for (auto y : st)
        if (y.second == 2)
            cnt++;
    cout << cnt << '\n';
}
inline void solve2 () {
    if (m <= abs(a[2] - a[1])) {
        cout << 0 << '\n';
        return;
    }
    int t = m / abs (a[2] - a[1]) * 2;
    int ans = n - t + 1;
    cout << max (ans, 0LL) << '\n';
}
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> trash;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int base = a[2] - a[1];
        bool f = true;
        for (int i = 2; i <= n; i++) {
            if (base != a[i] - a[i - 1])
                f = false;
        }
        if (f)
            solve2 ();
        else
            solve1 ();
    }
    return 0;
}

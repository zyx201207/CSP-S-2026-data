#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Fr first
#define Sc second
#define lowbit(x) (x & (-x))

using namespace std;

const int kMaxN =  5e5 + 5;

int a[kMaxN], n, m, ans;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int x = m, cnt = 0;
    for (int i = 1; i <= n; i++) {
        x -= (a[i] - a[i - 1]) * cnt; 
        for (int j = i - cnt; x < 0 && j < i; j++, cnt--) {
            x += (a[i] - a[j]);
        }
        cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}

signed main() {
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for (; T; T--) {
        solve();
    }
    return 0;
}
/*
ulimit -s 1024000 && cd "/home/noilinux/HN-S01000/crystal" && g++ crystal.cpp -o crystal -Wall -O2 && ./crystal 
*/
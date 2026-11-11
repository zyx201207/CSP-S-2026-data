#include<bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 2e6 + 5;

int C, T, n, d, a[kMaxN], nxt[kMaxN], dis[kMaxN], ok[kMaxN], cnt[kMaxN], p1[kMaxN], p2[kMaxN], tjc[kMaxN];

void solve() {
    cin >> n >> d;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // for(int i = 1; i <= n; i++) // cout << nxt[i] << ' ';
    // cout << '\n';
    if(n == 1) return cout << "0\n", void();
    if(C <= 12 && C >= 11) {
        int diff = a[2] - a[1];
        if(d / diff <= 1) return cout << "0\n", void();
        cout << max(0LL, n - 2 * (d / diff) + 1) << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        for(int p = i, j = i; p; p--) {
            while(a[j] - a[p] > d) --j;
            nxt[p] = j;
        }
        dis[i] = 0;
        // cout << i << ":\n";
        for(int j = 1; j <= n; j++) {
            dis[j] = ok[j] = cnt[j] = p1[j] = p2[j] = tjc[j] = 0;
        }
        int mx = 0;
        for(int j = i - 1; j; j--) {
            if(nxt[j] == j) {dis[j] = 1e9; continue;}
            dis[j] = dis[nxt[j]] + 1;
            if(dis[j] < 1e9) {
                mx = max(mx, dis[j]);
                ++cnt[dis[j]], swap(p1[dis[j]], p2[dis[j]]), p1[dis[j]] = j;
            }
        }
        ok[0] = 1, p1[0] = i, p2[0] = 0;
        for(int j = 1; j <= mx; j++) {
            ok[j] = (cnt[j] == 1 || 
                (nxt[p1[j]] == nxt[p2[j]] && nxt[p1[j]] == p1[j - 1]));
            ok[j] &= ok[j - 1];
            // cout << ok[j] << ' ';
        }
        // cout << '\n';
        for(int j = i; j; j--) {
            if(dis[j] >= 1e9) continue;
            if(nxt[j] == p2[dis[nxt[j]]] && ok[dis[nxt[j]]]) tjc[j] = 1, ++ans;
            else if(nxt[j] == p1[dis[nxt[j]]] && tjc[nxt[j]]) tjc[j] = 1, ++ans;
            // cout << dis[j] << ' ';
        }
        // cout << '\n';
        // cout << "ANS:" <<  ans << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    for(cin >> C >> T; T; T--) solve();
    return 0;
}

// cd ~/HN-S00630/migrate && g++ -Wall -Wextra -O2 -std=c++14 migrate.cpp -o migrate && time ./migrate
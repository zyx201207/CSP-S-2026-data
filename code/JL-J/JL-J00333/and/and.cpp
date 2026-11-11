#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long dp[N], vis[N];
long long n, ans = 0, m;
long long a[N];

void dfs(int step, int anss) {
    if (step > m){
        ans = max(ans, anss);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            //cout << (step == 1 ? anss + a[i] : (anss & a[i])) << endl;
            dfs(step + 1, (step == 1 ? anss + a[i] : (anss & a[i])));
            vis[i]--;
        }
    }
}

void solve() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans;
}

int main() {
    int ac = 1;
    // cin >> ac;
    while(ac--) {
        solve();
    }
}

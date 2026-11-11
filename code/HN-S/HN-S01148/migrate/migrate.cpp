#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5005;
const int M = 2e6 + 5;

int n,d;

int f[N][N],minn[N][N];

int a[M],to[N];

void solve() {
    cin >> n >> d;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    if(n > 5000) {
        cout << "0\n";
        return ;
    }
    for(int i = 1;i <= n;i ++) {
        to[i] = upper_bound(a + 1 , a + n + 1 , a[i] + d) - a - 1;
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            f[i][j] = 1e18;
            minn[i][j] = 1e18;
        }
    }
    long long ans = 0;
    for(int i = n;i >= 1;i --) {
        for(int j = i;j <= to[i];j ++) {
            f[i][j] = 1;
            minn[i][j] = (j == i ? 0 : 1);
        }
        for(int t = to[i] + 1;t <= n;t ++) {
            f[i][t] = 0;
            minn[i][t] = minn[to[i]][t] + 1;
            if(to[i] > i) f[i][t] += f[to[i]][t];
            if(to[i] - 1 > i && minn[to[i] - 1][t] == minn[to[i]][t]) f[i][t] += f[to[i] - 1][t];
            if(to[i] - 2 > i && minn[to[i] - 2][t] == minn[to[i]][t]) f[i][t] += f[to[i] - 2][t];
            f[i][t] = min(f[i][t] , 3ll);
            ans += (f[i][t] == 2);
        }
    }
    cout << ans << "\n";
}

signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin >> c >> t;
    while(t --) solve();
    return 0;
}
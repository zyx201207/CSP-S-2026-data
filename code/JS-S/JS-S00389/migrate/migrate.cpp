#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;

const int N = 5005;
int n, d, x[N], way[N][N], f[N][N], val[N][N];
bool vis[N];
vector<int> e[N];

void dijk(int s) {
    memset(vis, false, sizeof vis);
    memset(val, 0, sizeof val);
    f[s][s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        for(auto v: e[u]) {
            if(f[s][v] > f[s][u] + 1) {
                f[s][v] = f[s][u] + 1;
                way[s][v] = 1;
                q.push({f[s][v], v});
            }
            if(f[s][v] == f[s][u] + 1) {
                way[s][v] += way[s][u]-val[u][v];
                val[u][v] = way[s][u];
                q.push({f[s][v], v});
            }
        }
    }
}

void work() {
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(x[j]-x[i] <= d)
                e[i].push_back(j);
        }
    }
    memset(f, 0x3f, sizeof f);
    for(int i=1;i<=n;i++)
        dijk(i);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(way[i][j] == 2)
                ans++;
        }
    }
    cout << ans+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--) { work(); }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) ^ 1)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int c, t, n, k, dp[5005][5005][3][2], vis[1000005], viss[1000005], u[1000005], v[1000005], dis[1000005];
vector<int> g[1000005];
signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i < n; i++){
            cin >> u[i] >> v[i];
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }
        if (c <= 3){
            int ans = 1e18;
            for (int s = 0; s < (1ll << n); s++){
                int cnt = 0;
                for (int i = 1; i <= n; i++) vis[i] = viss[i] = 0, dis[i] = 1e18;
                for (int i = 1; i <= n; i++){
                    if (s & (1ll << i - 1)){
                        vis[i] = 1;
                        cnt++;
                    }
                }
                if (cnt != k) continue;
                for (int i = 1; i < n; i++){
                    if (vis[u[i]] && vis[v[i]]) cnt--;
                }
                if (cnt <= 2){
                    queue<int> q;
                    for (int i = 1; i <= n; i++) if (vis[i]) q.push(i), viss[i] = 1, dis[i] = 0;
                    while (q.size()){
                        int x = q.front();
                        q.pop();
                        for (int i: g[x]){
                            if (viss[i]) continue;
                            viss[i] = 1;
                            dis[i] = dis[x] + 1;
                            q.push(i);
                        }
                    }
                    int mx = 0;
                    for (int i = 1; i <= n; i++) mx = max(mx, dis[i]);
                    ans = min(ans, mx);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}



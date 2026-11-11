#include<bits/stdc++.h>
#define in inline 
#define int long long 

using namespace std;
const int M = 55;
const int N = 5e5 + 5;
int c, n, m, d, Q, w[N], k[N], t[M][N], a[M][N], pos[2][N]; 
bool vis[2][N];

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> Q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)  cin >> a[i][j] >> t[i][j];
    }
    if(n == 2) {
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= k[i]; j++) {
                vis[i - 1][a[i][j]] = 1; 
                pos[i - 1][a[i][j]] = j;
            }
        }
        int s = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[0][i] && vis[1][i]) { s = i; break; }  
        } 
        for(int i = 1; i <= Q; i++) {
            int u, v, ans = 0; cin >> u >> v;
            if(vis[0][u] && vis[0][v]) {
                ans += w[u] + w[v] + t[1][pos[0][u]] + t[1][pos[0][v]];
            } else if(vis[1][u] && vis[1][v]) {
                ans += w[u] + w[v] + t[2][pos[1][v]] + t[2][pos[1][u]];
            } else if(vis[1][u] && vis[0][v]) {
                ans += w[u] + w[v] + t[1][pos[0][v]] + t[2][pos[1][u]] + t[1][pos[0][s]] + t[2][pos[1][s]];
            } else ans += w[u] + w[v] + t[2][pos[1][v]] + t[1][pos[0][u]] + t[1][pos[0][s]] + t[2][pos[1][s]];
            cout << ans << '\n'; 
        }
    }
    return 0;
}
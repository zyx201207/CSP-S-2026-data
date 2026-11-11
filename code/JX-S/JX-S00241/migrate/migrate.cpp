#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f, N = 205;
int c, t, n, d;
int w[N], dist[N][N], path[N][N];
void floyd(){
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            if(dist[i][j] == 1) continue;
            for(int k = 1;k <= n;++k){
                int tmp = dist[i][k] + dist[k][j];
                if(dist[i][j] == tmp) ++path[i][j];
                else if(dist[i][j] > tmp) dist[i][j] = tmp, path[i][j] = 1;
            }
        }
    }
}
void solve(){
    cin >> c >> t;
    while(t--){
        memset(dist, inf, sizeof(dist));
        cin >> n >> d;
        for(int i = 1;i <= n;++i){
            dist[i][i] = 1;
            cin >> w[i];
            for(int j = i - 1;j;--j){
                if(w[i] - w[j] <= d) dist[i][j] = dist[j][i] = 1;
                else break;
            }
        }
        floyd();
        int ans = 0;
        for(int i = 1;i <= n;++i){
            for(int j = i + 1;j <= n;++j){
                if(path[i][j] == 2) ++ans;
            }
        }
        printf("%lld\n", ans);
    }
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

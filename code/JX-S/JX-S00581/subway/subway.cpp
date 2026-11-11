#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3000, M = 5e5 + 5;
int n, m, cas, d, q;
int zt[M][25][2], b[M], ztcnt[M];
int dis[N][N];

signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> cas>> n>> m>> d>> q;
    for(int i = 1;i <= m;i++) cin>> b[i];
    for(int i = 1;i <= n;i++){
        int k; cin>> k;
        for(int j = 1;j <= k;j++){
            int x, t;
            cin>> x>> t;
            ++ztcnt[x];
            zt[x][ztcnt[x]][0] = i;
            zt[x][ztcnt[x]][1] = t;
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= ztcnt[i];j++){
            for(int k = j + 1;k <= ztcnt[i];k++){
                int u = zt[i][j][0], v = zt[i][k][0], c1 = zt[i][j][1], c2 = zt[i][k][1];
                dis[u][v] = min(dis[u][v], c1 + c2);
                dis[v][u] = dis[u][v];
            }
        }
    }
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
        for(int k = 1;k <= n;k++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = dis[i][j];
            }
        }
    }

    for(int i = 1;i <= q;i++){
        int u, v;
        cin>> u>> v;
        int ans = 1e18;
        for(int j = 1;j <= ztcnt[u];j++){
            for(int k = 1;k <= ztcnt[v];k++){
                int uu = zt[u][j][0], vv = zt[v][k][0];
                ans = min(ans, dis[uu][vv] + zt[u][j][1] + zt[v][k][1]);
            }
        }
        cout<< ans + b[u] + b[v]<< '\n';
    }
    return 0;
}

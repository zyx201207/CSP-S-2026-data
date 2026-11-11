#include<bits/stdc++.h>
#define int long long
#define N 1005
#define M 500005
using namespace std;
int c, n, m, d, q, k, xr, yr;
int w[M], a[M], t[M];
int vis[N][N], dis[N][N];
struct node{
    int y, z;
    bool operator < (const node w) const{
        return z > w.z;
    }
};
vector<node> g[M];
vector<node> v[N];
void dijkstra(int s){
    memset(dis[s], 0x3f, sizeof(dis[s]));
    memset(vis[s], 0, sizeof(vis[s]));
    priority_queue<node> q;
    q.push({s, 0}), dis[s][s] = 0;
    while(!q.empty()){
        node tmp = q.top(); q.pop();
        if(vis[s][tmp.y]){
            continue;
        }
        vis[s][tmp.y] = 1;
        for(auto i : v[tmp.y]){
            if(dis[s][i.y] > dis[s][tmp.y] + i.z){
                dis[s][i.y] = dis[s][tmp.y] + i.z;
                q.push({i.y, dis[s][i.y]});
            }
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> m >> n >> d >> q;
    if(c <= 11){
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> k;
            for(int j = 1; j <= k; j++){
                cin >> a[j] >> t[j];
            }
            for(int x = 1; x <= k; x++){
                for(int y = x + 1; y <= k; y++){
                    v[a[x]].push_back({a[y], t[x] + t[y]});
                    v[a[y]].push_back({a[x], t[x] + t[y]});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            dijkstra(i);
        }
        while(q--){
            cin >> xr >> yr;
            cout << dis[xr][yr] + w[xr] + w[yr] << "\n";
        }
        return 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        for(int i = 1; i <= m; i++){
            cin >> k;
            for(int j = 1; j <= k; j++){
                cin >> a[j] >> t[j];
                g[a[j]].push_back({i, t[j]});
            }
        }
        for(int i = 1; i <= n; i++){
            int len = g[i].size();
            for(int x = 0; x < len; x++){
                for(int y = x + 1; y < len; y++){
                    int xx = g[i][x].y, yy = g[i][y].y, ww = g[i][x].z + g[i][y].z;
                    v[xx].push_back({yy, ww}), v[yy].push_back({xx, ww});
                }
            }
        }
        for(int i = 1; i <= m; i++){
            dijkstra(i);
        }
        while(q--){
            cin >> xr >> yr;
            int ans = 1e18;
            for(auto i : g[xr]){
                for(auto j : g[yr]){
                    ans = min(ans, dis[i.y][j.y] + i.z + j.z);
                }
            }
            cout << ans + w[xr] + w[yr] << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 10, N = 510;
typedef pair<int,long long> pii;
typedef long long ll;
int c,n,m,q,d;
ll w[M];
ll dis[N][N];
vector<pii> subs[N];
vector<pii> stats[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m ; ++ i)cin >> w[i];
    for(int i = 1,k; i <= n ; ++ i){
        cin >> k;
        for(int j = 0,x,v; j < k ; ++ j){
            cin >> x >> v;
            subs[i].push_back({x,v});
            stats[x].push_back({i,v});
        }
    }
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1; j <= n ; ++ j){
            dis[i][j] = 1e15;
        }
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m ; ++ i){
        int l = stats[i].size();
        for(int j = 0; j < l ; ++ j){
            for(int k = j+1; k < l ; ++ k){
                int u = stats[i][j].first,v = stats[i][k].first;
                ll c = stats[i][j].second + stats[i][k].second;
                dis[u][v] = min(dis[u][v],c);
                dis[v][u] = min(dis[v][u],c);
            }
        }
    }
    for(int k = 1; k <= n ; ++ k){
        for(int i = 1; i <= n ; ++ i){
            for(int j = 1; j <= n ; ++ j){
                if(dis[i][k] + dis[k][j] <= dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    // for(int i = 1; i <= n ; ++ i){
    //     for(int j = 1; j <= n ; ++ j){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    while(q--){
        int l,r;
        cin >> l >> r;
        ll res = 1e18;
        for(int i = 0; i < stats[l].size(); ++ i){
            for(int j = 0; j < stats[r].size(); ++ j){
                res = min(res,dis[stats[l][i].first][stats[r][j].first]+w[l]+w[r]+stats[l][i].second + stats[r][j].second);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
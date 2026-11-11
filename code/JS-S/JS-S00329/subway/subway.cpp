#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x7f7f7f7f
#define LINF 0x3f3f3f3f3f3f3f3f
const int N = 500 + 10,M = 5e5 + 10;
ll dis[N][N],w[M];
int c,n,m,d,q;
struct edge{
    int v;
    ll t;
};
vector<edge> rail[N];
vector<edge> station[M];
void floyd(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            if(dis[i][k] == LINF) continue;
            for(int j = 1;j <= n;j++){
                if(dis[j][k] == LINF) continue;
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
                if(dis[j][i] > dis[j][k] + dis[k][i]){
                    dis[j][i] = dis[j][k] + dis[k][i];
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int v,t;
            cin >> v >> t;
            rail[i].push_back((edge){v,t});
            station[v].push_back((edge){i,t});
        }
    }
    memset(dis,LINF,sizeof(dis));
    for(int i = 1;i <= n;i++) dis[i][i] = 0;
    for(int i = 1;i <= n;i++){
        for(edge e : rail[i]){
            ll to = e.v,t = e.t;
            for(edge e2 : station[to]){
                ll r = e2.v,t2 = e2.t;
                if(r == i) continue;
                dis[i][r] = min(dis[i][r],t + t2);
                dis[r][i] = min(dis[r][i],t + t2);
            }
        }
    }
    floyd();
    //for(int i = 1;i <= n;i++){
   //     for(int j = 1;j <= n;j++){
   //         cout << "From " << i << " to " << j << ": " << dis[i][j] << '\n';
    //    }
   // }
    while(q--){
        int u,v;
        cin >> u >> v;
        ll ans = LINF;
        for(edge i : station[u]){
            for(edge j : station[v]){
                ans = min(ans,w[u] + i.t + dis[i.v][j.v] + j.t + w[v]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define il inline

const int N = 5e5 + 5,M = 505;
int c,m,n,dd,q,k,u,t,x,y,w[N],d[M][M];
vector<pii> f[N],g[M];

signed main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> n >> m >> dd >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> u >> t;
            f[u].push_back({i,t});
        }
    }
    for(int j = 1;j <= m;j++){
        for(int k = 0;k < f[j].size();k++){
            for(int l = 0;l < f[j].size();l++){
                if(k == l) continue;
                g[f[j][k].fi].push_back({f[j][l].fi,f[j][k].se + f[j][l].se});
                g[f[j][l].fi].push_back({f[j][k].fi,f[j][k].se + f[j][l].se});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        priority_queue<pii,vector<pii>,greater<pii>> q;
        for(int j = 1;j <= n;j++) d[i][j] = 1e15;
        q.push({d[i][i] = 0,i});
        while(q.size()){
            auto tmp = q.top();q.pop();
            int a = tmp.fi,u = tmp.se;
            if(d[i][u] == a){
                for(auto rp : g[u]){
                    int v = rp.fi,w = rp.se;
                    if(a + w < d[i][v]) q.push({d[i][v] = a + w,v});
                }
            }
        }
    }
    while(q--){
        int ans = 0,qqq = 1e15;
        cin >> x >> y;
        ans += w[x] + w[y];
        for(auto aa : f[x]){
            for(auto bb : f[y]){
                qqq = min(qqq,d[aa.fi][bb.fi] + aa.se + bb.se);
            }
        }
        ans += qqq;
        cout << ans << '\n';
    }

    return 0;
}

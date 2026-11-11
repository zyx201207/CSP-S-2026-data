#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
constexpr int N = 1e6+10,M = 510;
int c,n,m,d,q;
int w[N];
int a[N],t[N];
int f[M][M];
vector<pii> g[N];
void floyd(){
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
            }
        }
    }
}
void init(){
    memset(f,0x3f,sizeof f);
    for(int i = 1;i <= n;i++) f[i][i] = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 0;j < g[i].size();j++){
            for(int k = 0;k < g[i].size();k++){
                if(j == k) continue;
                int s = g[i][j].first,t = g[i][k].first,dist = g[i][j].second + g[i][k].second;
                f[s][t] = min(f[s][t],dist);
                f[t][s] = min(f[t][s],dist);
            }
        }
    }
    floyd();
}
void solve(){
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            int ver,tim;
            cin >> ver >> tim;
            g[ver].push_back({i,tim});
        }
    }
    init();
    while(q--){
        int s,t;
        cin >> s >> t;
        int ans = 1e18;
        for(int i = 0;i < g[s].size();i++){
            for(int j = 0;j < g[t].size();j++){
                ans = min(ans,g[s][i].second + g[t][j].second + f[g[s][i].first][g[t][j].first]);
            }
        }
        cout << ans + w[s] + w[t] <<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    //*
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //*/
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}

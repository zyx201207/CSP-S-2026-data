#include<bits/stdc++.h>
#define rep(i, j, k) for(int i=(j); i<=(k); i++)
#define per(i, j, k) for(int i=(j); i>=(k); i--)
#define debug(a...) _debug(#a, a)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
using namespace std;
#define int long long
template<class T> void _debug(const char *s, T x){cout<<s<<'='<<x<<endl;}
template<class T, class... Nxt> void _debug(const char *s, T x, Nxt... nxt){
    int d=0;
    while(d||*s!=',') d+=*s=='(', d-=*s==')', cout<<*s++;
    cout<<'='<<x<<',';
    _debug(s+1, nxt...);
}
void cmin(int &a, int b){if(a>b) a=b;}
void cmax(int &a, int b){if(a<b) a=b;}
const int N=503, M=5e5+5, inf=1e18;
int c, n, m, d, q, w[M], dis[N][N];
vector<pair<int, int>> G[M];

signed main(){
    file("subway");
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    rep(i, 1, m) cin>>w[i];
    rep(i, 1, n){
        int k;
        cin>>k;
        int u, t;
        while(k--){
            cin>>u>>t;
            G[u].emplace_back(i, t);
        }
    }
    rep(i, 1, n) rep(j, 1, n) dis[i][j]=inf;
    rep(i, 1, n) dis[i][i]=0;
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    rep(u, 1, m){
        for(auto [v1, w1]:G[u]) for(auto [v2, w2]:G[u]){
            if(v1==v2) break;
            cmin(dis[v1][v2], w1+w2);
        } 
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    rep(i, 1, n) rep(j, 1, n) cmin(dis[i][j], dis[j][i]);
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) cmin(dis[i][j], dis[i][k]+dis[k][j]);
    while(q--){
        int x, y;
        cin>>x>>y;
        int ans=inf;
        for(auto [vx, wx]:G[x]) for(auto [vy, wy]:G[y])
            cmin(ans, wx+wy+dis[vx][vy]);
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}
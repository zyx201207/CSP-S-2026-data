#include<bits/stdc++.h>
#define rep(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("subway.in");
ofstream ouf("subway.out");
using lint=long long;
static constexpr auto _infl=(lint)(1e18l);
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int c,n,m,d,q;inf>>c>>n>>m>>d>>q;
    vector<lint> w(m);
    for(auto&x:w) inf>>x;
    vector<vector<pair<int,lint>>> lines(m);
    rep(i,0,n){
        int k;inf>>k;
        rep(c,0,k){
            int p;lint t;inf>>p>>t;--p;
            lines[p].emplace_back(i,t);
        }
    }
    vector<vector<lint>> dis(n,vector<lint>(n,_infl));
    rep(i,0,n) dis[i][i]=0;
    rep(i,0,m){
        for(auto&[x,xt]:lines[i]) for(auto&[y,yt]:lines[i]){
            dis[x][y]=min(dis[x][y],xt+yt);
        }
    }
    rep(k,0,n) rep(i,0,n) rep(j,0,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    rep(i,0,q){
        int u,v;inf>>u>>v;--u;--v;
        auto ans=_infl;
        for(auto&[x,xt]:lines[u]) for(auto&[y,yt]:lines[v]) ans=min(ans,w[u]+w[v]+xt+yt+dis[x][y]);
        ouf<<ans<<'\n';
    }
    return 0;
}
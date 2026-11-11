#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define dbgblk if(1)
#else
#define dbgblk if(0)
#endif
#define dbg (cerr<<"["<<__LINE__<<"]:")
using ll=long long;
int c,n,m,d,q;
const int N=505,M=5e5+5;const ll inf=1e18;
array<vector<pair<int,ll>>,M>C;
array<array<ll,N>,N>dis;
inline void floyd(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
array<ll,M>w;
inline void sol(){
    for(int i=1;i<=m;++i){
        for(int j=0;j<C[i].size();++j){
            for(int k=j+1;k<C[i].size();++k){
            dis[C[i][j].first][C[i][k].first]=dis[C[i][k].first][C[i][j].first]=min(dis[C[i][j].first][C[i][k].first],C[i][j].second+C[i][k].second);
        }
        }
    }
    floyd();
}
inline ll qry(int a,int b){
    ll ans=inf;
    for(int i=0;i<C[a].size();++i){
        for(int j=0;j<C[b].size();++j){
            ans=min(ans,C[a][i].second+C[b][j].second+dis[C[a][i].first][C[b][j].first]);
        }
    }
    return ans+w[a]+w[b];
}
int main(){
    freopen("subway.in","r",stdin);
    dbgblk{freopen("subway.err","w",stderr);}
    freopen("subway.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;++i){for(int j=1;j<=n;++j)dis[i][j]=inf;dis[i][i]=0;}
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        int k;cin>>k;
        for(int j=1;j<=k;++j){
            int x;ll y;cin>>x>>y;
            C[x].push_back({i,y});
        }
    }
    sol();
    for(int i=1;i<=q;++i){
        int x,y;cin>>x>>y;
        cout<<qry(x,y)<<'\n';
    }
    return 0;
}

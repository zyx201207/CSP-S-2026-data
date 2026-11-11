#include<bits/stdc++.h>
using namespace std;
#define N 507
#define M 500007
#define int long long
int dp[N][N];
int c,n,m,d,q;
struct node{
    int v,w;
};
vector<node> g[M];
int w[M];

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int u,v;
            cin>>u>>v;
            g[u].push_back({i,v});
        }
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;++i){
        dp[i][i]=0;
    }
    for(int i=1;i<=m;++i){
        int l=g[i].size();
        for(int j=0;j<l;++j){
            for(int k=j+1;k<l;++k){
                auto u=g[i][j],v=g[i][k];
                dp[u.v][v.v]=min(dp[u.v][v.v],u.w+v.w);
                dp[v.v][u.v]=min(dp[v.v][u.v],u.w+v.w);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    // for(int i=1;i<=m;++i){
    //     cout<<g[i].size()<<'\n';
    //     for(auto v:g[i]){
    //         cout<<v.v<<' '<<v.w<<'\n';
    //     }
    // }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=2000000000000000ll;
        int l1=g[u].size(),l2=g[v].size();
        for(int i=0;i<l1;++i){
            for(int j=0;j<l2;++j){
                auto aa=g[u][i],bb=g[v][j];
                // cout<<aa.v<<' '<<bb.v<<'\n';
                ans=min(ans,aa.w+bb.w+dp[aa.v][bb.v]);
            }
        }
        ans+=w[u]+w[v];
        cout<<ans<<'\n';
    }
}

#include<bits/stdc++.h>
#define int long long
#define arr array<int,2>
using namespace std;
const int N=505,M=5e5+5,F=1e18;
int c,n,m,d,q,w[M];
int dis[N][N];
vector<arr>e[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
        cin>>w[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)dis[i][j]=F;
    for(int i=1,sz;i<=n;++i){
        cin>>sz;
        for(int j=1,u,t;j<=sz;++j){
            cin>>u>>t;
            for(arr it:e[u]){
                int j=it[0],z=dis[i][j];
                dis[i][j]=dis[j][i]=min(z,t+it[1]);
            }e[u].push_back({i,t});
        }
    }for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j&&i!=k&&j!=k)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int u,v;q;--q){
        cin>>u>>v;int ans=F;
        for(arr i:e[u])for(arr j:e[v])
            ans=min(ans,dis[i[0]][j[0]]+i[1]+j[1]);
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
vector<pair<int,int>>G[M];
int dis[N][N],w[M];
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;cin>>a>>t;
            G[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<G[i].size();j++){
            int u=G[i][j].first,d1=G[i][j].second;
            for(int k=0;k<G[i].size();k++){
                int v=G[i][k].first,d2=G[i][k].second;
                dis[u][v]=min(dis[u][v],d1+d2);
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        if(i!=j&&j!=k&&i!=k)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--){
        int x,y;cin>>x>>y;
        int ans=inf;
        for(int j=0;j<G[x].size();j++){
            int u=G[x][j].first,d1=G[x][j].second;
            for(int k=0;k<G[y].size();k++){
                int v=G[y][k].first,d2=G[y][k].second;
                ans=min(ans,d1+d2+dis[u][v]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}//O(md^2+n^3+qd^2)
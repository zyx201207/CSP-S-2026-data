#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 510
#define M 500010
int C,n,m,D,q,w[M],d[N][N];
vector<int>b[M],c[M];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;cin>>x>>y;
            b[x].push_back(i),c[x].push_back(y);
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)d[i][j]=1e18;
    for(int i=1;i<=m;i++)
        for(int j=0;j<b[i].size();j++)
            for(int k=j+1;k<b[i].size();k++){
                int u=b[i][j],v=b[i][k];
                d[u][v]=d[v][u]=min(d[u][v],c[i][j]+c[i][k]);
            }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        int x,y,ans=1e18;cin>>x>>y;
        for(int i=0;i<b[x].size();i++)
            for(int j=0;j<b[y].size();j++)
                ans=min(ans,d[b[x][i]][b[y][j]]+c[x][i]+c[y][j]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

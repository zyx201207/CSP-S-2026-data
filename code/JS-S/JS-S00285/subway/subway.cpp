#include<bits/stdc++.h>
#define int long long 
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
vector<array<int,2>>g[500010];
int c,n,m,d,q;
int dis[510][510],w[500010];
signed main(){
    file("subway");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dis[i][j]=4e18;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int k=g[i].size();
        for(int x=0;x<k;x++){
            array<int,2>a=g[i][x];
            for(int y=x+1;y<k;y++){
                array<int,2>b=g[i][y];
                dis[b[0]][a[0]]=dis[a[0]][b[0]]=min(dis[a[0]][b[0]],a[1]+b[1]);
            }
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        int ans=4e18;
        for(auto a:g[u])for(auto b:g[v]){
            ans=min(ans,a[1]+b[1]+dis[a[0]][b[0]]);
        }
        cout<<ans+w[u]+w[v]<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int p,t;
};
int c,n,m,d,q;
int w[500005];
int k[505];
vector<edge> a[505];
edge g[500005][25];
int pl[500005];
int dis[505][505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int u,v,z;
            u=i;
            cin>>v>>z;
            edge tmp;
            tmp.p=v;
            tmp.t=z;
            a[u].push_back(tmp);
            tmp.p=u;
            g[v][++pl[v]]=tmp;
        }
    }
    //x-d-x
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
            dis[i][i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=pl[i];j++){
            for(int k=j+1;k<=pl[i];k++){
                int u=g[i][j].p;
                int v=g[i][k].p;
                dis[u][v]=dis[v][u]=min(dis[u][v],g[i][j].t+g[i][k].t);
            }
        }
    }
    //x-x
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    //d-x-d
    while(q--){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(int i=1;i<=pl[x];i++){
            for(int j=1;j<=pl[y];j++){
                int u=g[x][i].p;
                int v=g[y][j].p;
                ans=min(ans,g[x][i].t+g[y][j].t+dis[u][v]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

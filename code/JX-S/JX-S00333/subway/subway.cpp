#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int M = 5e5 + 10,N = 505;
typedef long long ll;
ll G[N][N];
ll dis[N][N];
ll t[N][M];
ll w[M];
vector<int> subway[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        int v;
        for(int j=1;j<=k;j++){
            scanf("%d",&v);
            subway[v].push_back(i);
            scanf("%lld",&t[i][v]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G[i][j] = i==j?0:(1ll<<61);
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=0;i<subway[k].size();i++){
            for(int j=i+1;j<subway[k].size();j++){
                int u = subway[k][i],v = subway[k][j];
                G[u][v] = min(G[u][v],t[u][k]+t[v][k]);
                G[v][u] = G[u][v];

            }
        }
        /*
        for(int u=1;u<=n;u++){
            if(t[u][k]==-1)continue;
            for(int v=u+1;v<=n;v++){
                if(t[v][k]==-1) continue;
                G[u][v] = min(G[u][v],t[u][k]+t[v][k]);
                G[v][u] = G[u][v];
            }
        }*/
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j] = G[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        ll ans = 1ll<<61;
        for(int i=0;i<subway[x].size();i++){
            for(int j=0;j<subway[y].size();j++){
                int u = subway[x][i],v = subway[y][j];
                ans = min(ans,dis[u][v] + t[u][x] + t[v][y]);
            }
        }
        printf("%lld\n",ans + w[x] + w[y]);
    }
    return 0;
}

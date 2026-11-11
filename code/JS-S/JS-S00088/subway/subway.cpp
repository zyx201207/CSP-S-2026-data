#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510,M = 6e5+10,INF = 1e17+1;
int c,n,m,d,q;
int w[M];
struct edge{
    int to,w;
};
vector<edge> ver[M],g[N];
int dis[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%lld%lld",&a,&t);
            ver[a].push_back({i,t});
            g[i].push_back({a,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) dis[i][j]=INF;
            else dis[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int u=0;u<ver[i].size();u++){
            for(int v=u+1;v<ver[i].size();v++){
                int x=ver[i][u].to,y=ver[i][v].to;
                dis[x][y]=min(dis[x][y],ver[i][u].w+ver[i][v].w);
                dis[y][x]=dis[x][y];
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans=INF;
        for(int u=0;u<ver[x].size();u++){
            for(int v=0;v<ver[y].size();v++){
                ans=min(ans,ver[x][u].w+ver[y][v].w
                        +dis[ver[x][u].to][ver[y][v].to]);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}

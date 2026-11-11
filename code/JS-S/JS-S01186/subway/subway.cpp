#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int c,d;
LL w[500005],f[505][505];
int n,m,k[505];
vector<int> to[500005];
vector<LL> go[500005];
LL solve(int u,int v){
    LL ans=0x3f3f3f3f3f3f3f3fLL;
    for (int x=0;x<(int)(to[u].size());++x){
        for (int y=0;y<(int)(to[v].size());++y){
//cerr<<x<<" "<<y<<" "<<go[u][x]+go[v][y]+f[to[u][x]][to[v][y]]<<" test\n";
            ans=min(ans,go[u][x]+go[v][y]+f[to[u][x]][to[v][y]]);
        }
    }
    return ans;
}
void update(int u,int v,LL w){
    f[u][v]=min(f[u][v],w);
    f[v][u]=min(f[v][u],w);
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T,u,v;LL t;scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
    for (int i=1;i<=m;++i){scanf("%lld",w+i);}
    for (int i=1;i<=n;++i){
        scanf("%d",k+i);
        for (int j=1;j<=k[i];++j){
            scanf("%d%lld",&u,&t);
            to[u].push_back(i);
            go[u].push_back(t);
        }
    }
    memset(f,0x3f,sizeof f);
    for (int i=1;i<=n;++i){f[i][i]=0;}
    for (int i=1;i<=m;++i){
        for (int x=0;x<(int)(to[i].size());++x){
            for (int y=x+1;y<(int)(to[i].size());++y){
                update(to[i][x],to[i][y],go[i][x]+go[i][y]);
//cerr<<to[i][x]<<" "<<to[i][y]<<" "<<go[i][x]+go[i][y]<<"!!!!!\n";
            }
        }
    }
    for (int k=1;k<=n;++k){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    ++T;while (--T){scanf("%d%d",&u,&v);printf("%lld\n",solve(u,v)+w[u]+w[v]);}
    return 0;
}

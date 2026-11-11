#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500005];
ll dis[505][505];
int jl[500005][25];
int jcnt[500005];
int xl[500005][25];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            jcnt[a]++;
            jl[a][jcnt[a]]=t;
            xl[a][jcnt[a]]=i;
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=jcnt[i];j++){
            for(int k=j+1;k<=jcnt[i];k++){
                dis[xl[i][j]][xl[i][k]]=min(dis[xl[i][j]][xl[i][k]],0ll+jl[i][j]+jl[i][k]);
                dis[xl[i][k]][xl[i][j]]=min(dis[xl[i][k]][xl[i][j]],0ll+jl[i][j]+jl[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("i:%d j:%d dis:%lld\n",i,j,dis[i][j]);
        }
    }*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=w[x]+w[y];
        ll zxjl=0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=jcnt[x];i++){
            for(int j=1;j<=jcnt[y];j++){
                zxjl=min(zxjl,dis[xl[x][i]][xl[y][j]]+jl[x][i]+jl[y][j]);
            }
        }
        ans+=zxjl;
        printf("%lld\n",ans);
    }
    return 0;
}
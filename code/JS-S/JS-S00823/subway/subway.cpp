#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+3,inf=0x3f3f3f3f3f3f3f3f;
int T,n,m,d,q,sz[N];
long long dis[503][503],a[N];
struct node{
    int x;
    long long w;
}sta[N][22];
inline long long rd(){
    long long f=1,x=0;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar_unlocked();
    }
    while('0'<=c&&c<='9') x=x*10+c-'0',c=getchar_unlocked();
    return x*f;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    T=rd(),n=rd(),m=rd(),d=rd(),q=rd();
    for(int i=1;i<=m;i++) a[i]=rd();
    for(int i=1;i<=n;i++){
        int k,x,y;k=rd();
        while(k--) x=rd(),y=rd(),sta[x][++sz[x]]={i,y};
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=sz[i];j++){
            for(int k=j+1;k<=sz[i];k++){
                int x=sta[i][j].x,y=sta[i][k].x;
                dis[x][y]=min(sta[i][j].w+sta[i][k].w,dis[x][y]);
            }
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[j][i]);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)if(i^k){
            for(int j=1;j<=n;j++)if(i^j&&j^k){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;x=rd(),y=rd();
        long long res=inf;
        for(int i=1;i<=sz[x];i++){
            for(int j=1;j<=sz[y];j++){
                auto u=sta[x][i],v=sta[y][j];
                res=min(res,a[x]+a[y]+u.w+v.w+dis[u.x][v.x]);
            }
        }
        printf("%lld\n",res);
    }
}

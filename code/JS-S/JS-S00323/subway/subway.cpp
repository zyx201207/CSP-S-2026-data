#include <iostream>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10,D=21;const ll inf=1e18;
int c,n,m,d,q,w[M],sz[M],out[M][D];ll a[M][D],F[N][N],ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)F[i][j]=(i==j?0:inf);
    for(int i=1;i<=m;++i)scanf("%d",&w[i]);
    for(int i=1,k,x,t;i<=n;++i){
        scanf("%d",&k);
        while(k--)scanf("%d%d",&x,&t),++sz[x],out[x][sz[x]]=i,a[x][sz[x]]=t;
    }
    for(int id=1;id<=m;++id)
        for(int i=1,x=out[id][i];i<=sz[id];x=out[id][++i])
            for(int j=1,y=out[id][j];j<=sz[id];y=out[id][++j])
                F[y][x]=F[x][y]=min(F[x][y],a[id][i]+a[id][j]);//O(md^2)
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                F[i][k]=min(F[i][k],F[i][j]+F[j][k]);//O(n^3)
    for(int s,t;q--;){//O(qd^2)
        scanf("%d%d",&s,&t),ans=inf;
        for(int i=1,x=out[s][i];i<=sz[s];x=out[s][++i])
            for(int j=1,y=out[t][j];j<=sz[t];y=out[t][++j])
                ans=min(ans,w[s]+a[s][i]+F[x][y]+a[t][j]+w[t]);
        printf("%lld\n",ans);
    }
    return 0;
}
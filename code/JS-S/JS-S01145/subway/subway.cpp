#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int CCFILOVEYOU,n,m,d,q,w[500005],tot[500005],a[500005][25],t[500005][25];
ll dis[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&CCFILOVEYOU,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++){
        int k,aa,tt;
        scanf("%d",&k);
        while(k--){
            scanf("%d%d",&aa,&tt);
            a[aa][++tot[aa]]=i,t[aa][tot[aa]]=tt;
        }
    }
    for(int i=1;i<=m;i++)for(int j=1;j<tot[i];j++)for(int k=j+1;k<=tot[i];k++)
        dis[a[i][j]][a[i][k]]=min(dis[a[i][j]][a[i][k]],(ll)t[i][j]+t[i][k]),
        dis[a[i][k]][a[i][j]]=min(dis[a[i][k]][a[i][j]],(ll)t[i][j]+t[i][k]);
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=1e18;
        for(int i=1;i<=tot[x];i++)for(int j=1;j<=tot[y];j++)
            ans=min(ans,dis[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
        printf("%lld\n",ans+w[x]+w[y]);
    }
}

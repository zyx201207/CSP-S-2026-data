#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,u,v,kk,len[500005],sw[500005][25];
long long w[500005],t[500005][25],dis[505][505],ans;
bool flag;
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for (int i=1;i<=n;i++) {
        scanf("%d",&kk);
        for (int j=1;j<=kk;j++) {
            scanf("%d%d",&u,&v);
            len[u]++;
            t[u][len[u]]=v;
            sw[u][len[u]]=i;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=len[i];j++) {
            for (int k=1;k<j;k++) {
                dis[sw[i][j]][sw[i][k]]=min(dis[sw[i][j]][sw[i][k]],t[i][j]+t[i][k]);
                dis[sw[i][k]][sw[i][j]]=dis[sw[i][j]][sw[i][k]];
            }
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            if (dis[i][k]==0x3f3f3f3f3f3f3f3f) continue;
            for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int i=1;i<=q;i++) {
        scanf("%d%d",&u,&v);
        ans=0x3f3f3f3f3f3f3f3f;
        for (int j=1;j<=len[u];j++) for (int k=1;k<=len[v];k++) ans=min(ans,dis[sw[u][j]][sw[v][k]]+t[u][j]+t[v][k]);
        ans+=w[u]+w[v];
        printf("%lld\n",ans);
    }
    return 0;
}

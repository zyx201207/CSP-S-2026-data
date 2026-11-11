#include<bits/stdc++.h>
#define int long long
#define N 505
#define M 500005
#define INF (1e14)
using namespace std;
int x[M],f[N][N],L[M],id[M][21],val[M][21];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&x[i]);
    for(int i=1;i<=n;i++){
        int l;
        scanf("%lld",&l);
        for(int j=1;j<=l;j++){
            int u,v;
            scanf("%lld%lld",&u,&v);
            L[u]++;
            id[u][L[u]]=i;
            val[u][L[u]]=v;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=INF;
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++)for(int j=1;j<=L[i];j++)for(int k=j+1;k<=L[i];k++){
        int u=id[i][j],v=id[i][k];
        f[u][v]=f[v][u]=min(f[u][v],val[i][j]+val[i][k]);
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
    while(q--){
        int s,t;
        scanf("%lld%lld",&s,&t);
        int res=INF;
        for(int i=1;i<=L[s];i++)for(int j=1;j<=L[t];j++)res=min(res,f[id[s][i]][id[t][j]]+val[s][i]+val[t][j]);
        printf("%lld\n",res+x[s]+x[t]);
    }
    return 0;
}
//Igunareo ver.

//chutirenheyiwei
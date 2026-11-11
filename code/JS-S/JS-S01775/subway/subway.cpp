#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,ans,a,b,dis[505][505],x,y;
vector<long long>v[500005],o[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;++i)
        scanf("%lld",&w[i]);
    for(long long i=1;i<=n;++i){
            scanf("%lld",&k);
            for(long long j=1;j<=k;++j){
                scanf("%lld",&a);
                scanf("%lld",&b);
                v[a].push_back(i);
                o[a].push_back(b);
            }
    }
    memset(dis,0x3f3f3f3f3f,sizeof(dis));
    for(long long i=1;i<=m;++i)
        for(long long j=0;j<v[i].size();++j)
            for(long long k=j+1;k<v[i].size();++k)
                dis[v[i][j]][v[i][k]]=dis[v[i][k]][v[i][j]]=min(dis[v[i][k]][v[i][j]],o[i][j]+o[i][k]);
    for(long long i=1;i<=n;++i)
        dis[i][i]=0;
    for(long long k=1;k<=n;++k)
        for(long long i=1;i<=n;++i)
            for(long long j=i+1;j<=n;++j)
                if((k!=i)&&(k!=j)){
                    dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
    while(q--){
        ans=922337203700000000;
        scanf("%lld%lld",&x,&y);
        for(long long i=0;i<v[x].size();++i)
             for(long long j=0;j<v[y].size();++j)
                ans=min(ans,dis[v[x][i]][v[y][j]]+o[x][i]+o[y][j]+w[x]+w[y]);
        printf("%lld\n",ans);
    }
    return 0;
}

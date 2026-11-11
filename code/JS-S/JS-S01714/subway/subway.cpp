#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[510],dis[510][510];
vector<long long>a[510],t[510];
vector<pair<long long,long long> >vct[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++) scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        scanf("%lld",k+i);
        a[i].resize(k[i]+1);
        t[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            vct[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(int i=1;i<=m;i++){
        long long len=vct[i].size();
        for(int j=0;j<len;j++){
            long long u=vct[i][j].first,w=vct[i][j].second;
            for(int l=0;l<j;l++){
                long long v=vct[i][l].first,w1=vct[i][l].second;
                dis[u][v]=min(dis[u][v],w+w1);
                dis[v][u]=min(dis[v][u],w+w1);
            }
        }
    }
    for(int i=1;i<=n;i++) for(int u=1;u<=n;u++) for(int v=1;v<=n;v++) dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
    while(q--){
        long long s,t,res=1e18;
        scanf("%lld%lld",&s,&t);
        for(int i=0;i<(int)vct[s].size();i++){
            for(int j=0;j<(int)vct[t].size();j++){
                long long u=vct[s][i].first,v=vct[t][j].first,w=vct[s][i].second+vct[t][j].second;
                res=min(res,dis[u][v]+w);
            }
        }
        printf("%lld\n",res+w[s]+w[t]);
    }
    return 0;
}
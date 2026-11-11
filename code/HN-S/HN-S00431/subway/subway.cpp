#include<bits/stdc++.h>
using namespace std;
const long long inf=1e17;
int c,n,m,d,q;
vector<pair<int,long long>> ve[500100];
long long dis[510][510],w[500100];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        int kkk;
        scanf("%d",&kkk);
        while(kkk--){
            int a,v;
            scanf("%d%d",&a,&v);
            ve[a].push_back({i,v});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=inf;
    for(int i=1;i<=m;i++){
        for(auto a : ve[i])
        for(auto b : ve[i])
            dis[a.first][b.first]=min(dis[a.first][b.first],a.second+b.second);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=inf;
        for(auto a : ve[x])
            for(auto b : ve[y])
                ans=min(ans,dis[a.first][b.first]+a.second+b.second);
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
#include<cstdio>
#include<vector>
#include<utility>
#define N 500005
int CID,n,m,d,q,w[N],k,A,T;
long long f[505][505];
std::vector<std::pair<int,int> >G[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&CID,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        while(k--)scanf("%d%d",&A,&T),G[A].push_back({i,T});
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=2e18;
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(std::pair<int,int>a:G[i])for(std::pair<int,int>b:G[i])if(f[a.first][b.first]>a.second+b.second)f[a.first][b.first]=a.second+b.second;
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j]>f[k][i]+f[k][j])f[i][j]=f[k][i]+f[k][j];
    while(q--){
        int u,v;long long ans=2e18;
        scanf("%d%d",&u,&v);
        for(std::pair<int,int>a:G[u])for(std::pair<int,int>b:G[v])if(ans>f[a.first][b.first]+a.second+b.second+w[u]+w[v])ans=f[a.first][b.first]+a.second+b.second+w[u]+w[v];
        printf("%lld\n",ans);
    }
}
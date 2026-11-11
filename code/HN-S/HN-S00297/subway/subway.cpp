#include<bits/stdc++.h>
using int_64=long long;

constexpr int M=5e5,N=500;
constexpr int_64 INF=4557430888798830399;

int w[M+5];
struct Station{int id,t;};
std::vector<Station>in[M+5];
int_64 dist[N+5][N+5];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // freopen("subway.log","w",stderr);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    int c,n,m,d,q;
    std::cin>>c>>n>>m>>d>>q;
    memset(dist,63,sizeof dist);
    for(int i=1;i<=n;++i)dist[i][i]=0;
    for(int i=1;i<=m;++i)std::cin>>w[i];
    for(int i=1,k;i<=n;++i)
    {
        std::cin>>k;
        for(int j=1,a,t;j<=k;++j)
        {
            std::cin>>a>>t;
            for(const auto &s:in[a])
                dist[s.id][i]=dist[i][s.id]=std::min(dist[s.id][i],(int_64)(s.t+t));
            in[a].push_back({i,t});
        }
    }

    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
        dist[i][j]=std::min(dist[i][j],dist[i][k]+dist[j][k]);

    while(q--)
    {
        int x,y;
        std::cin>>x>>y;
        int_64 min_cost=INF;
        for(const auto &s1:in[x])for(const auto &s2:in[y])
            min_cost=std::min(min_cost,dist[s1.id][s2.id]+s1.t+s2.t);
        std::cout<<w[x]+w[y]+min_cost<<'\n';
    }
}
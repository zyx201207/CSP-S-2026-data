#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st
{
    int a,jl;
};
int c,n,m,d,q,x,y,ans,w[500010],kk[510],mn[510][510];
vector<st>v[500010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q,memset(mn,0x3f,sizeof(mn));
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>kk[i],mn[i][i]=0;
        for(int j=1;j<=kk[i];j++)
            cin>>x>>y,v[x].push_back({i,y});
    }
    for(int i=1;i<=m;i++)
        for(st j:v[i])
            for(st k:v[i])
                if(j.a!=k.a)
                    mn[j.a][k.a]=mn[k.a][j.a]=min(mn[j.a][k.a],j.jl+k.jl);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&j!=k&&i!=k)
                    mn[i][j]=min(mn[i][j],mn[i][k]+mn[k][j]);
    while(q--)
    {
        cin>>x>>y;
        int ans=1e18;
        for(st i:v[x])
            for(st j:v[y])
                ans=min(ans,mn[i.a][j.a]+i.jl+j.jl);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2 -Wall
*/
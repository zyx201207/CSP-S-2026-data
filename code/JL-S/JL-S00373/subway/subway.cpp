#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int f[507][507],w[N];
vector<pair<int,int>>point[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(f,0x3f,sizeof f);

    int c,n,m,d,q,cnt=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int a,t;
            cin>>a>>t;
            point[a].push_back({i,t});
        }
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=0;i<point[k].size();i++)
            for(int j=i+1;j<point[k].size();j++)
            {
                auto[u1,v1]=point[k][i];
                auto[u2,v2]=point[k][j];
                f[u1][u2]=v1+v2;
                f[u2][u1]=v1+v2;
            }
    }
    for(int i=1;i<=n;i++)
        f[i][i]=0;

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(i!=k)
            for(int j=1;j<=n;j++) if(j!=k&&i!=k&&f[i][k]+f[k][j]<f[i][j])
                f[i][j]=f[i][k]+f[k][j];

    while(q--)
    {
        int x,y,ans=1e18;
        cin>>x>>y;
        for(auto [u,lhc]:point[x])
            for(auto [v,cxy]:point[y])
                ans=min(ans,w[x]+w[y]+lhc+cxy+f[u][v]);
        cout<<ans<<'\n';
    }
    return 0;
}

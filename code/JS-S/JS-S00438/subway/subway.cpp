#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,wdis[505][505];
//wdis[i][j]:地铁线路i到j的最短路
struct sta
{
    int w;
    vector<pair<int,int> >way;
}stas[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //freopen("subawy.in","w",stdin);        诈骗
    //freopen("subway2.out","r",stdout);     诈骗
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>stas[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x,y;
            cin>>x>>y;
            stas[x].way.push_back(make_pair(i,y));
        }
    }
    memset(wdis,0x3f,sizeof(wdis));
    for(int i=1;i<=m;i++)
    {
        for(auto j:stas[i].way)
        {
            for(auto k:stas[i].way)
            {
                wdis[j.first][k.first]=min(wdis[j.first][k.first],j.second+k.second);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            for(int k=1;k<=n;k++)
            {
                if(k==i||k==j)
                {
                    continue;
                }
                wdis[i][j]=min(wdis[i][j],wdis[i][k]+wdis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        wdis[i][i]=0;
    }
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        int ans=0x3f3f3f3f3f3f3f3f;
        for(auto j:stas[u].way)
        {
            for(auto k:stas[v].way)
            {
                ans=min(ans,wdis[j.first][k.first]+j.second+k.second+stas[u].w+stas[v].w);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

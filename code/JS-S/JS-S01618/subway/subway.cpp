#include<bits/stdc++.h>
using namespace std;

int w[500001];
struct sta{
    int sub;
    long long ti;
};
vector<sta>g[500001];
long long h[501][501];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int a,t;
            cin>>a>>t;
            g[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            for(int k=j+1;k<g[i].size();k++)
            {
                if(h[g[i][j].sub][g[i][k].sub]==0)
                {
                    h[g[i][j].sub][g[i][k].sub]=g[i][j].ti+g[i][k].ti;
                }else{
                    h[g[i][j].sub][g[i][k].sub]=min(h[g[i][j].sub][g[i][k].sub],g[i][j].ti+g[i][k].ti);
                }
                h[g[i][k].sub][g[i][j].sub]=h[g[i][j].sub][g[i][k].sub];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(h[i][k]!=0&&h[k][j]!=0)
                {
                    if(h[i][j]==0)
                    {
                        h[i][j]=h[i][k]+h[k][j];
                    }else{
                        h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
                    }
                    h[j][i]=h[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        h[i][i]=0;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=LONG_LONG_MAX;
        for(int i=0;i<g[x].size();i++)
        {
            for(int j=0;j<g[y].size();j++)
            {
                ans=min(ans,h[g[x][i].sub][g[y][j].sub]+g[x][i].ti+g[y][j].ti);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

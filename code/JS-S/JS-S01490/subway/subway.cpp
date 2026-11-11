#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[25005],k[505],a[505][1005],t[505][1005];
vector<pair<int,int>>g[505];
int x,y;
void dfs(int u)
{
    if(u==y)
    {
        return;
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
        for(int j=1;j<=k[i];j++)
            for(int p=j+1;p<=k[i];p++)
            {
                if(g[a[i][j]].size()==0)
                    g[a[i][j]].push_back({a[i][p],t[i][j]+t[i][p]}),
                    g[a[i][p]].push_back({a[i][j],t[i][j]+t[i][p]});

            }
    }
    while(q--)
    {
        int ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        dfs(x);
    }
    return 0;
}

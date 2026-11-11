#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
int xr,yr;
int w[500005];
int cnt[505];
int dp[505];
int dist[505][505];
int minn=inf;
vector<int> pos[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>cnt[i];
        for(int j=1;j<=cnt[i];j++)
        {
            int u,t;
            cin>>u>>t;
            if(i==u)dp[i]=t;
            else dist[i][j]=t;
            pos[u].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]!=0)
            {
                dist[i][j]+=dist[j][i];
                dist[j][i]=dist[i][j];
            }
            else if(i!=j) dist[i][j]=inf;
            else dist[i][j]=0;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    while(q--)
    {
        cin>>xr>>yr;
        minn=inf;
        for(int i=0;i<pos[xr].size();i++)
        {
            for(int j=0;j<pos[yr].size();j++)
            {
                minn=min(minn,dp[pos[xr][i]]+dist[pos[xr][i]][pos[yr][j]]+w[xr]+w[yr]);
            }
        }
        cout<<minn<<"\n";
    }
    return 0;
}

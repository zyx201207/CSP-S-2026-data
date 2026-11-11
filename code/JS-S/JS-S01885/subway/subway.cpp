#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[1010][1010];
int w[1010];
int k[1010];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    vector<pair<int,int>>p[1010];
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> k[i];
        for(int j=1;j<=k[i];j++)
        {
            int a,t;
            cin >> a >> t;
            p[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=1e18;
            
        }
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<p[i].size();j++)
        {
            for(int e=j+1;e<p[i].size();e++)
            {
                dis[p[i][j].first][p[i][e].first]=min(dis[p[i][j].first][p[i][e].first],p[i][j].second+p[i][e].second);
                dis[p[i][e].first][p[i][j].first]=min(dis[p[i][e].first][p[i][j].first],p[i][j].second+p[i][e].second);
            }
        }
    }
    // cout << dis[1][3] << endl;
    // for(int i=0;i<p[2].size();i++)
    // {
    //     cout << p[2][i].first << " " << p[2][i].second << " ";
    // }
    // cout << endl;
    for(int f=1;f<=n;f++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][f]+dis[f][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][f]+dis[f][j];
                }
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,t;
        cin >> s >> t;
        int minn=INT_MAX;
        for(int j=0;j<p[s].size();j++)
        {
            for(int e=0;e<p[t].size();e++)
            {
                int jp=p[s][j].first;
                int ep=p[t][e].first;
                minn=min(dis[jp][ep]+p[s][j].second+p[t][e].second+w[s]+w[t],minn);
            }
        }
        cout << minn << endl;
    }
    return 0;
}
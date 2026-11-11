#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000005],k[1000005],t[500005][505];
int dis[2500005];
vector<pair<int,int> >v[2500005];
vector<int>que[505];
priority_queue<pair<int,int>,greater<pair<int,int> > >qq;
int dij(int x,int y)
{
    qq.push({x,0});
    memset(dis,0x3f,sizeof(dis));
    dis[x]=0;
    while (!qq.empty())
    {
        pair<int,int>now=qq.top();
        qq.pop();
        for (int i=0;i<v[now.first].size();i++)
        {
            int here=v[now.first][i].first;
            if (dis[here]<=dis[now.first]+v[now.first][i].second)
            {
                continue;
            }
            dis[here]=dis[now.first]+v[now.first][i].second;
            qq.push({here,dis[here]});
        }
    }
    return dis[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    for (int i=1;i<=n;i++)
    {
        int k,now[1000005];
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            cin >> now[j] >> t[now[j]][i];
            que[i].push_back(now[j]);
        }
        for (int j=1;j<=k;j++)
        {
            for (int e=k+1;e<=k;e++)
            {
                v[(i-1)*m+now[j]].push_back({(i-1)*m+now[e],0});
                v[(i-1)*m+now[e]].push_back({(i-1)*m+now[j],0});
            }
        }

    }
    for (int i=1;i<=m;i++)
    {
        for (int j=i+1;j<=m;j++)
        {
            for (int k=0;k<que[i].size();k++)
            {
                int now=que[i][k];
                if (t[now][j]!=0)
                {
                    v[(i-1)*m+now].push_back({(j-1)*m+now,t[now][i]+t[now][j]});
                    v[(j-1)*m+now].push_back({(i-1)*m+now,t[now][i]+t[now][j]});
                }
            }
        }
    }
    while (q--)
    {
        int x,y;
        cout << w[x]+w[y]+dij(x,y) << endl;
    }
    return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/

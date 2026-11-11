#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,qq,w[500005];
vector<pair<int,int>>edge[25050007];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
long long dis[25050007];

long long solve(int s,int t)
{
    for(int i=1;i<=(n+1)*m;i++)
    {
        dis[i]=9982443539824435;
    }
    while(!q.empty())
    {
        q.pop();
    }
    dis[m*n+s]=0;
    q.push(make_pair(0,m*n+s));
    while(!q.empty())
    {
        int u=q.top().second;
        int cost=q.top().first;
        q.pop();
        for(int i=0;i<edge[u].size();i++)
        {
            int to=edge[u][i].second;
            int v=edge[u][i].first;
            if(dis[u]+v<dis[to])
            {
                dis[to]=dis[u]+v;
                q.push(make_pair(dis[u]+v,to));
            }
        }
    }
    return (dis[m*n+t]>1000000000000000?-1:dis[m*n+t]);
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int lst;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            edge[(i-1)*m+a].push_back(make_pair(t,n*m+a));
            edge[n*m+a].push_back(make_pair(t,(i-1)*m+a));
            if(j!=1)
            {
                edge[(i-1)*m+a].push_back(make_pair(0,(i-1)*m+lst));
                edge[(i-1)*m+lst].push_back(make_pair(0,(i-1)*m+a));
            }
            lst=a;
        }
    }
    while(qq--)
    {
        int s,t;
        cin>>s>>t;
        cout<<solve(s,t)+w[s]+w[t]<<'\n';
    }
    return 0;
}

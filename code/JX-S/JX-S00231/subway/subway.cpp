#include<bits/stdc++.h>
using namespace std;
int w[500005],x[500005];
vector<int>a[505],b[25];
map<int,vector<pair<int,int> > >vec;
int dis[500005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dijk(int s)
{
    q.push({0,s});
    memset(dis,0x3f,sizeof dis);
    dis[s]=w[s];
    while(q.size())
    {
        pair<int,int>p=q.top();
        q.pop();
        int p2=p.second;
        for(auto k:vec[p2])
        {
            int k1=k.first,k2=k.second;
            if(dis[k1]>dis[p2]+k2)
            {
                dis[k1]=dis[p2]+k2;
                q.push({dis[k1],k1});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t,n,m,d,q;
    scanf("%d%d%d%d%d",&t,&n,&m,&d,&q);
    for(int i=1;i<=m;++i) scanf("%d",&w[i]);
    for(int i=1;i<=n;++i)
    {
        int g;
        scanf("%d",&g);
        for(int j=1;j<=g;++j)
        {
            int ax;
            scanf("%d%d",&ax,&x[i]);
            a[j].push_back(ax);
            b[ax].push_back(j);
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<b[i].size();++j)
        {
            for(int k=j+1;k<b[i].size();++k) vec[j].push_back({k,x[b[i][j]]+x[b[i][k]]}),vec[k].push_back({j,x[b[i][j]]+x[b[i][k]]});
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<a[i].size();++j)
        {
            for(int k=j+1;k<a[i].size();++k) vec[j].push_back({k,0}),vec[k].push_back({j,0});
        }
    }
    for(int i=1;i<=q;++i)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        dijk(s);
        printf("%d\n",dis[t]);
    }
    return 0;
}

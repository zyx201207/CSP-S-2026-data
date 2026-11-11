#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
int c,n,m,q,d;
int const N=5e5+5;
vector<pair<int,int> >g[N];
int w[N];
long long ans;
long long dis[N];
void build(int x,int y,int val)
{
    g[x].push_back(make_pair(y,val));
    g[y].push_back(make_pair(x,val));
}
void P()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(auto k:g[j+i*m])
            {
                cout<<k.first<<" "<<k.second<<endl;
            }
            cout<<endl;
        }
    }
}
void dijstra(int s,int t)
{
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >que;
    memset(dis,0x3f3f,sizeof dis);
    dis[s]=0;
    que.push(make_pair(0,s));
    while(!que.empty())
    {
        pair<int,int>tmp(que.top());
        que.pop();
        int u=tmp.second;
        for(auto nxt:g[u])
        {
            int v=nxt.first;
            if(dis[u]+nxt.second<dis[v])
            {
                dis[v]=dis[u]+nxt.second;
                que.push(make_pair(-dis[v],v));
            }
        }
    }
    cout<<dis[t]+w[s]+w[t]<<endl;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int x,val,prex;
        cin>>x>>val;
        prex=x;
        build(x,x+i*m,val);
        for(int j=1;j<k;j++)
        {
            cin>>x>>val;
            build(x,x+i*m,val);
            build(x+i*m,prex+i*m,0);
            prex=x;
        }
    }
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        dijstra(s,t);
    }
    return 0;
}

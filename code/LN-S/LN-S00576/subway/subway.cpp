#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,D=25,M=500005;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct edge
{
    int to;
    ll w;
};
struct cmp
{
    bool operator()(const edge &a,const edge &b)const{
        return a.w>b.w;
    }
};
vector<vector<edge>> e(M*2+N);
int c,b,n,m,d,q,x,y;
ll t1[M],a[500005],t[500005];
ll dijkstra()
{
    vector<ll> dist(M*2+N,INF);
    dist[(x-1)*2+1]=0;
    priority_queue<edge,vector<edge>,cmp> pq;
    pq.push({(x-1)*2+1,0});
    while(!pq.empty())
    {
        auto cur=pq.top();
        pq.pop();
        int u=cur.to;
        if(cur.w>dist[u]) continue;
        for(auto &p:e[u])
        {
            if(dist[p.to]>dist[u]+p.w)
            {
                dist[p.to]=dist[u]+p.w;
                pq.push({p.to,dist[p.to]});
            }
        }
    }
    return dist[(y-1)*2+1];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        int nn=i-1;
        cin>>t1[i];
        e[nn*2+2].push_back({nn*2+1,t1[i]});
        e[nn*2+1].push_back({nn*2+2,t1[i]});
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>t[j];
            int nj=a[j]-1;//a[j]为第ℹ条线路到第a[j]个站台，2*n+i为第i个站台
            e[nj*2+2].push_back({2*m+i,t[j]});
            e[2*m+i].push_back({nj*2+2,t[j]});
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<dijkstra()<<endl;
    }
    return 0;
}

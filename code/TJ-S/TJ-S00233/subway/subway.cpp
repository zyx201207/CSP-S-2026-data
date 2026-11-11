#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int c,n,m,d,q,laste[600005],cnt,dis[600005],add[500005];
struct edge
{
    int v,w,nxt;
}e[1000005];
void adde(int u,int v,int w)
{
    e[++cnt].v=v;
    e[cnt].nxt=laste[u];
    e[cnt].w=w;
    laste[u]=cnt;
    return;
}
struct pt
{
    int u,sum;
};
struct cmp
{
    bool operator()(const pt&a,const pt&b)const
    {
        return a.sum>b.sum;
    }
};
priority_queue<pt,vector<pt>,cmp> pq;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>add[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int v,w;
            cin>>v>>w;
            adde(m+i,v,w);
            adde(v,m+i,w);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int in,out;
        cin>>in>>out;
        for(int j=1;j<=n+m;j++) dis[j]=inf;
        pq.push({in,0});
        while(!pq.empty())
        {
            pt nw=pq.top();
            pq.pop();
            int u=nw.u,val=nw.sum;
            if(val>=dis[u]) continue;
            dis[u]=val;
            for(int i=laste[u];i;i=e[i].nxt)
            {
                int v=e[i].v,w=e[i].w;
                if(dis[v]>dis[u]+w)
                {
                    pq.push({v,dis[u]+w});
                }
            }
        }
        cout<<dis[out]+add[in]+add[out]<<'\n';
    }
	return 0;
 }

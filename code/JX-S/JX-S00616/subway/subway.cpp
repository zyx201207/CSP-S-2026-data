#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int c,n,m,d,q;
int w,k,x[N],t[N];
struct egde
{
    int nxt,to,val;
} e[N*4];
int tot,head[4*N],dist[4*N];
bool vis[N];
void add(int u,int v,int w)
{
    e[++tot].nxt=head[u];
    e[tot].to = v;
    e[tot].val= w;
    head[u]=tot;
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1; i<=m; ++i)
    {
        cin>>w;
        add(i,i+m,w);
        add(i+m,i,w);
    }
    for(int i= 1; i<=n; i++)
    {
        int k,x,t;
        cin>>k;
        for(int j = 1; j<=k; j++)
        {
            cin>>x>>t;
            add(m+x,2*m+i,t);
            add(2*m+i,m+x,t);
        }
    }
    for(int i = 1; i<=q; i++)
    {
        int x,y;
        cin>>x>>y;
        memset(dist,0x3f,sizeof dist);
        memset(vis,0,sizeof vis);
        priority_queue<pair<int,int>> pq;
        pq.push({0,x});
        dist[x]=0;
        while(pq.size())
        {
            int u = pq.top().second;
            pq.pop();
            if(u==y) break;
            if(vis[u]) continue;
            vis[u]= true;
            for(int i= head[u]; i; i = e[i].nxt)
            {
                int v = e[i].to,w = e[i].val;
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    pq.push({-dist[v],v});
                }
            }
        }
        cout<<dist[y]<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt=0;
long long w[500005];
int s[100002],e[100002];
int node[500505],edge_nxt[500005],edge_to[500005],edge_v[500005];
queue <int> q;
bool inq[500505];
void ins(int u,int v,int va)
{
    edge_nxt[++cnt]=node[u];
    edge_to[cnt]=v;
    edge_v[cnt]=va;
    node[u]=cnt;
    return;
}
void spfa(int st,int ed)
{

    q.clear();
    q.push(st);
    inq[st]=1;
    int now,dis[500505];
    memset(dis,10000,sizeof(dis));
    dis[ed]=0;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        inq[now]=0;
        for(int i=node[now]; i!=-1; i=edge_nxt[i])
        {
            if(dis[edge_to[i]]>dis[now])
            {
                dis[edge_to[i]]=dis[now];
                if(!inq[edge_to[i]])
                    q.push(edge_to[i]);
                inq[edge_to[i]]=1;
            }
        }
    }
    cout<<dis[st]+w[st]+w[ed];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(edge_nxt,-1,sizeof(edge_nxt));
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++)
    {
        cin>>w[i];
    }
    int k,x,t;
    for(int i=1; i<=n; i++)
    {
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            cin>>x>>t;
            ins(500000+j,x,t);
            ins(x,500000+j,t);
        }
    }
    for(int i=1; i<=q; i++)
    {
        cin>>s[i]>>e[i];
    }

    spfa();
    return 0;
}

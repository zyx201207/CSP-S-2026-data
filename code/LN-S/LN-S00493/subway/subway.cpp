#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int id;
    int cnt;

};
struct node
{
    int id,cnt;
};
int n,m,d,qq;
priority_queue<Node>q;
vector<int>g[500009];
ll v[500009];
int a; ll t;
int c,k;
int x,y;
ll dis[500009];
ll tim[500009][509];
void dijkstra(int p)
{
    memset(dis,0x3f3f3f3f,sizeof(dis));
    for(int i=0;i<g[p].szie();i++)
    {
        q.push((Node){ g[p][i].id , tim[g[p][i.id]][g[p][i].cnt]});
    }
    while(!q.empty());
    {
        Node x=q.top();
        vis[x.id]=0;
        q.pop();
        for(int i=0;i<g[x.id].size();i++)
        {
            int y=g[x.id][i].id;
            int now=g[x.id][i].cnt;
        }
    }
}
int main()
{
    freopen("sudway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c;
    scanf("%d%d%d%d",&n,&m,&d,&qq);
    for(int i=1;i<=m;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        int las=-1;
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&a);
            scanf("%lld",&t);
            tim[a][i]=t;
            if(las!=-1)
            {
                g[a].push_back({las,i});
                g[las].push_back({a,i});
            }
            las=a;
        }
        for(int j=1;j<=qq;j++)
        {
            scanf("%d%d",&x,&y);
            dijkstra(x);
            printf("%lld",dis[y]);
            cout<<endl;
        }
    }
    return 0;
}

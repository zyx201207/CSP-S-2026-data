# include<cstdio>
# include<iostream>
# include<algorithm>
# include<cstring>
# include<vector>
# include<queue>
using namespace std;
const int N = 5e5+505;
int c,d,e,a,t,m,n,st,ed,w[N],k,cnt;
int dis[N];
bool vis[N];
vector<int>g[N],f[N];
struct node
{
    int x,y;
};
queue<node> q;
void bfs()
{
    memset(dis,0x3f,sizeof(dis));
    //memset(vis,0,sizeof(vis));
    dis[st] = 0;
    q.push({st,0});
    while(!q.empty())
    {
        int u = q.front().x,lu = q.front().y;
        q.pop();
        if(u == ed)continue;
        for(int i = 0;i<g[u].size();i++)
        {
            int v = g[u][i];
            if(v == lu)continue;
            dis[v] = min(dis[u]+f[u][i],dis[v]);
            q.push({v,u});
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> e;
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j = 1;j<=k;j++)
        {
            scanf("%d %d",&a,&t);
            g[m+i].push_back(a);
            g[a].push_back(m+i);
            f[m+i].push_back(t);
            f[a].push_back(t);
        }
    }
    for(int i = 1;i<=e;i++)
    {
        scanf("%d %d",&st,&ed);
        bfs();
        printf("%d\n",dis[ed]+w[st]+w[ed]);
    }
    return 0;
}

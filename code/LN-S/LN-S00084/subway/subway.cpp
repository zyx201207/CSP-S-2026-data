#include<bits/stdc++.h>
using namespace std;
#define N 505
#define ll long long
int c,n,m,d,q,k;
int cnt;
int a,la;
ll t;
int w[N];
ll dis[N*2][N*2];
vector<int> e[N*2];
void bfs(int x)
{
    bool vis[N*2];
    memset(vis,0,sizeof(vis));
    queue<int> qu;
    qu.push(x);vis[x]=1;
    while(!qu.empty())
    {
        int head=qu.front();
        for(int v:e[head])
        {
            dis[x][v]=dis[v][x]=min(dis[x][v],dis[x][head]+dis[head][v]);
            if(!vis[v])
            {
                qu.push(v);
                vis[v]=1;
            }
        }
        qu.pop();
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    cnt=m;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<N*2;i++)
    {
        for(int j=1;j<N*2;j++)
        {
            dis[i][j]=0x3f3f3f3f;
            if(i==j)dis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            cnt++;
            e[a].push_back(cnt);
            e[cnt].push_back(a);
            dis[a][cnt]=dis[cnt][a]=t;
            if(j==1)
            {
                la=cnt;
                continue;
            }
            dis[cnt][la]=dis[la][cnt]=0;
            e[cnt].push_back(la);
            e[la].push_back(cnt);
            la=cnt;
        }
    }
    
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(dis[x][y]==0x3f3f3f3f)bfs(x);
        cout<<dis[x][y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
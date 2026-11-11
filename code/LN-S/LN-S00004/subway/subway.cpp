#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
struct node
{
    int to;
    int w;
    bool friend operator <(node a,node b)
    {
        return a.w>b.w;
    }
};
vector<node> g1[maxn];
priority_queue <node> g2[maxn];




int owntime[maxn];//owntime[i]表示第i个地铁站的地铁口-站厅时间（自有时间），只在起点和终点计入
int c,n,m,d,q;
//滚木，线路条数，节点数，每个节点最多被几条线路经过，询问数（出行计划数）

int belong[maxn];//belong[i]是地铁站i归属的线路id
bool vis[505];
int no[maxn][505];

int k[505];//k[i]=第i条线路包含的地铁站数
int a[505][maxn];
int t[505][maxn];

int dis[5005]={0};//dis[i]表示当前i号新点到起点st的最段距离
void dijkstra(int st)
{
    while(!g2[st].empty())
        {
            int v=g2[st].top();
            if(vis[v])continue;
            vis[v]=1;
            if(dis[v]>dis[st]+g1[st][v].w)dis[v]=dis[st]+g1[st][v].w;
            g2[st].pop();
        }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)//读入每个地铁站的地铁口-站厅时间
    {
        cin>>owntime[i];
    }
    for(int i=1;i<=n;i++)//读入所有线路的信息
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            //第i条线路上的第j个地铁站的id，
            //以及这个地铁站对于这条线路的站厅-站台时间
            belong[a[i][j]]=i;
            no[a[i][j]][i]=j;

            for(int p=1;p<=k[i-1];p++)//看看上一条线路和这条线路的公共点有哪些；进行连边
            {
                if(a[i-1][p]==a[i][j])
                {
                    g1[i].push_back({i-1,t[i][j]+t[i-1][p]});
                    g1[i-1].push_back({i,t[i][j]+t[i-1][p]});
                    g2[i].push({i-1,t[i][j]+t[i-1][p]});
                    g2[i-1].push({i,t[i][j]+t[i-1][p]});
                }
            }


        }
        

        //for(int j=1;j<k;j++)
        //{
        //    g[j].push_back({j+1,0});
        //    g[j+1].push_back({j,0});
        //}
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        //x:start point;
        //y:end point;
        int st=belong[x];
        int ed=belong[y];
        
        memset(dis,0x3f3f3f3f,sizeof(dis));
        dijkstra(st);
        cout<<(long long)dis[ed]+owntime[x]+t[st][no[x][st]]+owntime[y]+t[ed][no[y][ed]];
    }
    return 0;
}

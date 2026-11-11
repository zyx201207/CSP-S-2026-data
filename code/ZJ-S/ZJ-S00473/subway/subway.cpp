#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int a,t;
};
struct node2
{
    ll time;
    int now;
    short int whe;
    friend bool operator < (node2 x1,node2 y1){
        return x1.time>y1.time;
    }
};
int c,n,m,d,Q;
int w[500005];
bool vis[500005][505];
int x,y;
long long minx=1e18;
vector<node> xl[505];
vector<node> zt[500005];
void bfs()
{
    priority_queue<node2> q;
    q.push({0,x,0});
    for(auto i : zt[x])
    {
        vis[x][i.a]=1;
    }
    while(!q.empty())
    {
        node2 p=q.top();
        q.pop();
        if(p.whe==2)
        {
            for(auto i : xl[p.now])
            {
                if(vis[i.a][p.now]==0)
                {
                    q.push({p.time+i.t,i.a,1});
                    vis[i.a][p.now]=1;
                }
            }
        }
        if(p.now==y&&p.whe==1)
        {
            p.time+=w[p.now];
            minx=min(minx,p.time);
            return;
        }
        if(p.whe==0)
        {
            p.time+=w[p.now];
            p.whe=1;
        }
        if(p.whe==1)
        {
            for(auto i : zt[p.now])
            {
                q.push({p.time+i.t,i.a,2});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a,t;
            cin>>a>>t;
            xl[i].push_back({a,t});
            zt[a].push_back({i,t});
        }
    }
    while(Q--)
    {
        cin>>x>>y;
        minx=1e9;
        memset(vis,0,sizeof(vis));
        bfs();
        cout<<minx<<endl;
    }
    return 0;
}
//???awdawddadwdadwadwada
//RP++!!!!!!!!!!!!!!!!!!!!
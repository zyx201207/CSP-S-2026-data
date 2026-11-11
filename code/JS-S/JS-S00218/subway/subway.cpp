#include <bits/stdc++.h>
using namespace std;

int n,m,d,qq,w[50010],dis[50010],o,op;

int h = 0;

bool vis[50010];

struct aa
{
    int u,id;
};

vector<aa> g[50010];

struct bb
{
    int v,w,id;
    bool operator < (const bb &h)const
    {
        return w > h.w;
    }
};

priority_queue<bb> q;

vector<bb> g1[50010];

int id[50010][510];

int x,y;

void diji(int s)
{
    o = 0;
    op = 0;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = 0;
    q.push({s,0,0});
    while(!q.empty())
    {
        auto t = q.top();
        q.pop();
        if(vis[t.v])
        {
            continue;
        }
        vis[t.v] = 1;
        for(auto f : g[t.v])
        {
            int v = f.u;
            int w = f.id;
            if(dis[v] > dis[t.v] + ((w == t.id || t.id == 0) ? 0 : id[t.v][t.id] + id[t.v][w]))
            {
                dis[v] = dis[t.v] + ((w == t.id || t.id == 0) ? 0 : id[t.v][t.id] + id[t.v][w]);
                if(v == y)
                {
                    o = w;
                }
                if(t.v == x)
                {
                    op = w;
                }
                q.push({v,dis[v],w});
            }
        }
    }
}


map<pair<int,int>,int> mp;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin >> c >> n >> m >> d >> qq;
    for(int i = 1;i <= m;i++)
    {
        cin >> w[i];
    }
    bool flag = 0;
    for(int i = 1;i <= n;i++)
    {
        int l,k,qh;
        cin >> l >> k >> qh;
        id[k][i] = qh;
        h = qh;
        for(int j = 2;j <= l;j++)
        {
            int h;
            cin >> h;
            int s;
            cin >> s;
            mp[{h,i}] = s;
            id[h][i] = s;
            g[k].push_back({h,i});
            g[h].push_back({k,i});
        }
    }
    while(qq--)
    {
        cin >> x >> y;
        diji(x);
        cout << dis[y] + w[x] + w[y] + id[y][o] + id[x][op] << "\n";
    }
    return 0;
}

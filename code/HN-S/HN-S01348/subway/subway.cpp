#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 6e5 + 5;
ll dist[N],w[N];
bool ask[N];
ll ans[N];

struct node{
    int v;
    ll w;
    bool operator < (const node x) const
    {
        return w > x.w;
    }
};

struct Que{
    int x,y;
    int id;
} que[N];

bool cmp(const Que a,const Que b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

vector<node> edge[N];
priority_queue<node> pq;
bool vis[N];

void Dijkstra(int s)
{
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    memset(vis,0,sizeof vis);
    pq.push((node){s,0});
    while(!pq.empty())
    {
        int u = pq.top().v;
        pq.pop();
        vis[u] = 1;
        for(int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i].v;
            ll w = edge[u][i].w;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                if(!vis[v]) pq.push((node){v,dist[u] + w});
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    //厅：1~m
    //台：m+1~m+n
    for(int i = m + 1; i <= m + n; i++)
    {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++)
        {
            int a;
            ll t;
            cin >> a >> t;
            edge[i].push_back((node){a,t});
            edge[a].push_back((node){i,t});
        }
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> que[i].x >> que[i].y;
        ask[que[i].x] = 1,ask[que[i].y] = 1;
        que[i].id = i;
    }
    sort(que + 1,que + q + 1,cmp);
    int k = 1;
    for(int i = 1; i <= m + n; i++)
        if(ask[i])
        {
            Dijkstra(i);
            while(k <= q && que[k].x == i)
            {
                ans[que[k].id] = dist[que[k].y] + w[que[k].x] + w[que[k].y];
                k ++;
            }
        }
    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
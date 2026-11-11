#include<bits/stdc++.h>
using namespace std;
int w[500010], k[510], a[500010][510], t[500010][510], head[500010], cnt = 0;
struct edge
{
    int to, w, nxt;
}e[1000010];
struct node
{
    int x, b;
};
bool operator <(node xxx, node yyy)
{
    return xxx.b < yyy.b;
}
priority_queue <node> q;
void add(int u, int v, int w)
{
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
int dist[500010], vis[500010];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, sizeof(head));
    int c, n, m, d, qq;
    cin >> c >> n >> m >> d >> qq;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j] >> t[i][j];
            if(j == 1) continue;
            for(int l = 1; l < j; l++)
            {
                add(a[i][l], a[i][j], t[i][l] + t[i][j]);
             add(a[i][j], a[i][l], t[i][l] + t[i][j]);
            }

        }
    }
    while(qq--)
    {
        int xx, yy;
        cin >> xx >> yy;
        memset(dist, 0x3f3f3f3f, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        q.push((node){xx, 0});
        dist[xx] = 0;
        while(!q.empty())
        {
            node tmp = q.top();
            q.pop();
            if(vis[tmp.x]) continue;
            vis[tmp.x] = 1;
            //cout << tmp.x << " ";
            for(int i = head[tmp.x]; ~i; i = e[i].nxt)
            {
                int vv = e[i].to;
                if(dist[vv] > dist[tmp.x] + e[i].w)
                {
                    dist[vv] = dist[tmp.x] + e[i].w;
                    vis[vv] = 0;
                    q.push((node){vv, dist[vv]});
                }
            }
        }
        cout << dist[yy] + w[xx] + w[yy] << "\n";
    }
    return 0;
}

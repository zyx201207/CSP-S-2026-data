#include<bits/stdc++.h>
using namespace std;
//const int MAXQ = 1e5 + 10;
const int MAXM = 5e5 + 20;
int c, n, m, d, q;
bool vis[520 + MAXM];
struct ques
{
    int u, v, t, ans;
    ques(){};
    ques(int uu, int vv, int tt)
    {
        u = uu, v = vv, t = tt, ans = 0;
    }
    bool operator< (ques other) const
    {
        return u < other.u;
    }
};
vector<ques> sta;
int w[MAXM];
int dis[520 + MAXM];
int head[520 + MAXM];
int cnt;
struct Edge
{
    int to, nxt, w;
    Edge(){};
    Edge(int too, int nxtt, int ww)
    {
        to = too;
        nxt = nxtt;
        w = ww;
    }
}edges[MAXM];
void addEdge(int u, int v, int w)
{
    edges[++cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
}
bool comp(ques q1, ques q2)
{
    return q1.t < q2.t;
}
int main()
{
    memset(head, -1, sizeof head);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // code here
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for(int i = 1, k; i <= n; i++)
    {
        cin >> k;
        for(int j = 1, a, t; j <= k; j++)
        {
            cin >> a >> t;
            addEdge(i, 520 + a, t);
            addEdge(520 + a, i, t);
        }
    }
    int x, y;
    for(int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        sta.push_back(ques(x + 520, y + 520, i));
    }
    sort(sta.begin(), sta.end());
    int pre = -1, s;
    for(int i = 1; i <= q; i++)
    {
        s = sta[i].u;
        if(s == pre)
        {
            sta[i].ans = dis[sta[i].v];
            continue;
        }
        memset(dis, 0x3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        priority_queue<pair<int, int> > pq;
        pq.push({0, s});
        while(!pq.empty())
        {
            pair<int, int> np = pq.top();
            pq.pop();
            if(vis[np.second]) continue;
            vis[np.second] = 1;
            for(int e = head[np.second]; e + 1; e = edges[e].nxt)
            {
                int to = edges[e].to;
                if(dis[to] >= np.first + edges[e].w)
                {
                    dis[to] = np.first + edges[e].w;
                    pq.push({dis[to], to});
                }
            }
        }
        sta[i].ans = dis[sta[i].v] + w[sta[i].v - 520] + w[sta[i].u - 520];
    }
    sort(sta.begin(), sta.end());
    for(int i = 1; i <= q; i++)
    {
        cout << sta[i].ans << '\n';
    }
    return 0;
}

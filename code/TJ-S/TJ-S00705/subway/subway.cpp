// pwd: j:Trick||Treat! s:Oct31==Dec25?
// shen ren kao chang, kai kao 5 fen zhong hai mei fa ti
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int N = 505, M = 1e6 + 5, D = 25, Q = 1e5 + 5;
const int E = 1e7, F = M * (D + 5);
const int inf = 4e18;
int c, n, m, d, q;
int tot, k[M], t[M], x[M][D], cnt, wi[E];
int hd[F], nxt[E], to[E]; 
int dis[F], ans[Q];
vector<int> qsc[M];

struct Node2
{
    int a, b;
} qs[Q];

void add(int u, int v, int w)
{
    ++cnt;
    to[cnt] = v;
    wi[cnt] = w;
    nxt[cnt] = hd[u];
    hd[u] = cnt;
}

struct Node
{
    int u, d;
};

struct cmp
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.d > b.d;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

void dijkstra(int s)
{
    // cout << "---s: " << s << '\n';
    for (int i = 1; i <= tot; i++)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    pq.push({s, 0});
    while (!pq.empty())
    {
        int nu = pq.top().u, nd = pq.top().d;
        // cout << "pq: " << nu << '\n';
        pq.pop();
        if (nd > dis[nu]) continue;
        for (int e = hd[nu]; e; e = nxt[e])
        {
            int nv = to[e], nw = wi[e];
            // cout << "e: " << nu << ' ' << nv << ' ' << nw << '\n';
            if (dis[nv] > dis[nu] + nw)
            {
                dis[nv] = dis[nu] + nw;
                pq.push({nv, dis[nv]});
            }
        }
    }
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        int xi;
        cin >> xi;
        k[i] = ++tot, t[i] = ++tot;
        add(k[i], t[i], xi), add(t[i], k[i], xi);
    }
    for (int i = 1; i <= n; i++)
    {
        int ki;
        cin >> ki;
        int ltot = 0;
        for (int j = 1; j <= ki; j++)
        {
            int a, b;
            cin >> a >> b;
            ++tot;
            add(tot, t[a], b), add(t[a], tot, b);
            if (j >= 2)
            {
                // cout << "addedge: " << tot << ' ' << x[la][i] << '\n';
                add(tot, ltot, 0), add(ltot, tot, 0);
            }
            ltot = tot;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        qs[i] = {a, b};
        qsc[a].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (qsc[i].size() > 0)
        {
            dijkstra(k[i]);
        }
        for (auto cur : qsc[i])
        {
            int a = qs[cur].a, b = qs[cur].b;
            ans[cur] = dis[k[b]];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }
	return 0;
}

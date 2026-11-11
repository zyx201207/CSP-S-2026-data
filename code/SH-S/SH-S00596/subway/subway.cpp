#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using lonit = long long;
using Pr = pair<int, pair<int, int>>;

constexpr int kMaxN = 510,
              kMaxM = 500'010, kMaxK = 500'010, kMaxQ = 100'010;
constexpr int kMaxP = kMaxM + kMaxN, kMaxS = kMaxK * 2;

struct Lxy
{
    int to;
    lonit val;
    int nxt;
};

Lxy gh[kMaxS];
int head[kMaxP], tot;

inline void add(int u, int v, lonit w)
{
    ++tot;
    gh[tot] = {v, w, head[u]};
    head[u] = tot;
    return;
}

lonit dis[kMaxP];
bool vis[kMaxP];

struct Node
{
    int id;
    lonit dis;
    bool operator>(const Node &y) const
    {
        return dis > y.dis;
    }
};

using PQue = priority_queue<Node, vector<Node>, greater<Node>>;
PQue que;
inline void dijk(int s, int tn)
{
    memset(dis, 0x3f, sizeof(lonit) * (tn + 5));
    memset(vis, 0, sizeof(bool) * (tn + 5));

    PQue().swap(que);

    dis[s] = 0;
    que.push({s, dis[s]});

    while (!que.empty())
    {
        Node t = que.top();
        que.pop();
        int u = t.id;
        lonit d = t.dis;
        for (int k = head[u]; k; k = gh[k].nxt)
        {
            int v = gh[k].to;
            lonit w = gh[k].val;
            
            if (d + w < dis[v])
            {
                dis[v] = d + w;
                if (!vis[v])
                {
                	vis[v] = true;
                    que.push({v, dis[v]});
                }
            }
        }
    }

    return;
}

int c, n, m, d, q;
lonit pw[kMaxM];
lonit anss[kMaxQ];

Pr qs[kMaxQ];

bool comp(const Pr &x, const Pr &y)
{
    return x.second.first < y.second.first;
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; ++i)
        scanf("%lld", &pw[i]);

    int sta, ta;
    lonit w;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &sta);
        for (int j = 1; j <= sta; ++j)
        {
            scanf("%d%lld", &ta, &w);
            add(ta, m + i, w);
            add(m + i, ta, w);
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        qs[i].first = i;
        scanf("%d%d", &qs[i].second.first, &qs[i].second.second);
    }

    sort(qs + 1, qs + 1 + q, comp);

    int ls = 0;
    for (int i = 1; i <= q; ++i)
    {
        int id = qs[i].first, s = qs[i].second.first, t = qs[i].second.second;
        if (s != ls)
        {
            dijk(s, m + n);
        }
        anss[id] = pw[s] + dis[t] + pw[t];
    }
    
    for (int i = 1; i <= q; ++i)
    {
        printf("%lld\n", anss[i]);
    }

    return 0;
}


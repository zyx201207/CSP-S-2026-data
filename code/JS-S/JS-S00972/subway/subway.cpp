#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int c, n, m, d, q;
int w[N];
bool vis[N + 500];
int tmax;
int sum20[N];
bool before20[N];
queue<pair<int, int> > que;
struct node
{
    int to, wt;
    node(int a, int b)
    {
        to = a, wt = b;
    }
};
vector<node> v[N + 500];
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    //printf("1\n");
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            scanf("%d%d", &a, &t);
            tmax = t;
            v[m + i].push_back(node(a, t));
            v[a].push_back(node(m + i, t));
            if (sum20[a] != 0) before20[a] = 1;
            sum20[a] += t;
        }
    }
    //printf("1\n");
    for (int i1 = 1; i1 <= q; i1++)
    {

        int x, y;
        scanf("%d%d", &x, &y);
        if (c < 12 || c > 21)
        {
            while (!pq.empty()) pq.pop();
        memset(vis, 0, sizeof(vis));
        pq.push(make_pair(0, x));
        vis[x] = 1;
        while (!pq.empty())
        {
            pair<int, int> t = pq.top();
            pq.pop();
            //if (x == 18 && y == 74) printf("t:%d %d\n", t.second, t.first);
            if (t.second == y)
            {
                printf("%d\n", t.first + w[x] + w[y]);
                break;
            }
            for (int i = 0; i < v[t.second].size(); i++)
            {
                //printf("t:%d %d\n", t.second, t.first);
                if (!vis[v[t.second][i].to])
                {
                    //printf("t:%d %d\n", t.second, t.first);
                    vis[v[t.second][i].to] = 1;
                    //if (x == 18 && y == 74) printf("push:%d %d\n", v[t.second][i].to, t.first + v[t.second][i].wt);
                    pq.push(make_pair(t.first + v[t.second][i].wt, v[t.second][i].to));
                }
            }
        }
        }
        else if(c < 20)
        {
            while (!que.empty()) que.pop();
            que.push(make_pair(x, 0));
            memset(vis, 0, sizeof(vis));
            vis[x] = 1;
            while (!que.empty())
            {
                pair<int, int> t = que.front();
                que.pop();
                if (t.first == y)
                {
                    printf("%d\n", t.second * tmax + w[x] + w[y]);
                }
                for (int i = 0; i < v[t.first].size(); i++)
                {
                    if (!vis[v[t.first][i].to])
                    {
                        vis[v[t.first][i].to] = 1;
                        que.push(make_pair(v[t.first][i].to, t.second + 1));
                    }
                }
            }
        }
        else
        {
            if (n == 1) printf("%d\n", v[x][0].wt + v[y][0].wt);
            else
            {
                int minsum = INT_MAX;
            for (int i = 1; i <= m; i++)
            {
                if (before20[i]) minsum = min(minsum, sum20[i]);
            }
            if (v[x].size() == 1 && v[y].size() == 1)
            {
                if (v[x][0].to == v[y][0].to)
                {
                    printf("%d\n", v[x][0].wt + v[y][0].wt + w[x] + w[y]);
                }
                else
                {
                    printf("%d\n", v[x][0].wt + v[y][0].wt + minsum + w[x] + w[y]);
                }
            }
            else if (v[x].size() == 2 && v[y].size() == 2)
            {
                int ka, kb, kc, kd;
                if (v[x][0].to == v[y][0].to)
                {
                    ka = v[x][0].wt, kb = v[y][0].wt, kc = v[x][1].wt, kd = v[y][1].wt;
                }
                else
                {
                    ka = v[x][0].wt, kb = v[y][1].wt, kc = v[x][1].wt, kd = v[y][0].wt;
                }
                printf("%d\n", min(ka + kb, min(kc + kd, min(ka + kd, kb + kc) + minsum)) + w[x] + w[y]);
            }
            else
            {
                if (v[x].size() < v[y].size()) swap(x, y);
                int ka, kb;
                if (v[x][0].to == v[y][0].to) ka = v[x][0].wt, kb = v[x][1].wt;
                else  ka = v[x][1].wt, kb = v[x][0].wt;
                printf("%d\n", min(ka + v[y][0].wt, kb + v[y][0].wt + minsum) + w[x] + w[y]);
            }
            }

        }
    }
    return 0;
}

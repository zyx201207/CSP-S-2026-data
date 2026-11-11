#include<bits/stdc++.h>
#define int long long
using namespace std;
/* Define & Const */
const int V = 2e6 + 100;
const int E = 2e7 + 100;
const int M = 5e5 + 10;
const int N = 505;
/* Struct */
struct Graph
{
    int head[V];
    struct Edge
    {
        int to;
        int val;
        int nxt;    
    };
    Edge edge[E];
    int e_cnt = 0;
    int v_cnt = 0;
    /* for dijkstra */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist;

    void __add(int u, int v, int w)
    {
        edge[++e_cnt] = {v, w, head[u]};
        head[u] = e_cnt;
    }
    void add(int u, int v, int w)
    {
        __add(u, v, w);
        __add(v, u, w);
    }
    int dijkstra(int st, int goal)
    {
        pq = tmp;
        for (int i = 1; i <= v_cnt; i++)
        {
            dist[i] = 0x3f3f3f3f;
        }
        
        dist[st] = 0;
        pq.push({0, st});
        while(pq.size())
        {
            int dis_ = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dis_ > dist[u])
            {
                continue;   
            }

            for (int i = head[u]; i; i = edge[i].nxt)
            {
                int v = edge[i].to;
                int w = edge[i].val;
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[goal];
    }
};
/* Variables */
Graph g;
int c, n, m, d, q;
int w[M];
/* Functions */
void input_build()
{
    g.dist.resize(V);
    cin >> c >> n >> m >> d >> q;
    // cout << "1\n";
    for (int i = 1; i <= m; i++)
    {
        
        // int w;
        cin >> w[i];
        // g.add(i, m + i, w); // edge betweem the hall (1 ~ m) and the entrance (m + 1 ~ 2m)
    }
    int board_num = 0;
    // cout << "2\n";
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, t;
            cin >> a >> t;
            board_num++;
            g.add(a, 1 * m + board_num, t);// edge between the hall (1 ~ m) and the board (2m + 1 ~ )
            if(j > 1)
            {
                g.add(1 * m + board_num, 1 * m + board_num - 1, 0); // edge between boards(stations) 
                // w = 0 because it's the subway's route, not XiaoR's. So it doesn't count into the total 'walking' time.
            }
        }
        
    }
    g.v_cnt = 2 * m + board_num;
}
/* Main */
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input_build();
    while(q--)
    {
        int st, goal;
        cin >> st >> goal;
        cout << g.dijkstra(st, goal) + w[st] + w[goal] << "\n";
    }
}
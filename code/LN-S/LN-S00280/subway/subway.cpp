#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int c, n, m, d, q;
vector<int> w;
vector<vector<pair<int, int>>> a_and_t;
vector<pair<int, int>> xy;
void input_all()
{
    cin >> c >> n >> m >> d >> q;
    for (int i = 0; i < m; i++)
    {
        int w_c = 0;
        cin >> w_c;
        w.push_back(w_c);
    }
    for (int i = 1; i <= n; i++)
    {
        int ki = 0;
        cin >> ki;
        vector<pair<int, int>> Ephemeral;
        for (int j = 1; j <= ki; j++)
        {
            int qq, ww;
            cin >> qq >> ww;
            pair<int, int> hrtg = {qq, ww};
            Ephemeral.push_back(hrtg);
        }
        a_and_t.push_back(Ephemeral);

    }
    for (int i = 1; i <= q; ++i)
    {
        int x, y;
        cin >> x >> y;
        xy.push_back({x, y});
    }
}

//graph
struct Edge{
    int u, v;
    int w;
    Edge(int u1, int v1, int w1){u = u1, v = v1, w = w1;}
};
struct Node{
    int num = 0;
    vector<Edge> adj;
    Node(int nu){num = nu;}
};



bool operator< (Edge a, Edge b)
{
    return a.w < b.w ? true : false;
}
//dijkstra_attempt
vector<Edge> all_edges;
vector<Node> all_nodes;
//dij helper
int dist[500050], vis[500050];
bool operator> (Node a, Node b)
{
    return dist[a.num] > dist[b.num] ? true : false;
}
void dijkstra(Node s)
{
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[s.num] = 0;
    pq.push(all_nodes[s.num]);
        Node TMP = pq.top();
        pq.pop();
        for(auto G : TMP.adj)
        {
            if((dist[G.u] + G.w) < dist[G.v])
            {
                dist[G.v] = dist[G.u] + G.w;
                pq.push(all_nodes[G.v]);
            }
        }
        vis[TMP.num] = true;
  
}
void refill()
{
    for(int i = 0; i < 500045; i++)
    {
        dist[i] = INF;
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    input_all();
    for(int i = 1; i <= m; ++i)
    {
        all_nodes.push_back(Node(i));
    }
    //build up the graph
    for (int i = 0; i < a_and_t.size(); i++)
    {
        for (int j = 1; j < a_and_t[i].size(); ++j)
        {
            Edge N4(a_and_t[i][j-1].first,a_and_t[i][j].first, w[a_and_t[i][j].first] + a_and_t[i][j-1].second);
            all_nodes[a_and_t[i][j-1].first].adj.push_back(N4);
            all_nodes[a_and_t[i][j].first].adj.push_back(N4);
        }
    }
    for(int i = 0; i < q; i++)
    {
        dijkstra(all_nodes[xy[i].first]);
        cout << dist[xy[i].second] << endl;
        refill();
    }
    return 0;
}

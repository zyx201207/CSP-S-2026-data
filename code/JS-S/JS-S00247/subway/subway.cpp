#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using Pr = pair<ll, int>;
const int N = 5e5 + 1000, SW = 500 + 100, Q = 1e5 + 100;
const ll inf = 1e15 + 100;

struct edge {
    int to;
    ll w;
    edge () {
        to = -1;
        w = 0;
    }
    edge (int _to, ll _w) {
        to = _to;
        w = _w;
    }
};

int c, n, m, d, q;
int wToTop[N];
int k[N];

//int WayX[N], WayY[N];
struct query {
    int id, to;
    query () {}
    query (int _id, int _to) {
        id = _id;
        to = _to;
    }
};
vector <query> qry[N];
ll ans[N];

vector <edge> towards[SW];
vector <edge> g[SW + N];

//Bao Li
ll dis[N];
void dijkstra (int s) {
    fill (dis, dis + N, inf);
    priority_queue <Pr, vector <Pr>, greater <Pr>> pq;
    dis[s] = 0;
    pq.push (make_pair(0, s));

    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (tmp.first > dis[u]) continue;

        for (auto ttmp : g[u]) {
            int v = ttmp.to;
            ll dt = ttmp.w;
            if (dis[v] > dis[u] + dt) {
                dis[v] = dis[u] + dt;
                pq.push (make_pair(dis[v], v));
            }
        }
    }
}


int main () {
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    //Obviously the edge is very XiShu. (But I don't know how to use it...QAQ)_
    //li xian suan fa ma ?
    cin >> c >> n >> m >> d >> q;

    for (int i = 1; i <= m; ++ i) {
        cin >> wToTop[i];
    }

    for (int i = 1; i <= n; ++ i) {
        cin >> k[i];
        for (int j =1; j <= k[i]; ++ j) {
            int ai;
            ll ti;
            cin >> ai >> ti;
            g[m + i].push_back (edge (ai, ti));
            g[ai].push_back (edge (m + i, ti));
        }
    }
    for (int i = 1; i <= q; ++ i) {
        int xps, yps;
        cin >> xps >> yps;
        //fang zhi bei ka
        //dan shi ye rong yi si
        if (rand()&1) swap (xps, yps);
        qry[xps].push_back (query(i, yps));
        //cin >> WayX[i] >> WayY[i];
    }
    for (int i = 1; i <= m; ++ i) {
        if (qry[i].size()) {
            dijkstra (i);
            for (auto tmpp : qry[i]) {
                int id = tmpp.id, to = tmpp.to;
                ans[id] = dis[to] + wToTop[i] + wToTop[to];
            }
        }
    }

    for (int i = 1; i <= q; ++ i) {
        cout << ans[i] << '\n';
    }
    return 0;
}


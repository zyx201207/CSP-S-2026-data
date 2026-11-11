# include <iostream>
# include <vector>
# include <queue>
# define int long long
const int N = 505, S = 2e5 + 10, M = 5e5 + 5;
struct Node {
  int to, wei;
  friend bool operator < (const Node &x, const Node &y) {
    return x.wei > y.wei;
  }
}; std::vector <Node> G[N];
std::priority_queue <Node> qe;
void add (int u, int v, int w) {
  G[u].push_back ({v, w});
  G[v].push_back ({u, w});
}
int c, n, m, d, q, w[M], fa[N];
std::vector <Node> ts[M];
//int xx[S], yy[S], xq[S];
int dis[N][N];
bool vis[N][N];
// 换乘站边数最多有 40 个 
// 线路最多有 500 个 
// 站点最多有 5e5 个
void Dijkstra (int s) {
  for (int i = 0; i < n; i ++) dis[s][i] = 9e18;
  dis[s][s] = 0;
  qe.push ({s, 0});
  while (!qe.empty ()) {
    Node now = qe.top (); qe.pop ();
    if (vis[s][now.to]) continue;
    vis[s][now.to] = 1;
    for (int i = 0; i < (int) G[now.to].size (); i ++) {
      int vv = G[now.to][i].to, ww = G[now.to][i].wei;
      if (dis[s][vv] > dis[s][now.to] + ww) {
        dis[s][vv] = dis[s][now.to] + ww;
        qe.push ({vv, dis[s][vv]});
      }
    }
  }
  return;
}
signed main () {
  freopen ("subway.in", "r", stdin);
  freopen ("subway.out", "w", stdout);
	std::cin.tie (0) -> sync_with_stdio (false);
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++)
    std::cin >> w[i];
  for (int i = 0; i < n; i ++) {
    int k; std::cin >> k;
    for (int j = 1; j <= k; j ++) {
      int p, x;
      std::cin >> p >> x;
      ts[p].push_back ({i, x});
    }
  }
//  if (1 <= c && c <= 3) {
//    for (int i = 1; i <= m; i ++) {
//      for (int j = 1; j <= m; j ++) {
//        
//      }
//    }
//  }
  for (int i = 1; i <= m; i ++) {
    int nn = (int) ts[i].size ();
    if (nn >= 2)
      for (int j = 0; j < nn; j ++)
        for (int k = 0; k < nn; k ++)
          if (j != k)
            add (ts[i][j].to, ts[i][k].to, ts[i][j].wei + ts[i][k].wei);
  }
//  for (int i = 1; i <= q; i ++) {
//    std::cin >> xx[i] >> yy[i];
//    xq[0] ++;
//    xq[xq[0]] = xx[i];
//  }
  for (int i = 0; i < n; i ++)
    Dijkstra (i);
  for (int i = 1; i <= q; i ++) {
    int xx, yy;
    std::cin >> xx >> yy;
    int anss = 9e18;
    for (int j = 0; j < (int) ts[xx].size (); j ++) {
      for (int k = 0; k < (int) ts[yy].size (); k ++) {
        int jj = ts[xx][j].to, kk = ts[yy][k].to;
        int jw = ts[xx][j].wei, kw = ts[yy][k].wei;
        anss = std::min (anss, dis[jj][kk] + w[xx] + w[yy] + jw + kw);
//        std::cout << jj << ' ' << kk << ' ' << dis[jj][kk] << '\n';
      }
    }
    std::cout << anss << '\n';
  }
	return 0;
}
/*
0 3 7 20 2 
8 3 6 1 7 2 9 
3 1 4 2 5 5 100 
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3 

*/


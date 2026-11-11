#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
const int M = 5e5 + 10;
const ll inf = 0x3f3f3f3f;
int c, n, m, d, q, w[M];
map<int, vector<pii> > g;
map<int, ll> dist;
map<int, bool> f;
priority_queue<pil, vector<pil>, greater<pil> >pq;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
ll dijkstra(int start, int ended) {
  for (int i = 1; i <= m; i++) dist[i] = inf, dist[i + m] = inf, f[i] = 0, f[i + m] = 0;
  for (int i = 1; i <= n; i++) dist[-i] = inf, f[-i] = 0;
  dist[start] = 0;
  pq.push({start, 0});
  while (pq.size()) {
    int t = pq.top().first;
    pq.pop();
    if (f[t]) continue;
    f[t] = 1;
    for (auto tt : g[t]) if (!f[tt.first] && dist[tt.first] > dist[t] + 1LL * tt.second) {
      dist[tt.first] = dist[t] + 1LL * tt.second;
      pq.push({tt.first, dist[tt.first]});
    }
  }
  //for (int i = 1; i <= m; i++) cout << dist[i] << " " << dist[i + m] << "\n";
  //for (int i = 1; i <= n; i++) cout << dist[-i] << "\n";
  return dist[ended];
}
int main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  c = read(), n = read(), m = read(), d = read(), q = read();
  for (int i = 1; i <= m; i++) {
    w[i] = read();
    g[i].push_back({i + m, w[i]});
    g[i + m].push_back({i, w[i]});
  }
  for (int i = 1; i <= n; i++) {
    int k = read();
    for (int j = 1; j <= k; j++) {
        int a = read(), t = read();
        g[a + m].push_back({-i, t});
        g[-i].push_back({a + m, t});
    }
  }
  while (q--) {
    int x = read(), y = read();
    write(dijkstra(x, y));
    puts("");
  }
  return 0;
}

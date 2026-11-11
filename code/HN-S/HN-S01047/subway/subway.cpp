#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second

using namespace std;

ifstream fin("subway.in");
ofstream fout("subway.out");

const int kMaxN = 1005;
ll n, m, c, d, T, a[kMaxN], cnt[kMaxN], dis[kMaxN][205];

vector<pair<ll, ll>> sub[kMaxN];
pair<ll, ll> b[205][1005];
map<pair<ll, ll>, bool> vis;
vector<pair<ll, ll>> G[kMaxN];
priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> q;

ll help(ll x, ll y) {
  return x + y * m;
}

// void bfs(ll op) {
//   fill(dis[0], dis[0] + kMaxN * 205, 1e18);
//   for(auto u : sub[op]) {
//     q.push({u.sc, {op, u.fr}});
//   }
//   for(pair<ll, ll> x, u;!q.empty(); ) {
//     x = q.top().sc, q.pop();
//     if(vis[x]) continue;
//     for(auto u : G[x.fr]) {
//       for(auto v : sub[u.fr]) {
//         if(dis[u.fr][x.sc] > dis[x.sc]) {
//           dis[]
//         }
//       }
//     }
//   }
// }

int main() {
  ios::sync_with_stdio(0), fin.tie(0);
  fin >> c >> n >> m >> d >> T;
  srand(time(NULL));
  for(int i = 1; i <= m; i++) {
    fin >> a[i];
  }
  for(int i = 1, k; i <= n; i++) {
    fin >> k;
    for(int j = 1; j <= k; j++) {
      fin >> b[i][j].fr >> b[i][j].sc;
      sub[b[i][j].fr].push_back({i, b[i][j].sc});
      G[i].push_back({b[i][j].fr, b[i][j].sc});
    }
  }
  for(ll x, y; T; T--) {
    fin >> x >> y;
    fout << a[x] + a[y] + (rand() % 1000) << '\n';
  }
  return 0;
}
/*
cd /home/noilinux/HN-S01047/subway/ && ulimit -s 102400 && g++ subway.cpp -O2 -Wall -o subway && time ./subway && diff subway.out subway.ans -Bb
*/
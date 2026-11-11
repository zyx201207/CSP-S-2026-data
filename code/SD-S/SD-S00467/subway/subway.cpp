#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define ll long long
#define topQ priority_queue
#define bint __int128

inline int in () {
 int x = 0; bool f = false; char ch = getchar();
 while (!isdigit(ch)) f |= ch == '-', ch = getchar();
 while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
 return f ? -x : x;
}

constexpr int N = 5e5 + 1e3, Mod = 998244353, M = 520, inf = 2e18;

int cid, n, m, d, q, dis[M][M], W[N];
vector<array<int, 2> > E[N];

signed main() { freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
 cid = in(), m = in(), n = in(), d = in(), q = in();
 for (int i = 1; i <= n; W[i] = in(), i++);
 //puts("what?");
 for (int i = 1; i <= m; i++) {
  for (int j = in(); j; j--) {
   int x, d; x = in(), d = in();
   E[x].push_back(array<int, 2> {i, d});
  }
  //printf("end %d\n", i);
 } for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) dis[i][j] = i == j ? 0 : inf;
 for (int i = 1; i <= n; i++) {
  int l = E[i].size();
  for (int j = 0; j < l; j++) for (int k = j; k < l; k++) {
   int x = E[i][j][0], y = E[i][k][0], v1 = E[i][j][1], v2 = E[i][k][1];
   //printf("#line 36 : i = %d, x = %d, y = %d, v1 = %d, v2 = %d\n", i, x, y, v1, v2);
   if (v1 + v2 < dis[x][y]) {
    dis[x][y] = dis[y][x] = v1 + v2;
   }
  }
 } 
 for (int k = 1; k <= m; k++) for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) 
  dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
 //for (int i = 1; i <= m; i++) for (int j = 1; j <= m; j++) printf("i = %d, j = %d, dis = %lld\n", i, j, dis[i][j]);
 for (; q--; ) {
  int x = in(), y = in();
  int Ex = (int)E[x].size(), Ey = (int)E[y].size();
  int ans = inf;
  for (int i = 0; i < Ex; i++) {
   int z = E[x][i][0], v = E[x][i][1];
   //printf("#line 48 : z = %d, v = %lld\n", z, v);
   for (int j = 0; j < Ey; j++) {
    //printf("#line 50 : z' = %d, v' = %lld\n", E[y][j][0], E[y][j][1]);
    ans = min(ans, v + E[y][j][1] + dis[z][E[y][j][0]]);
   }
  }
  printf("%lld\n", ans + W[x] + W[y]);
 }
 return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

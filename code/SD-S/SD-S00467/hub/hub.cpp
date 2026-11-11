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

constexpr int N = 1e5 + 1e3, Mod = 998244353;

int cid, Test, n, k, fa[N], dis[N], ans;
vector<int> E[N];

inline int findset (int x) {
 return fa[x] == x ? x : fa[x] = findset(fa[x]);
}

inline void solve () {
 n = in(), k = in(); ans = n - 1;
 for (int i = 1, x, y; i < n; x = in(), y = in(), E[x].push_back(y), E[y].push_back(x), i++);
 for (int i = 0; i < 1 << n; i++) {
  if (__builtin_popcount(i) == k) {
   for (int j = 1; j <= n; j++) fa[j] = j;
   for (int j = 1; j <= n; j++) if (i >> (j - 1) & 1) {
    for (auto x : E[j]) if (i >> (x - 1) & 1) {
     //if (i == 262)printf("? %d %d\n", j, x);
     fa[findset(j)] = findset(x);
    }
   } set<int> st;
   for (int j = 1; j <= n; j++) if (i >> (j - 1) & 1) {
    st.insert(findset(j));
   }
   if ((int)st.size() <= 2) {
    queue<int> q; int ret = 1;
    for (int j = 1; j <= n; j++) dis[j] = i >> (j - 1) & 1;
    for (int j = 1; j <= n; j++) if (dis[j]) q.push(j);

    while (!q.empty()) {
     auto x = q.front(); q.pop(); ret = max(ret, dis[x]);
     //printf("#line 45 : x = %d, dis = %d\n", x, dis[x]);
     for (auto y : E[x]) if (!dis[y]) {
      dis[y] = dis[x] + 1; q.push(y); 
     }
    }
    ans = min(ans, ret - 1);
   }
  }
 } printf("%lld\n", ans);
 for (int i = 1; i <= n; i++) E[i].clear();
}

signed main() { freopen("hub.in", "r", stdin); freopen("hub.out", "w", stdout);
 for (cid = in(), Test = in(); Test--; solve());
 return 0;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/

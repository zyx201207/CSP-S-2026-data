#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int itn;
typedef  __int128 i128;
int test = 1;
const int N = 1e6 + 5;
int c , n , k;
vector < int > e[N];
int vis[N] , dis[N];
int fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dfs(int u , int fa) {
	for (auto v : e[u]) {
		if (v == fa) continue ;
		if (dis[u + 1] > dis[v]) continue ;
		dis[v] = min(dis[v] , dis[u] + 1);
		dfs(v , u);
	}
}
inline void solve() {
	scanf("%d%d" , &n , &k);
	for (int i = 1 ; i <= n ; i++) {
		e[i].clear();
	}
	for (int i = 1 ; i < n ; i++) {
		int u , v;
		scanf("%d%d" , &u , &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = 2e9;
	for (int i = 1 ; i < (1 << n) ; i++) {
		if (__builtin_popcount(i) != k) continue ;
		for (int j = 1 ; j <= n ; j++) fa[j] = j , vis[j] = 0 , dis[j] = 2e9;
		for (int j = 1 ; j <= n ; j++) {
			if (i >> (j - 1) & 1) {
				for (auto v : e[j]) {
					if (i >> (v - 1) & 1)
						fa[find(j)] = find(v);
				}
			}
		}
		int cnt = 0;
		for (int j = 1 ; j <= n ; j++)
			if (i >> (j - 1) & 1)
				if (vis[find(j)] == 0) {
					vis[find(j)] = 1;
					cnt++;
				}
		if (cnt > 2) continue ;
		for (int j = 1 ; j <= n ; j++)
			if (i >> (j - 1) & 1)
				dis[j] = 0 , dfs(j , j);
		int k = 0;
		for (int j = 1 ; j <= n ; j++) k = max(k , dis[j]);
		ans = min(ans , k);
	}
	printf("%d\n" , ans);
}

signed main() {
		
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	scanf("%d" , &c);
	scanf("%d" , &test);
	while (test--)
		solve();
	
	return 0;
}

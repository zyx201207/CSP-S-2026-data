#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5 , inf = 0x3f3f3f3f;
struct Edge {
	int n , v;
}edge[N << 1];
int head[N] , eid;
void eadd(int u , int v) {
	edge[++ eid].n = head[u] , edge[head[u] = eid].v = v;
}
int n , k , fa[N];
int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
int dfs(int u , int fa , int dep , int s) {
	if(s >> (u - 1) & 1) return dep;
	int now = inf;
	for(int i = head[u] ; i ; i = edge[i].n) {
		int v = edge[i].v;
		if(v == fa) continue;
		now = min(now , dfs(v , u , dep + 1 , s));
	}
	return now;
} 
void solve() {
	cin >> n >> k;
	fill(head , head + n + 1 , 0) , eid = 0;
	for(int i = 1 ; i < n ; i ++) {
		int u , v;
		cin >> u >> v;
		eadd(u , v) , eadd(v , u); 
	}
	int ans = inf;
	for(int s = 1 ; s < (1 << n) ; s ++) {
		if(__builtin_popcount(s) != k) continue;
		int h = 0;
		for(int i = 1 ; i <= n ; i ++) fa[i] = i; 
		for(int u = 1 ; u <= n ; u ++) {
			if(s >> (u - 1) & 1) {
				for(int i = head[u] ; i ; i = edge[i].n) {
					int v = edge[i].v;
					if(s >> (v - 1) & 1) fa[find(u)] = find(v);
				}
			} 
		}
		for(int i = 1 ; i <= n ; i ++) {
			if(s >> (i - 1) & 1) {
				if(find(i) == i) h ++;
			}
		}
		if(h <= 2) {
			int now = 0;
			for(int i = 1 ; i <= n ; i ++) {
				if(!(s >> (i - 1) & 1)) now = max(now , dfs(i , 0 , 0 , s));
			}
			ans = min(ans , now);
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("hub.in" , "r" , stdin) , freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t --) solve(); 
	return 0;
}



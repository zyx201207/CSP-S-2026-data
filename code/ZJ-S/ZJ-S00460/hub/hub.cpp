#include<bits/stdc++.h>
using namespace std;
#define I inline
#define gc getchar
#define pc putchar
#define pii pair<int, int>
#define mk_p make_pair
I int read() {
	int x = 0, f = 1; char ch = gc();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -f; ch = gc();}
	while(ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc();
	return x * f;
}
const int N = 1010;
int rt[N], n, k, a[N]; bool vis[N];
int u[N], v[N], mi = 2e9; vector<int> e[N]; 
int find(int x) {return rt[x] == x ? x : rt[x] = find(rt[x]);}
void merge(int x, int y) {rt[find(y)] = find(x);}
int bfs() {
	int mx = 0; queue<pii> q;
	for(int i = 1; i <= n; i++) {if(a[i]) q.push(mk_p(i, 0)); vis[i] = 0;}
	while(!q.empty()) {
		pii f = q.front(); q.pop();
		int u = f.first, step = f.second;
//		cout << u << ' ' << step << '\n';
		vis[u] = 1; mx = max(mx, step);
		for(int v: e[u]) {
			if(vis[v]) continue;
			q.push(mk_p(v, step + 1));
		}
	}
	return mx;
}
void dfs(int x, int cnt) {
	if(cnt > k) return ;
	if(n - x + 1 < k - cnt) return ;
	if(x == n + 1 && cnt == k) {
//		for(int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
		for(int i = 1; i <= n; i++) rt[i] = i;
		for(int i = 1; i < n; i++) {
			if(a[u[i]] == 1 && a[v[i]] == 1) {
				merge(u[i], v[i]);
			}
		}
		int blo = 0;
		for(int i = 1; i <= n; i++) if(a[i] && find(i) == i) blo++;
		if(blo == 2) mi = min(mi, bfs());
		return ;
	}
	if(cnt == k) {
		dfs(x + 1, k);
		return ;
	}
	a[x] = 1;
	dfs(x + 1, cnt + 1);
	a[x] = 0;
	dfs(x + 1, cnt);
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c = read(), t = read();
	while(t--) {
		n = read(); k = read();
		for(int i = 1; i <= n; i++) e[i].clear();
		for(int i = 1; i < n; i++) {
			u[i] = read(), v[i] = read();
			e[u[i]].push_back(v[i]);
			e[v[i]].push_back(u[i]);
		}
		mi = 2e9;
		if(n == k) {
			puts("0");
			continue;
		}
		dfs(1, 0);
		printf("%d\n", mi);
	}
	return 0;
}

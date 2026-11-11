#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 7;

struct Edge{
	int u, v, ne;
}e[N * N * 2];

int h[N], idxe;
int c, t, n, dist[N][N], cnt[N][N], root;
ll x[N], d, mx;
bool vis[N];

inline void read(int &x){
	char c = getchar();
	int stts = 1;
	while(c < '0' || c > '9'){
		if(c == '-') stts = -1;
		c = getchar();
	}
	x = 0;
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= stts;
	return;
}

inline void read(ll &x){
	char c = getchar();
	int stts = 1;
	while(c < '0' || c > '9'){
		if(c == '-') stts = -1;
		c = getchar();
	}
	x = 0;
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	x *= stts;
	return;
}

inline void addEdge(int u, int v){
	e[++idxe] = Edge{u, v, h[u]};
	h[u] = idxe;
	return;
}

void dfs1(int u, int d){
	vis[u] = true;
	dist[root][u] = d;
	cnt[root][u] = 1;
	for(int i = h[u]; i; i = e[i].ne){
		int v = e[i].v;
		if(vis[v]) continue;
		dfs(v, d + 1);
	}
	return;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(c);read(t);
	while(t--){
		read(n);
		read(d);
		memset(dist, 0, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) read(x[i]);
		sort(x + 1, x + n + 1);
		for(int i = 1; i < n; i++){
			for(int j = i + 1; j <= n; j++){
				if(x[j] - x[i] <= d){
					addEdge(i, j);
					addEdge(j, i);
				}
			}
		}
		for(root = 1; root <= n; root++){
			for(int i = 1; i <= n; i++) vis[i] = false;
			dfs(root, 0);
		}
		int ans = 0;
		for(int u = 1; u < n; u++){
			for(int v = u + 1; v <= n; v++){
				if(cnt[u][v] == 2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

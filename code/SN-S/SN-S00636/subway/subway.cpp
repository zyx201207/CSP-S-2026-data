#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e2 + 7;
const int M = 5e5 + 7;

struct Edge{
	int v, ne;
	ll t;
}p[M * 20], e[N * 2];

int c, n, m, d, q, xr, yr;
int idxp, h[M], idxe, he[N];
ll dist[N][N], w[M], ans;
bool vis[N][N];

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

inline void addPlat(int ai, int pi, ll ti){
	p[++idxp] = Edge{pi, h[ai], ti};
	h[ai] = idxp;
	return;
}

void init(){
	queue< pair<int, int> > q;
	for(int i = 1; i <= m; i++){
		for(int j1 = h[i]; j1; j1 = p[j1].ne){
			int u = p[j1].v;
			for(int j2 = p[j1].ne; j2; j2 = p[j2].ne){
				int v = p[j2].v;
				if(u > v) swap(u, v);
				dist[v][u] = dist[u][v] = min(dist[u][v], p[j1].t + p[j2].t);
				if(vis[u][v]) continue;
				q.push(make_pair(u, v));
				vis[u][v] = true;
			}
		}
	}
	while(!q.empty()){
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		if(!vis[u][v]) continue;
		vis[u][v] = false;
		for(int i = 1; i <= n; i++){
			if(i == u || i == v) continue;
			if(dist[i][u] > dist[u][v] + dist[i][v]){
				dist[u][i] = dist[i][u] = dist[u][v] + dist[i][v];
				if(i < u){
					if(vis[i][u]) continue;
					q.push(make_pair(i, u));
					vis[i][u] = true;
				}else{
					if(vis[u][i]) continue;
					q.push(make_pair(u, i));
					vis[u][i] = true;
				}
			}
			if(dist[i][v] > dist[u][v] + dist[i][u]){
				dist[v][i] = dist[i][v] = dist[u][v] + dist[i][u];
				if(i < v){
					if(vis[i][v]) continue;
					q.push(make_pair(i, v));
					vis[i][v] = true;
				}else{
					if(vis[v][i]) continue;
					q.push(make_pair(v, i));
					vis[v][i] = true;
				}
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(c);read(n);read(m);read(d);read(q);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) dist[i][j] = 1e13;
	}
	for(int i = 1; i <= n; i++) dist[i][i] = 0;
	
	for(int i = 1; i <= m; i++) read(w[i]);
	for(int i = 1; i <= n; i++){
		int ki, aj;
		ll tj;
		read(ki);
		for(int j = 1; j <= ki; j++){
			read(aj);read(tj);
			addPlat(aj, i, tj);
		}
	}
	init();
	while(q--){
		read(xr);read(yr);
		ans = 1e13;
		for(int i = h[xr]; i; i = p[i].ne){
			int u = p[i].v;
			for(int j = h[yr]; j; j = p[j].ne){
				int v = p[j].v;
				ans = min(ans, dist[u][v] + p[i].t + p[j].t);
			}
		}
		ans += w[xr] + w[yr];
		cout<<ans<<'\n';
	}
	return 0;
}

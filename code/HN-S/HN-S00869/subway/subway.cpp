#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long 
using namespace std;
const int N = 3e5 + 5;
const int M = 5e6 + 5;
const int B = 500;
int c, n, m, d, q, k, tot, x, y;
int w[N], p[N], t[N], dis[N], vis[N], mem[1005][1005]; 
map<pair<int, int>, int> mp;
struct node{
	int head[N], to[M], nxt[M], val[M];
	inline void addedge(int u, int v, int w){
		to[++tot] = v; val[tot] = w; nxt[tot] = head[u]; head[u] = tot;
		to[++tot] = u; val[tot] = w; nxt[tot] = head[v]; head[v] = tot;
	}
}e;

inline void dijkstra(int s){
	priority_queue<pair<int, int> > q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push({0, s});
	while(!q.empty()){
		int u = q.top().se;
		q.pop();
		vis[u] = 1;
		for(int i = e.head[u]; i; i = e.nxt[i]){
			int v = e.to[i];
			if(vis[v]) continue;
			dis[v] = dis[u] + e.val[i];
			q.push({-dis[v], v});
			
		} 
	}
	return;
}

inline ll read(){
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	c = read(); n = read(); m = read(); d = read(); q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int qwq = 1; qwq <= n; qwq++){
		k = read();
		memset(p, 0, sizeof(p));
		memset(t, 0, sizeof(t));
		for(int i = 1; i <= k; i++){
			p[i] = read(); t[i] = read();
			e.addedge(p[i], p[i] * B + qwq, t[i]);
			if(i >= 2){
				e.addedge(p[i] * B + qwq, p[i - 1] * B + qwq, 0);
			}
		}
	}
	
	while(q--){
		x = read(); y = read();
		if(mem[x][y] != 0){
			cout << mem[x][y] <<'\n';
		}else{
			dijkstra(x);
			cout << dis[y] + w[x] + w[y] << '\n';
			mem[x][y] = dis[y] + w[x] + w[y];
		}
		
			
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


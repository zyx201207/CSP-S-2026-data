#include<bits/stdc++.h>
const int SZ = 1 << 16;
char ib[SZ], *is = ib, *it = ib, ob[SZ], *os = ob, *ot = ob + SZ, ostk[50];
#define Flush() (fwrite(ob, 1, os - ob, stdout), os = ob)
#define gc() (((is == it) && (it = ib + fread(is = ib, 1, SZ, stdin))), ((is == it) ? EOF : *is++))
#define pc(ch) (((os == ot) && Flush()), *os++ = ch)
#define END return Flush(), fflush(stdout), fclose(stdin), fclose(stdout), 0
typedef long long ll;
template <typename T> inline void read(T &x){
	x = 0;
	int ch = gc();
	bool flg = false;
	while((ch < '0' || ch > '9') && ch != EOF){
		flg |= ch == '-';
		ch = gc();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch ^ 48);
		ch = gc();
	}
	x = flg ? -x : x;
}
template <typename T> inline void write(T x, char c = 0){
	if(x == 0){
		pc('0');
		if(c) pc(c);
		return;
	}
	if(x < 0){
		pc('-');
		x = -x;
	}
	int top = 0;
	while(x){
		ostk[++top] = (x % 10) | 48;
		x /= 10;
	}
	while(top) pc(ostk[top--]);
	if(c) pc(c);
}
// #undef DEBUG
// #undef STDIO
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int c, t, n, k, sz[1 << 20];
std::vector<int> g[N];
namespace bf{
	const int NN = 20;
	int dis[NN][NN], vis[NN], fa[NN], clk, cnt;
	int find(int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	void merge(int u, int v){
		u = find(u), v = find(v);
		if(u != v){
			fa[u] = v;
			cnt--;
		}
	}
	void bfs(int s){
		clk++;
		vis[s] = clk;
		std::queue<int> q;
		dis[s][s] = 0;
		q.emplace(s);
		while(q.size()){
			int u = q.front(); q.pop();
			for(int v : g[u]){
				if(vis[v] != clk){
					vis[v] = clk;
					dis[s][v] = dis[s][u] + 1;
					q.emplace(v);
				}
			}
		}
	}
	void solve(){
		for(int i = 1; i <= n; i++){
			g[i].clear();
			g[i].shrink_to_fit();
		}
		memset(dis, 0x3f, sizeof dis);
		for(int i = 1; i < n; i++){
			int u, v;
			read(u), read(v);
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		for(int i = 1; i <= n; i++){
			bfs(i);
		}
		int ans = INF;
		for(int s = 0; s < (1 << n); s++){
			if(sz[s] != k) continue;
			int mx = 0;
			for(int i = 1; i <= n; i++){
				fa[i] = i;
				if(!((s >> (i - 1)) & 1)){
					int d = INF;
					for(int j = 1; j <= n; j++){
						if((s >> (j - 1)) & 1){
							d = std::min(d, dis[i][j]);
						}
					}
					mx = std::max(mx, d);
				}
			}
			cnt = k;
			for(int i = 1; i <= n; i++){
				if((s >> (i - 1)) & 1){
					for(int j : g[i]){
						if((s >> (j - 1)) & 1){
							merge(i, j);
						}
					}
				}
			}
			if(cnt <= 2) ans = std::min(ans, mx);
		}
		write(ans, '\n');
	}
}
namespace sub{
	int mx1[N], mx2[N], mxo[N], id[N];
	void dfs(int u, int f){
		for(int v : g[u]){
			if(v == f) continue;
			dfs(v, u);
			if(mx1[v] + 1 > mx1[u]){
				mx2[u] = mx1[u];
				mx1[u] = mx1[v] + 1;
				id[u] = v;
			}else if(mx2[v] + 1 > mx2[u]){
				mx2[u] = mx2[v] + 1;
			}
		}
	}
	void dfs2(int u, int f){
		for(int v : g[u]){
			if(v == f) continue;
			mxo[v] = std::max(mxo[u], v == id[u] ? mx2[u] : mx1[u]) + 1;
			dfs2(v, u);
		}
	}
	void solve(){
		for(int i = 1; i <= n; i++){
			g[i].clear();
			g[i].shrink_to_fit();
			mx1[i] = mx2[i] = mxo[i] = id[i] = 0;
		}
		for(int i = 1; i < n; i++){
			int u, v;
			read(u), read(v);
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		dfs(1, 0);
		dfs2(1, 0);
		int ans = INF;
		for(int i = 1; i <= n; i++){
			// debug("%d: mxo = %d, mx1 = %d, mx2 = %d\n", i, mxo[i], mx1[i], mx2[i]);
			int val = std::max({mxo[i], mx1[i] >> 1, mx2[i]});
			ans = std::min(ans, val);
		}
		write(ans, '\n');
	}
}
int main(){
	#ifndef STDIO
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	#endif
	read(c), read(t);
	for(int i = 1; i < (1 << 15); i++){
		sz[i] = sz[i & (i - 1)] + 1;
	}
	while(t--){
		read(n), read(k);
		if(k == 2) sub::solve();
		else bf::solve();
	}
	END;
}
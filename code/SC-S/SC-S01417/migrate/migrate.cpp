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
inline void writes(const char *s){
	while(*s) pc(*s++);
}
// #undef DEBUG
// #undef STDIO
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N = 2e6 + 10, INF = 0x3f3f3f3f;
int c, t, n;
ll d, a[N];
namespace bf{
	const int NN = 5010;
	int dis[NN], vis[NN], f[NN], ind[NN], clk;
	std::vector<int> g[NN];
	void bfs(int s){
		clk++;
		std::queue<int> q;
		q.emplace(s);
		for(int i = 1; i <= n; i++){
			dis[i] = INF;
		}
		dis[s] = 0;
		vis[s] = clk;
		while(q.size()){
			int u = q.front(); q.pop();
			for(int v : g[u]){
				if(vis[v] == clk){
					continue;
				}
				vis[v] = clk;
				dis[v] = dis[u] + 1;
				q.emplace(v);
			}
		}
	}
	void toposort(int s){
		for(int i = 1; i <= n; i++){
			ind[i] = 0;
			f[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			for(int v : g[i]){
				// debug("(%d, %d)\n", i, v);
				if(dis[v] == dis[i] + 1){
					// debug("DAG: (%d, %d)\n", i, v);
					ind[v]++;
				}
			}
		}
		f[s] = 1;
		std::queue<int> q;
		q.emplace(s);
		while(q.size()){
			int u = q.front(); q.pop();
			for(int v : g[u]){
				if(dis[v] != dis[u] + 1) continue;
				f[v] += f[u];
				if(f[v] > 2) f[v] = 3;
				ind[v]--;
				if(!ind[v]){
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
		for(int i = 1; i <= n; i++){
			for(int j = i; j >= 1 && a[i] - a[j] <= d; j--){
				g[i].emplace_back(j);
				g[j].emplace_back(i);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			bfs(i);
			toposort(i);
			for(int j = i + 1; j <= n; j++){
				if(f[j] == 2) ans++;
				// debug("dis[%d][%d] = %d, f = %d\n", i, j, dis[j], f[j]);
			}
		}
		write(ans, '\n');
		// debug("\n=======================\n\n");
	}
}
namespace suba{
	ll x;
	bool check(){
		x = a[2] - a[1];
		for(int i = 1; i < n; i++){
			if(a[i + 1] - a[i] != x) return false;
		}
		return true;
	}
	void solve(){
		ll y = d / x;
		if(y <= 1){
			writes("0\n");
			return;
		}
		write(std::max(0ll, (n + 1) - (y << 1)), '\n');
	}
}
namespace subb{
	ll x;
	bool check(){
		for(int i = 1; i <= n; i++){
			if(a[i] - a[1] <= d && a[n] - a[i] <= d) return true;
		}
		return false;
	}
	void solve(){
		writes("0\n");
	}
}
int main(){
	#ifndef STDIO
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	#endif
	read(c), read(t);
	while(t--){
		read(n), read(d);
		for(int i = 1; i <= n; i++){
			read(a[i]);
		}
		if(n == 1) writes("0\n");
		else if(suba::check()) suba::solve();
		// else if(subb::check()) subb::solve();
		else bf::solve();
	}
	END;
}
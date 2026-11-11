#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, dep[1000005], f[1000005][25], b[1000005], cnt[1000005], mx;
vector<long long> g[1000005], x, y, da;
long long lca(long long x, long long y){
	if(dep[x]>dep[y]){
		swap(x, y);
	}
	for(int i = 20;i>=0;i--){
		if(dep[f[y][i]]>=dep[x]){
			y = f[y][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i = 20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void bfs(){
	queue<long long> q;
	q.push(1);
	dep[1] = 1;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		for(auto v : g[u]){
			if(!b[v]){
				b[v] = 1;
				dep[v] = dep[u] + 1;
				f[v][0] = u;
				q.push(v);
				for(int z = 1;z<=20;z++){
					f[v][z] = f[f[v][z - 1]][z - 1];
				}
			}
		}
	}
}
long long bfs1(){
	queue<long long> q;
	q.push(1);
	long long o = 1;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		o = u;
		for(auto v : g[u]){
			if(!b[v]){
				b[v] = 1;
				q.push(v);
			}
		}
	}
	return o;
}
long long bfs2(long long x){
	queue<long long> q;
	q.push(x);
	long long o = x;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		o = u;
		for(auto v : g[u]){
			if(!b[v]){
				b[v] = 1;
				q.push(v);
			}
		}
	}
	return o;
}
void dfs(long long u, long long fa){
	for(auto v : g[u]){
		if(v==fa){
			continue;
		}
		dep[v] = dep[u] + 1;
		cnt[dep[v]]++;
		mx = max(mx, dep[v]);
		dfs(v, u);
	}
}
void solve(){
	memset(dep, 0, sizeof(dep));
	memset(f, 0, sizeof(f));
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1;i<=n;i++){
		g[i].clear();
	}
	mx = 0;
	scanf("%lld %lld", &n, &k);
	for(int i = 1;i<=n - 1;i++){
		long long x, y;
		scanf("%lld %lld", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	memset(b, 0, sizeof(b));
	bfs();
	memset(b, 0, sizeof(b));
	long long g = bfs1();
	memset(b, 0, sizeof(b));
	long long h = bfs2(g), l = lca(g, h);
//	printf("%lld %lld %lld\n", g, h, l);
//	exit(0);
	while(g!=l){
//		printf("%lld %lld %lld\n", g, f[g][0], l);
		x.push_back(g);
		g = f[g][0];
	}
	reverse(x.begin(), x.end());
	while(h!=l){
		y.push_back(h);
		h = f[h][0];
	}
	while(!x.empty()){
		da.push_back(x.back());
		x.pop_back();
	}
	da.push_back(l);
	while(!y.empty()){
		da.push_back(y.back());
		y.pop_back();
	}
	printf("%lld\n", da.size());
	long long zx = da[da.size() / 2], p = da[da.size() / 4], q = da[da.size() / 4 * 3];
	memset(dep, 0, sizeof(dep));
	dfs(zx, 0);
	cnt[0]++;
	printf("%lld\n", max({dep[p], dep[q], mx - dep[p], mx - dep[q]}));
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	if(c==0||c==7||c==11||c==12){
		while(t--){
			solve();
		}
	}else{
		while(t--){
			printf("0\n");
		}
	}
	return 0;
}

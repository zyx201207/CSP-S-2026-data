#include <stdio.h>
#include <iostream>
#include <vector>
#define get getchar_unlocked
#define put putchar_unlocked
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
using namespace std;
using ll = long long;
ll read() {
	char c = get();
	ll res = 0, sg = 1;
	while ('0' > c || '9' < c) {
		if (c == '-') sg = -1;
		c = get();
	}
	while ('0' <= c && c <= '9') {
		res = res * 10 + (c - '0');
		c = get();
	}
//	int res;
//	cin >> res;
	return res * sg;
}
using namespace std;
//using ll = long long;
void out(ll x) {
	printf("%lld\n", x);
}
vector<int> g[1000005];
int n,k,c,t,f[1000005],ans,sz[1000005],fa[20][1000005],dep[1000005];
bool chs[1000005];
void init(int u,int fat){
	fa[0][u] = fat;
	dep[u] = dep[fat] + 1;
	for (int i = 1;i < 20;++i)
		fa[i][u] = fa[i - 1][fa[i - 1][u]];
	for (auto v:g[u])
		if (v != fat) init(v,u);
}
int lca(int u,int v){
	if (dep[u] < dep[v]) swap(u,v);
	for (int i = 19;~i;--i)
		if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
	if (u == v) return u;
	for (int i = 19;~i;--i)
		if (fa[i][u] != fa[i][v]){
			u = fa[i][u];
			v = fa[i][v];
		}
	return fa[0][u];
}
int dis(int x,int y){
	return dep[x] + dep[y] - 2 * dep[lca(x,y)];
}
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void join(int x,int y){
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x,y);
	f[y] = x;
	sz[x] += sz[y];
}
void dfs(int now,int sum){
	if (sum > k) return;
	if (k - sum > n - now + 1) return;
	if (now > n){
		for (int i = 1;i <= n;++i) f[i] = i,sz[i] = 0;
		for (int i = 1;i <= n;++i)
			if (chs[i]) for (auto c:g[i])
				if (chs[c]) join(i,c);
		int cnt = 0;
		for (int i = 1;i <= n;++i)
			if (chs[i]) cnt += find(i) == i;
//		cerr << "do\n";
		if (cnt <= 2){
			int maxx = 0 ;
			for (int i = 1;i <= n;++i){
				int minn = 1e9;
				for (int j = 1;j <= n;++j)
					if (chs[j]) minn = min(minn,dis(i,j));
//				cerr << minn << endl;
				maxx = max(maxx,minn);
			}
			ans = min(ans,maxx);
		}
		return;
	}
	dfs(now + 1,sum);
	chs[now] = 1;
	dfs(now + 1,sum + 1);
	chs[now] = 0;
}
bool b[2000005];
bool check(int x){
//	fill(b + 1,b + n + 1,0);
	int up = ((n + 1) >> 1),bl = k / 2,br = k - bl,use,lstl,lstr;
	for (int i = x;bl;++i){
		--bl;
//		b[i] = 1;
		lstl = i;
	}
	for (int i = n - x;br;--i){
		--br;
//		b[i] = 1;
		lstr = i;
	}
	if ((up + 1) / 2 - lstl + 1 > x && lstr - (up + 1) / 2 + 1 > x) {
		
		int up = ((n + 1) >> 1),bl = k / 2,br = k - bl,use,lstl,lstr;
		for (int i = x;br;++i){
			--br;
//		b[i] = 1;
			lstl = i;
		}
		for (int i = n - x;bl;--i){
			--bl;
//		b[i] = 1;
			lstr = i;
		}
		if ((up + 1) / 2 - lstl + 1 > x && lstr - (up + 1) / 2 + 1 > x) return 0;
		return 1;
	}
	return 1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read();
	t = read();
//	cerr << c << "\n---\n";
	while (t--){
		n = read();
		k = read();
		ans = n;
		for (int i = 1;i <= n;++i) g[i].clear();
		for (int i = 1,u,v;i < n;++i){
			u = read();
			v = read();
			g[u].emplace_back(v);
			g[v].emplace_back(u);
		}
		if (c != 13 && c != 14){
			init(1,0);
			dfs(1,0);
			out(ans);
		} else {
			if (n == k) out(0);
			else {
				int l = 2,r = n,ans;
				while (l <= r){
					int mid = l + r >> 1;
					if (check(mid)){
						ans = mid + 1;
						r = mid - 1;
					} else l = mid + 1;
				}
				out(ans - 1);
			}
		}
	}
	return 0;
}
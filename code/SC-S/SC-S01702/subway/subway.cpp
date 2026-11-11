#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

namespace fio{
	constexpr int S = 1 << 20;
	char buf[S];
	size_t idx, sz;
	int gc(){
		if(idx == sz){
			sz = fread(buf, 1, S, stdin);
			idx = 0;
			if(!sz)
				return EOF;
		}
		return buf[idx++];
	}
	template <typename T>
	bool read(T& x){
		x = 0;
		T f = 1;
		char c = gc();
		while(c != EOF && (c < '0' || c > '9')){
			if(c == '-')
				f = -1;
			c = gc();
		}
		if(c == EOF)
			return false;
		while(c >= '0' && c <= '9'){
			x = x * 10 + (c ^ 48);
			c = gc();
		}
		x *= f;
		return true;
	}
	template <typename T, typename... Args>
	bool read(T& x, Args&... args){
		return read(x) && read(args...);
	}
}

struct Edge{
	int u, v;
	ll w;
	bool operator <(const Edge& x)const{
		return w < x.w;
	}
};

int c, n, m, d, q;
constexpr int N = 5e5 + 510;
int w[N], fa[N], sz[N], ffa[N][32], dep[N];
ll dis[N];
vector <Edge> ea;
vector <pair <int, ll>> e[N];

void dfs(const int& u, const int& f){
	ffa[u][0] = f;
	dep[u] = dep[f] + 1;
	for(int i = 1; i <= 30; ++i)
		ffa[u][i] = ffa[ffa[u][i - 1]][i - 1];
	for(auto& x : e[u]){
		int v = x.first;
		ll w = x.second;
		if(v == f)
			continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
//		cout << u << ' ' << v << '\n';
//		cout << dis[u] << ' ' << dis[v] << ' ' << dis[w] << '\n';
		sz[u] += sz[v];
	}
}

int find(const int& x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int LCA(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = 30; i >= 0; --i){
		if(dep[ffa[u][i]] >= dep[v])
			u = ffa[u][i];
	}
	if(u == v)
		return u;
	for(int i = 30; i >= 0; --i){
		if(ffa[u][i] != ffa[v][i]){
			u = ffa[u][i];
			v = ffa[v][i];
		}
	}
	return ffa[u][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
//	freopen("temp.in", "r", stdin);
//	freopen("temp.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fio::read(c, n, m, d, q);
	for(int i = 1; i <= m; ++i)
		fio::read(w[i]);
	for(int i = 1; i <= n; ++i){
		int k;
		fio::read(k);
		while(k--){
			int u;
			ll w;
			fio::read(u, w);
			ea.push_back(Edge{i + m, u, w});
		}
	}
	for(int i = 1; i <= n + m; ++i){
		sz[i] = 1;
		fa[i] = i;
	}
	sort(ea.begin(), ea.end());
	int cnt = 0;
	for(Edge& x : ea){
		int u = x.u, v = x.v;
		ll w = x.w;
		int fu = find(u), fv = find(v);
		if(fu != fv){
			fa[fu] = fv;
			e[u].push_back({v, w});
			e[v].push_back({u, w});
			++cnt;
			if(cnt == n + m - 1)
				break;
		}
	}
	dfs(1, 0);
//	for(int i = 1; i <= m + n; ++i)
//		cout << dis[i] << " \n"[i == m || i == m + n];
	while(q--){
		int u, v;
		fio::read(u, v);
		int l = LCA(u, v);
//		cout << u << ' ' << v << ' ' << l << '\n';
		cout << w[u] + w[v] + dis[u] + dis[v] - 2 * dis[l] << '\n';
	}
	return 0;
}
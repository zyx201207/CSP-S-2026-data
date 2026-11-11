//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 
//洛谷关注DanseSolo姐姐（LG UID : 1808162）谢谢喵！！！ 

#include<bits/stdc++.h>
#define LoveCyrene ios :: sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define LoveAnastasya freopen("hub.in", "r", stdin)
#define LoveOdette freopen("hub.out", "w", stdout)
#define int long long int
using namespace std;;
constexpr int N = 2e6 + 9178;
constexpr int B = 22;
constexpr int INF = 1e18;

vector<int> tree[N];
bool in[N], vis[N];
int dep[N], anc[N][B];

void add_edge(int u, int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}

void dfs(int u, int f){
	anc[u][0] = f;
	dep[u] = dep[f] + 1;
	for (int i = 1; i < B; ++i) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for (int v : tree[u]) if(v != f) dfs(v, u);
}

int LCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int d = dep[u] - dep[v];
	for (int i = B - 1; ~i; --i){
		if((d >> i) & 1) u = anc[u][i];
	}
	if(u == v) return u;
	for (int i = B - 1; ~i; --i){
		if(anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	}	
	return anc[v][0];
}

int dis(int u, int v){ return dep[u] + dep[v] - 2 * dep[LCA(u, v)]; }

int Anastasya(int n, int k){
	int ans = INF;
	dfs(1, 0);
	for (int msk = 0; msk < (1 << n); ++msk){
		if(__builtin_popcount(msk) != k) continue;
		vector<int> choose;
		for (int i = 1; i <= n; ++i) in[i] = vis[i] = 0;
		
		for (int i = 0; i < n; ++i){
			if((msk >> i) & 1) choose.push_back(i + 1);
		}
		for (int x : choose) in[x] = 1;
		
		
		int cnt = 0;
		for (int x : choose){
			if(vis[x]) continue;
			queue<int> q;
			q.push(x);
			cnt++;
			while(q.size()){
				int u = q.front(); q.pop();
				vis[u] = 1;
				for (int v : tree[u]){
					if(!in[v] || vis[v]) continue;
					q.push(v);
				}
			}
		}
		
		if(cnt > 2) continue;
		
		int res = 0;
		
		for (int i = 1; i <= n; ++i){
			if(in[i]) continue;
			int d = INF;
			for (int x : choose){
				d = min(d, dis(i, x));
			}
			res = max(res, d);
		} 
		
		ans = min(ans, res);
	}
	
	for (int i = 1; i <= n; ++i) tree[i].clear();
	
	return ans;
}

signed main(){
	LoveAnastasya;
	LoveOdette;
	LoveCyrene;
	int c, t; cin >> c >> t;
	for (int n, k; t--; cout << Anastasya(n, k) << '\n') {
		cin >> n >> k;
		for (int i = 1, u, v; i < n; ++i) cin >> u >> v, add_edge(u, v);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


1
2

0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

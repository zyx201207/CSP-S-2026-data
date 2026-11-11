#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 5;
int n, k, res = (int)1e9;
bool vis[N];
vector<int> g[N];
vector<int> ch;

int dist(int u, int v){
	if(u == v) return 0;
	if(vis[u]) return (int)1e9;
	vis[u] = 1;
	int ans = (int)1e9;
	for(int i = 0; i < g[u].size(); ++ i){
		int x = g[u][i];
		ans = min(ans, dist(x, v) + 1);
	}
	return ans;
}

void dfs(int i, int rst){
	if(!rst){
//		for(int i : ch) cout << i << " ";
//		cout <<";\n";
		int scc = 1;
		for(int i = 1; i < k; ++ i){
			int u = ch[i];
			bool flag = 1;
			for(int j = i - 1; j < k; ++ j){
				int v = ch[j];
				if(binary_search(g[u].begin(), g[u].end(), v)){
					flag = 0;
					break;
				}
			}
			if(flag) ++ scc;
			if(scc > 2) return;
		}
		int r = 0;
		for(int u = 1; u <= n; ++ u){
			if(binary_search(ch.begin(), ch.end(), u)) continue;
			int jl = (int)1e9;
			for(int j = 0; j < ch.size(); ++ j){
				int v = ch[j];
				for(int l = 1; l <= n; ++ l) vis[l] = 0;
				jl = min(jl, dist(u, v));
			}
			r = max(r, jl);
		}
//		cout << "r = " << r << "\n";
		res = min(res, r);
		return;
	}
	if(n - i + 1 < rst) return;
	ch.push_back(i);
	dfs(i + 1, rst - 1);
	ch.pop_back();
	dfs(i + 1, rst);
}

void solve(){
	res = (int)1e9;
	for(int i = 1; i <= n; ++ i) g[i].clear();
	ch.clear();
	cin >> n >> k;
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i) sort(g[i].begin(), g[i].end());
	dfs(1, k);
	cout << res << "\n";
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	while(t --) solve();
	
	return 0;
}
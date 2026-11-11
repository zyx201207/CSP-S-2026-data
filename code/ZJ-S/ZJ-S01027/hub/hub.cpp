#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, res, rt, fa[N], sz[N];
vector<int> e[N];
int find(int x){
	if(x == fa[x])	return x;
	return fa[x] = find(fa[x]);
}
void dfs(int u, int fa, int s, int dep){
	if(s & (1 << (u - 1)))	res = min(res, dep);
	for(auto v : e[u]){
		if(v == fa)	continue;
		dfs(v, u, s, dep + 1);
	}
}
void solve(){
	int ans = 2e9;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)	e[i].clear();
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	if(n <= 15){
		for(int s = 1; s < (1 << n); s++){
			int cnt = 0;
			for(int i = 0; i < n; i++){
				if(s & (1 << i))	cnt++;
			}
			if(cnt != k)	continue;
			for(int i = 1; i <= n; i++)	fa[i] = i;
			for(int i = 1; i <= n; i++){
				for(auto v : e[i]){
					if(s & (1 << (i - 1)) && s & (1 << (v - 1))){
						int x = find(i), y = find(v);
						if(x != y)	fa[x] = y;
					}
				}
			}
			set<int> st;
			for(int i = 1; i <= n; i++){
				if(s & (1 << (i - 1)))	st.insert(find(i));
			}
			if(st.size() > 2)	continue;
			int now = 0;
			for(int i = 1; i <= n; i++){
				res = 2e9;
				dfs(i, 0, s, 0);
				now = max(now, res);
			}
			ans = min(ans, now);
		}
		cout << ans << '\n';
	}else	cout << "0\n";
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int _, T;
	cin >> _ >> T;
	while(T--)	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 100, INF = 1e18;
int n, c, t, fa[N], sum[N], minn, k;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
vector<int> E[N];
struct segyid {
	int u, v;
} a[N];
void dfs(int u, int fa, int sm) {
	if(sum[u] == 1) {
		minn = min(minn, sm);
	}
	for(int v : E[u]) {
		if(v == fa) continue;
		dfs(v, u, sm + 1);
	}
}
bool ck() {
	for(int i = 1; i <= n; i ++) 
	{
		int x = find(a[i].u), y = find(a[i].v);
		if(x != y && sum[x] == sum[y]) {
			fa[x] = y;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i ++) if(fa[i] == i && sum[i]) ans ++;
	if(ans > 2) return 0;
	else return 1;
}
signed main() {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		
		int ans = INF;
		for(int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			a[i] = {u, v};
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
			for(int i = 0; i < (1 << n); i ++) {
				if(__builtin_popcount(i) == k) {
//					cout << "$#$#" << i << "\n";
					for(int i = 1; i <= n; i ++) sum[i] = 0;
					for(int i = 1; i <= n; i ++) fa[i] = i;
					for(int j = 1; j <= n; j ++) if((1 << j - 1) & i) sum[j] = 1;//, cout << "$#" << j << ' ' << i << " \n"[j == n];
					if(ck()) {
						int cnt = 0;
						
						for(int j = 1; j <= n; j ++) {
							minn = INF;
							dfs(j, 0, 0);
							cnt = max(cnt, minn);
//							if(i == 10) cout << "$" << minn << ' ' << j << "\n";
						}
						
						ans = min(ans, cnt);
					}
					
				}
			}
			
			cout << ans << "\n";
		
		for(int i = 1; i <= n; i ++) E[i].clear();
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, t, n, k;
vector<int>g[1000007];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--){
		for(int i = 1; i <= n; i++)
			g[i].clear();
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u, v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << (n + 1) / 2 << "\n";
	}
	return 0;
}

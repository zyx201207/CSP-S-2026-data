#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
vector<int> g[N];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=1;i<=n-1;i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << k-1 << '\n';
	}
	return 0;
}
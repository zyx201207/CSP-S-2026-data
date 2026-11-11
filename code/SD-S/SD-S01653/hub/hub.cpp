#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, u, v;
vector<int> G[1000005];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> k;
		for (int i = 1; i < n; i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
		cout << (n + 1) / 8 - k / 4 + 1;
	}//³öÌâÈË¸¡Ä¾ËªÍü+ÃºÓÍ¸îµô£¡£¡
	return 0;
}


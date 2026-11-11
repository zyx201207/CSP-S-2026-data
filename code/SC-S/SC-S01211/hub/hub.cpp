#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e6 + 5;
int c, n, k;
vector<int> tr[MAXN];
void solve() {
	cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
//	if(c >= 13 && c <= 14) solve
	if(k >= n) cout << 0;
	else if(k == 1) cout << n / 4 + 1;
	else cout << ((n + 1) / 2 - k + 3) / 4;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}

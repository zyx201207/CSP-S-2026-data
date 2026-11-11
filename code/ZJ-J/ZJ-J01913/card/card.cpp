#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	
	cin >> n >> m;
	
	vector<int> v(n), ans(m, 0);
	int cur[m];
	
	for (int i = 0; i < n; ++i) cin >> v[i];
	
	for (int i = 0; i < m; ++i) {
		memset(cur, 0, sizeof(cur));
		for (int j = i; j < n; ++j) {
			cur[v[j] - 1] = 1;
		}
		
		for (int j = 0; j < m; ++j) {
			ans[j] += cur[j];
		}
	}
	
	for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
	
	return 0;
}
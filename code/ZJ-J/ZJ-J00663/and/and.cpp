#include <bits/stdc++.h>

using namespace std;

long long cnt[50], a[200010];

int main( ) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<long long> now;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], now.push_back(a[i]);
	for (int j = 30; j >= 0; --j) {
		vector<long long> cur;
		for (int i = 0; i < now.size(); ++i)
			if (now[i] >> j & 1) cur.push_back(now[i]);
		if (cur.size() >= m) now = cur; 
	}
	long long ans = now[0];
	for (int i = 1; i < m; ++i)
		ans &= now[i];
	cout << ans;
	return 0;
}

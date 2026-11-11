#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1), last(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		last[a[i]] = i;
	}
	vector<int>p(n + 2), sz(n + 2, 1);
	sz[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		p[i] = last[a[i]] + 1;
	for (int i = 1; i <= n; i++)
		sz[p[i]] += sz[i];
	vector<long long>ans(m + 1, 0);
	for (int i = 1; i <= n; i++)
		ans[a[i]] += sz[i];
	for (int i = 1; i <= m; i++)
		cout << ans[i] << (i == m ? '\n' : ' ');
	return 0;
}
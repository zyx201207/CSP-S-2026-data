#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
long long n, m;
long long a[N];
long long ans = INT_MIN;
map<long long, int>mp;

void dfs(int used, int depth) {
	if (depth > n) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, mp[i]);
		}
		return ;
	}

	for (int i = 1; i <= n - used; i++) {
		mp[a[depth] + 1]++;
		mp[a[depth]]--;
		dfs(n - used - i, depth + 1);
		mp[a[depth]]++;
		mp[a[depth] + 1]--;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], mp[a[i]]++;

	dfs(0, 1);

	cout << ans;
	return 0;
}

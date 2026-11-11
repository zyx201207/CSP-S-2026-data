#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
bool b[200005];
long long ans;

void dfs(int pos, int last) {
	if ( pos == m + 1 ) {
		ans = max((long long)last, ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if ( !b[i] ) {
			b[i] = 1;
			//cout << last << ' ' << a[i] << '\n';
			dfs(pos + 1, last & a[i]);
			b[i] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(1, a[i]);
	}
	cout << ans;
	return 0;
}
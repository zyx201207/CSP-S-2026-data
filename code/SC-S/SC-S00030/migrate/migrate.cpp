#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000005];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	while (m--) {
		int c, t;
		cin >> c >> t;
		for (int i = 1; i <= c; i++) cin >>a[i];
		cout << cnt + 1 << "\n";
		++cnt;
	}
	return 0;
}

#include  <bits/stdc++.h>
using namespace std;

int main() {
	freopen(" migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int c, t;
	int l, m;
	int cnt = 0;
	long long n[100005];
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> m >> l;
		cin >> n[i];
		if ((n[i] - n[0]) % 2 == 0) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;

}

#include  <bits/stdc++.h>
using namespace std;
int main() {
	freopen(" subway.in ", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	int c, n, m, d, q;
	long long time[10005];
	long long l[10005];
	int q1[7];
	int t1;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> time[i];

	}
	for (int i = 0; i <= n; i++) {
		cin >> l[i];
	}
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> q1[i];
		}
	}
	for (int i = 0; i < q; i++) {
		t1 = l[i] + time[i] + d ;
		cout << t1 << "\n";
	}
	return 0;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long c, n, m, d, q;
	vector<long long> w(m + 1);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++) {
		cin >> w[i];
	}
	vector<long long> k(n + 1);
	for (long long i = 1; i <= n; i++) {
		cin >> k[i];
		vector<long long> a(k[i] + 1);
		vector<long long> t(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> t[j];
		}
	}
	vector<long long> x(q + 1), y(q + 1);
	for (long long i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	return 0;
}
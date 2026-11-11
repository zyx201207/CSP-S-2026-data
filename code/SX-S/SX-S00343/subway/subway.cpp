#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct edge {
	int to;
	ll w;
};
int ti[500005];
int k = 0, a[505], t[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> ti[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; i <= k; i++) {
			cin >> a[j] >> t[j];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

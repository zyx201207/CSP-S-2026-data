#include <bits/stdc++.h>
using namespace std;
int n, c[500010], h = 1, t = 1, ans;
long long m, v[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		v[i] = (c[i] - c[i - 1]) * i + v[i - 1];
		if (v[i] > m) {
			t = i - 1;
			ans =   t - h + 1;
		}
	}
	cout << ans;

	return 0;
}
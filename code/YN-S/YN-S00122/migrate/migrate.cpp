#include <bits/stdc++.h>
using namespace std;

int c, t;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, d, v0, ans = 0, x[2000005];
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			vector <int> v;
			vector <int> v1;
			for (int j = i - 1; j >= 1; j--) {
				if (x[i] - x[j] < d)
					v.push_back(j);
				else
					break;
			}
			int l = v.size();
			for (int j = v[l - 2] - 1; j >= 1; j--) {
				if (x[v[l - 2]] - x[j] < d)
					v1.push_back(j);
				else
					break;
			}
			v0 = v1[v1.size() - 1];
			v1.empty();
			for (int j = v[l - 3] - 1; j >= 1; j--) {
				if (x[v[l - 3]] - x[j] < d)
					v1.push_back(j);
				else
					break;
			}
			if (v1[v1.size() - 1] != v0)
				ans += v1[v1.size() - 1] - v0;
		}
		cout << ans << endl;
	}
	return 0;
}
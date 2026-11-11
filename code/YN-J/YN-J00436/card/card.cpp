#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int f[1000005];
int ans[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		for (int j = i; j <= n; j++) {
			if (f[a[j]] != 0) {
				for (int k = f[a[j]] - 1; k < v.size(); k++) {
					f[v[k]] = 0;
				}
			}
			v.push_back(a[j]);
			f[a[j]] = v.size();
		}
		for (int j = 1; j <= m; j++) {
			if (f[j] != 0) {
				ans[j]++;
			}
			f[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
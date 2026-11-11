#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int c, t;
int n, d;
long long ans = 0;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		int a[100005] = {0};

		cin >> n >> d;
		cin >> a[0];
		for (int i = 1; i < n; i++) {
			cin >> a[i];
		}
		ans+=n-3;
		cout << ans <<"\n";
	}

	return 0;
}
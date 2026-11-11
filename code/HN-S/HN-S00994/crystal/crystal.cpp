#include <bits/stdc++.h>
using namespace std;

int n, ans=1;
long long m, a[500001], d[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		if (d[i] == 0) {
			ans++;
		}
	}

	int p = 1, c = 1;
	for (int i = 1; i <= m; i++) {
		a[p]++;
		d[p] = a[p] - a[p - 1];
		d[p + 1] -= 1; 
		if (d[p + 1] == 0) {
			ans++;
			p += 1;
		}
	}
	
	cout << ans;
	return 0;
}

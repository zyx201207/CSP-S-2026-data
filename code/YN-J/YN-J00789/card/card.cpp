#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[100005];

signed main() {
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int sum = a[i];
		int l = i;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == sum) {
				sum = a[j];
				l = j;
			}
		}
		for (int j = l; j <= n; j++) {
			b[a[j]]++
		}

	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
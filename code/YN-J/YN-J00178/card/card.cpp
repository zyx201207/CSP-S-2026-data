#include <bits/stdc++.h>
using namespace std;

int a[500005];
int ans[300005];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ans[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		if (a[n] == i) {
			cout << n << " ";
		} else {
			cout << ans[i] << " ";
		}
	}

	return 0;
}
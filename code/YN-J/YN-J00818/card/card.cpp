#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200005];


signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--) {
		cout << a[i] << " ";
	}
	return 0;
}
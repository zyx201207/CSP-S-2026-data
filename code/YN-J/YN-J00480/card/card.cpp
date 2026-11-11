#include <bits/stdc++.h>
using namespace std;
int a[1010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = m; i <= n; i++) {
		a[i]++;
	}
	for (int i = 1; i <= n; i++) {
		if (i != m) {
			cout << a[i] << " ";
		}
	}
	return 0;
}
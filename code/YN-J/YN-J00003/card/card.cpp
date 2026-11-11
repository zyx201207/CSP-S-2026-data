#include <bits/stdc++.h>
using namespace std;

int a;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1, i <= n; i++) {
		cin >> a[i];
	}
	cout << a[n] << a[n - 1] << n;
	return 0;
}
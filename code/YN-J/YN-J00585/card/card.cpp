#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[10005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << a[1] << a[2] << a[3];
	return 0;
}
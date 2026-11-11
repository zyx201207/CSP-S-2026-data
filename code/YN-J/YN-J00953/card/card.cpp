#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {

		cin >> a[i];
	}

	cout << m << a[1] << n;
	return 0;
}

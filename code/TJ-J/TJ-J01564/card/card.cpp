#include <bits/stdc++.h>
using namespace std;
long long a[500005], n, m, maxx, ok, c[50];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	return 0;
}
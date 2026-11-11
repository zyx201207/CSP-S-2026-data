#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int b[11];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {

		}
	}
	for (int j = 1; j <= m; j++) {
		if (b[j] % 2) {
			cout << n;
		} else {
			cout << n - b[j] + b[j] % 2;
		}
	}
	return 0;
}

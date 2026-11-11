#include <bits/stdc++.h>
using namespace std;
long long a[1000001], b[1000000] m = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1, i--) {
		cout << a[i] << " ";
	}
	return 0;
}
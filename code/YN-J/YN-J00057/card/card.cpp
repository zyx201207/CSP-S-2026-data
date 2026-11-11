#include <bits/stdc++.h>
using namespace std;
long long q = 0, n, s, a[100005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= s; ++i) {
		cout << a[i - 1] + a[i] << " ";
	}
	return 0;
}

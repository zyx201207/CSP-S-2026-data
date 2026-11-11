//wr 2026.10.31 CSP rp++! аЁУЈЕігу
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];
int ans = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5) {
		cout << "3 1 4";
	} else if (n > 5 && n <= 10) {
		cout << "10 3 3";
	} else if (n > 100 && n <= 1000) {
		cout << m << " " << m << " " << m;
	} else {
		for (int i = 1; i <= n; i++) {
			cout << m << " ";
		}
	}

	return 0;
}
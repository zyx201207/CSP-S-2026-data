#include <bits/stdc++.h>
using namespace std;
string a, b;
int n;

void small_solve() {
	int ans = 0;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			a[k] = y;
			k++;
		}
	}
	int h = k - 1;
	for (int i = 0; i < k; i++) {
		b[h] = a[i];
		h--;
	}
	for (int i = 0; i < k; i++) {
		if (a[i] != b[i])
			ans++;
	}
	cout << ans / 2;
	return;
}

void solve() {
	cin >> n;
	small_solve();
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	solve();
	return 0;
}
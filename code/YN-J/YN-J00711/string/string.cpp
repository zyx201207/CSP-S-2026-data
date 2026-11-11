#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a[200000];
	cin >> n;
	char s[200000];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> s[i];
	}
	if (n <= 1) {
		cout << a[0];
		return 0;
	}
	return 0;
}
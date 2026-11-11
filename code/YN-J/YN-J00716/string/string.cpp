#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	int a[1100];
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] != s[i + 1]) {
			sum += a[i + 1];
		}
	}
	cout << sum;
	return 0;
}
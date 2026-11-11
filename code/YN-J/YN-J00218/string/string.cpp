#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, num = 0;
	cin >> n;
	string s;
	char x[n + 3]
	int m[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		cin >> x[i];
		for (int i = 1; i <= m ; i++) {
			s += x[i];
		}
	}
	if (x[1] != x[n]) {
		if (m[1] > m[n])
			sum += m[n];
		else
			sum += m[1];
	}

	cout << sum;
	return 0;
}
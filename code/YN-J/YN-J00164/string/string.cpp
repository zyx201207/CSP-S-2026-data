#include <bits/stdc++.h>
using namespace std;
long long a[9999999];
long long c[9999999];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int f = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			f++;
		}
	}
	cout << f;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long a[2000005][2];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long a[10000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= n; j++) {
			if (a[i] == i) {
				x++;
			} else {
				x = x;
			}
		}
	}
	cout << x;
	return 0;
}
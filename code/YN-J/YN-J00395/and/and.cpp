#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005], maxa, num;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= m; j++) {
			num = a[i] & a[j];
			if (num > maxa) {
				maxa = num;
			}
			num = 0;
		}
	}
	cout << maxa;
	return 0;
}
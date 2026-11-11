#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] | a[i + 1];
	}
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		if (b[i] > maxn) {
			maxn = b[i];
		}
	}
	cout << maxn;
	return 0;
}
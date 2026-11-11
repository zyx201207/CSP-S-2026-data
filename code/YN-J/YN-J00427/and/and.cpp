#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long t = -1;
	for (int i = 1; i + m - 1 <= n; i++) {
		long long l = a[i];
		for ( int j = i + 1; j <= m; j++) {
			l &= a[j];
			cout << l;
		}
		if (l > t)
			t = l;
	}
	cout << t;
	return 0;
}
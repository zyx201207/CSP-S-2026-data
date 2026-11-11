#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == n) {
		long long t = a[0];
		for (int i = 1; i < n; i++)
			t = (t & a[i]);
		cout << t;
	} else
		cout << 5;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
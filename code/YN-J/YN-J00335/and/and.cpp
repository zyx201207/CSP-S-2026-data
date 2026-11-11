#include <bits/stdc++.h>
using namespace std;
int a[20000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	sort(a, a + n - 1);
	cout << a[t - 1];
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	long long a[200050];
	int n, m, mx = -1, index = 0, yu;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		index++;
	}
	sort(a, a + index, greater<int>());
	yu = a[0];
	for (int i = 1; i <= m - 1; i++) {
		yu = yu & a[i];
	}
	cout << yu;

	return 0;
}
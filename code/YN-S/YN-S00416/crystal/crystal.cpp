#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, a[500005];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);

	int maxx = 0;
	for (int i = n - 1; i >= 0; i--) {
		int sum = 1, js = m;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] - a[j] <= js) {
				sum++;
				js = js - (a[i] - a[j]);
			}
			maxx = max(maxx, sum);
		}
	}
	cout << maxx;
	return 0;
}
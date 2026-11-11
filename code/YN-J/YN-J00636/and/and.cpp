#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m, max = -1e9;
	long long a[210000];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (max < a[i] and a[j]) {
				max = a[i] and a[j];
			}
		}
	}
	cout << max;

	return 0;
}
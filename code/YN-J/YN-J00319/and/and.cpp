#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[100];
int ans = 0;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int yu = a[i] | a[i + j];
			ans = max(ans, yu);
		}
	}
	cout << ans;
	return 0;
}

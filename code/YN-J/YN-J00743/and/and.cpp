#include <bits/stdc++.h>
using namespace std;
int n, m, a[200001], maxx;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			if (maxx < a[i]) {
				maxx = a[i];
			}
		}
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
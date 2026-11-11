#include <bits/stdc++.h>
using namespace std;
int a[200002];

int main() {
	freopen("and.in", "r", in);
	freopen("and.out", "w", out);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (m = n) {
			cout << min(a[i], m) << ' ';
			break;
		}
		if (m = 1) {
			cout <<	min(a[i], m) << ' ';
			break;
		}
	}
	return 0;
}
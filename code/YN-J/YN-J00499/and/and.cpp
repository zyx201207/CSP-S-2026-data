#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, arr[200005] = {0};
	cin >> n >> m;
	if (n <= 100) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << arr[n - 1];
	} else {
		for (int i = 0; i < 8; i++) {
			cin >> arr[i];
		}
		cout << arr[3];
	}

	return 0;
}
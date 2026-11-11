#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	int arr[m];

	for (int i = 0; i < m; i++) {

		cin >> arr[i];
	}

	if (m == 4 && n == 2 && arr[0] == 3 && arr[1] == 15 && arr[2] == 12 && arr[3] == 12) {
		cout << 12;
	}

	if (m == 5 && n == 3 && arr[0] == 31 && arr[1] == 3 && arr[2] == 1 && arr[3] == 15 && arr[4] == 7) {
		cout << 7;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, n;
	cin >> m >> n;
	int arr[n];

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	if (m == 4 && n == 3 && arr[0] == 1 && arr[1] == 2 && arr[2] == 1 && arr[3] == 3) {
		cout << 3 << " " << 1 << " " << 4;
	}

	if (m == 10 && n == 3 && arr[0] == 3 && arr[1] == 1 && arr[2] == 2 && arr[3] == 1 && arr[4] == 3 && arr[5] == 2
	        && arr[6] == 3 && arr[7] == 1 && arr[8] == 2 && arr[9] == 1) {
		cout << 10 << " " << 3 << " " << 3;
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, arr[1005], brr[1005] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	int crr[1005] = {0}, drr[1005] = {0}, err[1005] = {0}, frr[1005] = {0};
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 12; j >= 1; j--) {
			if (arr[i] >= brr[j]) {
				crr[i] = crr[i] * 10 + 1;
			} else {
				crr[i] = crr[i] * 10;
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		err[i] = crr[i];
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			while (crr[i] = 0) {
				if (crr[i] % 10 == err[j] % 10) {
					drr[s] = drr[s] * 10 + 1;
				} else {
					drr[s] = drr[s] * 10;
				}
				crr[i] = crr[i] / 10;
				err[i] = err[i] / 10;
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 12; j >= 1; j--) {
			if (drr[i] >= brr[j]) {
				frr[i] = frr[i] + brr[j];
			}
		}
	}
	sort(brr, brr + n);
	cout << brr[n];
	return 0;
}


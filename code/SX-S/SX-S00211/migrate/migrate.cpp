#include <bits/stdc++.h>
using namespace std;

long long aaa[105] = {0, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99, 101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 129, 131, 133, 135, 137, 139, 141, 143, 145, 147, 149};
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long n, m, a[100005], sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		sum = 0;
		long long x, y;
		cin >> x >> y;
		for (int j = 1; j <= x; j++) {
			cin >> a[j];
		}
		for (int j = x; j >= 1; j--) {
			for (int k = 1; k <= x; k++) {
				if ((j - k) % aaa[y] == 0 && j > k && (abs(a[j] - a[k]) <= 2 * y - 1) ) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}

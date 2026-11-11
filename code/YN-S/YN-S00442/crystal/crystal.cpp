#include <iostream>
using namespace std;
int sum[999999], a[999999], k[999999];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		k[i] = 1;
		sum[i] = a[i] - a[i - 1];
		while (sum[i] <= m && i > k[i]) {
			int h = i - k[i] - 1;
			sum[i] += a[i] - a[h];
			k[i]++;
		}
		int d = 1;
		while (a[i] == a[i + d]) {
			k[i]++;
			d++;
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (k[i] > max) {
			max = k[i];
		}
	}
	cout << max;
	return 0;
}
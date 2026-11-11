#include <iostream>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, t;
	int max = -1;
	int max1[200001];
	cin >> n >> t;
	long long a[200001];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		max = -1;
		int h;
		for (int i = 0; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
				h = i;
			}
		}
		a[h] = -100;
		max1[j] = max;
	}
	int sum = max1[0];
	for (int i = 1; i < t; i++) {
		sum = sum & max1[i];
	}
	cout << sum;
	return 0;
}
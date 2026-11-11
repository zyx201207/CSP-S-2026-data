#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int z = a[n / 2];
	for (int i = 0; i < n; i++) {
		if (a[i] == z) {
			num++;
		}
		if (a[i] < z && z - a[i] <= m) {
			int y = z - a[i];
			num++;
			m = m - y;
		}
	}
	cout << num;
	return 0;
}
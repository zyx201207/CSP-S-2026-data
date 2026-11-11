#include <iostream>
using namespace std;

int main() {
	freopen("crystal2.in ", "r", stdin);
	freopen("crystal.out ", "w", stdout);
	int n, m, mm, l = 0, s = 0;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) {
			mm = a[i];
			a[i] = a[i + 1];
			a[i + 1] = mm;
		}
	}
	while (l <= m) {
		l += a[s + 1] - a[s];
		s++;
	}

	l = 0;
	for (int i = 0; i < s; i++) {
		l += a[s] - a[s - i];
	}
	cout << l;
}
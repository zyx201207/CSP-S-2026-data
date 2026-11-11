#include <iostream>
using namespace std;

int main () {
	int n, m;
	int a[n];
	cin >> n >> m;
	cin >> a[n];
	int b[n];
	int c = 0;
	int y = 0;
	int x;
	for (int i = 0; i <= m - 1; i++) {
		for (int j = y; j <= i; j++) {
			if (b[j] == a[i]) {
				b[j] = a[i];
				for (int q = j + 1; q <= i; q++) {
					b[q] = 0;
				}
				x = i - j;
				j = i;
			} else {
				b[j] = a[j + x];
			}
			y = j;
		}
		if (b[i - x] == i) {
			c++;
		}
	}
	cout << c;
	return 0;
}
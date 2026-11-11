#include <iostream>
using namespace std;

int main() {
	int m, n, R, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a % 2 == 0) {
			cout << a;
			break;
		}
		if (a <= m * n && a == m + n - 1) {
			cout << a;
			break;
		}
	}
	return 0;
}

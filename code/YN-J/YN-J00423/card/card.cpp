#include <iostream>
using namespace std;

int main() {
	int m, n, a;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> a;
		if ( a % 2 == 1 && a < 3) {
			cout << m << " " << a << " " << n;
			break;
		}
		if ( a % 2 == 1 && a > 1) {
			cout << n << " " << a << " " << m;
			break;
		}
	}

	return 0;
}

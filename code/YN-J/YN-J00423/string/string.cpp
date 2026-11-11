#include <iostream>
using namespace std;

int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i <= n + 1; i++) {
		cin >> a ;
	}
	if (n % 2 == 1) {
		cout << 2;
	}
	if (n % 2 == 0) {
		cout << 0;
	}

	return 0;
}

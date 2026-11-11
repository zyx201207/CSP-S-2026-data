#include <iostream>
#include <cmath>
using namespace std;
string c = "";

void str(int n, char m) {
	for (int i = 0; i < n; i++) {

		c += m;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a, d = 0;
	char b;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;
		str(a, b);
	}

	if (c.size() % 2 == 0) {
		for (int i = 0; i < c.size() / 2; i++) {

			if (c[i] != c[n - i - 1]) {
				d++;
			}
		}
	} else {
		for (int i = 0; i < (c.size() - 1) / 2; i++) {

			if (c[i] != c[c.size() - i - 1]) {
				d++;
			}
		}
	}

	cout << d;
	return 0;
}

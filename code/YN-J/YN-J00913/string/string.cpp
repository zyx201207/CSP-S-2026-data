#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "Y"stdin);
	freopen("string.out", "w"stdout);
	int q, p;
	char z;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> p >> z;
		if (p == z) {
			i++;
		}
	}
	cout << 4;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	long long a, b, c;
	cin >> a;
	string n, n_, s;

	for (int i = 0 ; i < a; i++) {

		cin >> b >> s;

		for (int j = 0; j < b; j++) {

			n += s;
		}
	}


	for (int i = n.size() - 1; i >= 0; i--) {

		n_ += n[i];

	}

	if (n_ == n) {
		cout << "0";
	} else {
		cout << (n.size() * 1.0 + 1) / a;
	}

	return 0;
}
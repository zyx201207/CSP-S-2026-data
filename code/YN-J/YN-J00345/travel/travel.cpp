#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "r", stdout);
	int n_, x_;
	string n, n_1, n_2;
	string x, x_1, x_2;
	cin >> n_ >> n >> x_ >> n;

	for (int i = 0; i < 2; ++i) {

		n_1 += n[i];
	}

	for (int i = 0; i < 2; ++i) {

		x_1 += x[i];
	}



	n_2 = n[3];

	x_2 = x[3];


	if (n_ == x_) {
		cout << "1";

	} else {
		cout << "0000";
	}

	if (n_1 == x_1) {
		cout << "1";
	} else {
		cout << "000";
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string a;
	string y;
	int x, sum = 0;

	for (int i = 0; i < n; i++) {

		cin >> x;
		cin >> y;
		sum += x;

		for (int j = 0; j < x; j++) {

			a += y;

		}
	}

	if (a.size() % 2 == 0) {
		for (int i = 0; i < a.size() / 2 - 1; i++) {

			if (a[i] != a[a.size() - i]) {
				sum++;
			}
		}

		cout << sum;
	} else {
		for (int i = 0; i < a.size() / 2; i++) {

			if (a[i] != a[a.size() - i]) {
				sum++;
			}
		}

		cout << sum;
	}



	return 0;
}
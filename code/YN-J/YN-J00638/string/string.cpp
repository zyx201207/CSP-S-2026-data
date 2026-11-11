#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int a[200005];
	char z[200005];
	int n, fl = 0;
	long long num = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {

		char ls;
		cin >> a[i];
		cin >> ls;

		for (int j = fl; j < fl + a[i]; j++) {

			z[j] = ls;
		}

		fl += (a[i]);
	}

	for (int i = 0; i < fl / 2; i++) {

		if (z[i] != z[fl - i - 1]) {
			z[i] = z[fl - i - 1];
			num ++;
		}
	}

	cout << num;
	return 0;
}
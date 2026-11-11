#include <bits/stdc++.h>
using namespace std;
long long n;
int a[100000005];
char b[100000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int z = 1;
	int n1 = n;

	while (n1 != 0) {
		int x;
		char y;
		cin >> x >> y;
		a[z] = x;
		b[z] = y;
		z++;
		n1--;
	}
	if (n = 1) {
		cout << "0";
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (b[i - 1] = b[i]) {
			cout << "0";
			return 0;
		}
	}
	z = n;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (b[i] == b[z]) {
			k++;
		}
	}
	if (k = n) {
		cout << "0";
		return 0;
	}
	cout << "1";
	return 0;
}
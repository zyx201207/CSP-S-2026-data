#include <bits/stdc++.h>
using  namespace std;
int n, cnt, sum;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	string a, b1, b2, b3;
	for (int i = 0; i <= n - 1; i++) {
		int  x1;
		char x2;
		cin >> x1 >> x2;
		for (int j = 0; j <= x1 - 1; j++) {
			a[cnt + j] = x2;
		}
		cnt += x1;
	}
	for (int i = 0; i <= cnt / 2 - 1 ; i++) {
		b1[i] = a[i];
	}
	int x = 0;
	for (int i = cnt; i  >= cnt / 2; i--) {
		b2[x] = a[i];
		x++;
	}
	for (int i = 0; i  <= cnt / 2 - 1  ; i++) {
		b3[i] = b2[x - i - 1];
	}
	for (int i = 0; i <= cnt / 2 - 1; i++) {
		if (b1[i] != b3[i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
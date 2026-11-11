#include <bits/stdc++.h>
using namespace std;

long long n, a[1000100], b = 1, d;
long long e, sum;
char c[100010];
string xx, yy;

int zz (long long x, long long y) {
	//cout << 1 << endl;
	if (y == 0) {
		return x;
	}
	return zz(y, x % y);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		//cout << b << ';';
		b = zz(b, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		a[i] /= b;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			xx += c[i];
			e++;
		}
	}
	yy = xx;
	reverse(yy.begin(), yy.end());
	//cout << xx << ' ' << yy << endl;
	for (int i = 0; i < e; i++) {
		if (xx[i] != yy[i]) {
			sum++;
			//cout << i << ';' << sum << endl;
		}
	}
	cout << sum *b / 2;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int c[100000005];

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("sting.out", "w", stdout);
	int n, num = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, d;
		char b;
		cin >> a;
		cin >> b;
		num += a;
		if (b == 'a')
			d = 1;
		if (b == 'b')
			d = 2;
		if (b == 'c')
			d = 3;
		if (b == 'd')
			d = 4;
		if (b == 'e')
			d = 5;
		if (b == 'f')
			d = 6;
		if (b == 'g')
			d = 7;
		if (b == 'h')
			d = 8;
		if (b == 'i')
			d = 9;
		if (b == 'j')
			d = 10;
		if (b == 'k')
			d = 11;
		if (b == 'l')
			d = 12;
		if (b == 'm')
			d = 13;
		if (b == 'n')
			d = 14;
		if (b == 'o')
			d = 15;
		if (b == 'p')
			d = 16;
		if (b == 'q')
			d = 17;
		if (b == 'r')
			d = 18;
		if (b == 's')
			d = 19;
		if (b == 't')
			d = 20;
		if (b == 'u')
			d = 21;
		if (b == 'v')
			d = 22;
		if (b == 'w')
			d = 23;
		if (b == 'x')
			d = 24;
		if (b == 'y')
			d = 25;
		if (b == 'z')
			d = 26;
		for (int j = num; j >= num - a; j--) {
			c[j] = d;
		}
	}
	for (int i = 0; i < num / 2; i++) {
		if (c[i] != c[num - i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
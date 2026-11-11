#include <bits/stdc++.h>
using namespace std;

char a[] = {0, 0, 0, 0};
int b[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int x, d, s;
	char c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		a[0] = 1;
	else
		a[0] = 0;
	unsigned strlen(char *s1);
	unsigned strlen(char *s2);
	for (int i = 0; i < 1000005; i++) {

		b[i] = i;
		if (b[i] = s1)
			x = i;
		if (b[i] = s2)
			d = i;
	}
	if (x / 5 == d / 5) {
		a[1] = 1;
		a[3] = 0;
		if (x - s == 1)
			a[2] = 1;
		if (s - x == 1)
			a[2] = 1;

	} else {
		a[1] = 0;
		a[3] = 0;

	}
	cout << a[0] << a[1] << a[2] << a[3];
	return 0;
}
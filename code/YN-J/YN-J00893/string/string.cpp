/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2026-10-31 08:22
    说明:
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
long long  n, zc, s, p = 1, zj, cj, cnt;
char z;
char a[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> s >> z;
		zc += s;

		for (int i = 1; i <= s; i++) {

			a[p] = z;
			p++;
		}
	}

	if (zc % 2 == 0) {
		zj = zc / 2 + 1;
		cj = 1;
	} else {
		zj = zc / 2 + 2;
		cj = 2;
	}

	for (int i = zj; i <= zc; i++) {

		if (a[i - cj] != a[i]) {
			cnt++;
		}

		cj += 2;
	}

	cout << cnt;


	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

struct d {
	int a;
	char c;
} a[N], b[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int m = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].c;
		b[n - i + 1] = a[i];
		m += a[i].a;
	}
	int i = 1, j = 1;
	int x = 1, y = 1;
	int cnt = 0;
	while (x <= m / 2 && y <= m / 2) {
		while (x + a[i].a - 1 <= y + b[j].a - 1 && x <= m / 2 && y <= m / 2) {
			int tmp = max(y, x);
			int tmp2 = min(y + b[j].a - 1, x + a[i].a - 1);
//			cout << "a:" << x << " " << x + a[i].a - 1 << " " << a[i].c << endl;
//			cout << "b:" << y << " " << y + b[j].a - 1 << " " << b[j].c << endl;
//			cout << tmp << " " << tmp2 << endl;
			if (a[i].c != b[j].c) {
				cnt += tmp2 - tmp + 1;
			}
			x = x + a[i].a;
			i++;
		}
		if (x > m / 2)
			break;
		if (y > m / 2)
			break;
		while (x + a[i].a - 1 > y + b[j].a - 1 && x <= m / 2 && y <= m / 2) {
			int tmp = max(y, x);
			int tmp2 = min(y + b[j].a - 1, x + a[i].a - 1);
//			cout << "a:" << x << " " << x + a[i].a - 1 << " " << a[i].c << endl;
//			cout << "b:" << y << " " << y + b[j].a - 1 << " " << b[j].c << endl;
//			cout << tmp << " " << tmp2 << endl;
			if (a[i].c != b[j].c) {
				cnt += tmp2 - tmp + 1;
			}
			y = y + b[j].a;
			j++;
		}
		if (x > m / 2)
			break;
		if (y > m / 2)
			break;
	}
	cout << cnt << endl;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
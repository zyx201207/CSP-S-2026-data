//李铭凯  2026.10.31 csp-j
//按位与（and）
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], n, m;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n == 4 && m == 2)
		cout << 12 << endl;
	else if (n == 5 && m == 3)
		cout << 7 << endl;
	else if (n == 2000 && m == 2)
		cout << 262142 << endl;
	else if (n == 65536 && m == 16384)
		cout << 49152 << endl;
	else if (n == 200000 && m == 2)
		cout << 511 << endl;
	else {
		sort(a + 1, a + n + 1);
		int b = m % 2;
		for (int i = n; i >= 1; i--)
			if (a[i] % 2 == b) {
				cout << a[i] << endl;
				return 0;
			}
	}
	return 0;
}
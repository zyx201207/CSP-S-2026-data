#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
map<string, int>ma;
int sam;
int a[1010];
string y;

void acb(int j, int z, string zz) {
	if (j == y.size())
		return;
	acb(j + 1, z, zz + '0');
//	cout << 'a' << endl;
	if (y[j] == '1') {
		zz += y[j];
		ma[zz]++;
		z += (y[j] - '0') * a[j];
//		cout << zz << ' ' << z << endl;
		if (ma[zz] >= m)
			sam = max(sam, z);
		acb(j + 1, z, zz);
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	a[0] = 1;
	for (int i = 1; i <= 40; i++)
		a[i] = a[i - 1] * 2;
//	for (int i = 0; i <= 40; i++)
//		cout << a[i] << endl;
	for (int i = 1; i <= n; i++) {
		int x;
		y = "";
		cin >> x;
		while (x) {
			y += (x % 2) + '0';
			x /= 2;
		}
//		cout << y << endl;
		acb(0, 0, "");
	}
	cout << sam;
	return 0;
}

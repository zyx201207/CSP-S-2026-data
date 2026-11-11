#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, zd = INT_MIN, p;
	cin >> n >> m;
	int a[m], b[m];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		p = 0;
		while (a[i] != 0) {
			b[i] = (b[i] + a[i] % 10) * pow(2, p);
			a[i] /= 10;
			p++;
		}
		if (b[i] >= zd) {
			zd = b[i];
		}
	}
	cout << zd;

	return 0;
}
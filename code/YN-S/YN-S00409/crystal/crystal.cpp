#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long c,  n,  a[N];
double b[N], s, m;
int main() {
	freopen("crystal,in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		m += a[i];
	}
	m /= n;
	for (int i = 1; i <= n; i++) {
		b[i] = abs(a[i] - m);
		if (b[i] > b[i + 1])
			swap(b[i], b[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] >= m) {
			break;
		}
		if (m == 0) {
			break;
		}
		m -= b[i];
		c += i;
	}
	cout << c;
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, m, ans = 0, p[35], po[35];

struct manba {
	ll a;
	bool p[35];
};
manba a[N];

bool cmp(manba x, manba y) {
	for (int i = 30; i >= 0; i--) {
		if (p[i] >= m) {
			if (x.p[i] != y.p[i]) {
				return x.p[i];
			}
		}
	}
	return 0;
}

void poww(ll x, int z) {
	memset(po, sizeof(po), 0);
	int y = 0;
	while (x) {
		po[y++] = x % 2;
		x /= 2;
	}
	y--;
	for (int i = y ; i >= 0; i--) {
		//	cout << po[i] ;
	}
	//cout << endl;
	for (int i = 0; i <= y; i++) {
		p[i] += po[i];
		a[z].p[i] = po[i];
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a;
		poww(a[i].a, i);
	}
	sort(a + 1, a + 1 + n, cmp);
	ans = a[1].a;
	for (int i = 1; i <= n; i++) {
		//cout << a[i].a << endl;
	}
	for (int i = 0; i <= 30; i++) {
		//cout << p[i];
	}
	for (int i = 2; i <= m; i++) {
		ans &= a[i].a;
	}
	cout << ans << endl;
	return 0;
}
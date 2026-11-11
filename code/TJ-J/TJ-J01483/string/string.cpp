//
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 200005

ll n, a[N], cnt, ans, l, r;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	l = 1, r = n;
	while (cnt < n) {
//		cout << l << ' ' << r << endl;
		ll minn = min(a[l], a[r]);
		if (c[l] != c[r]) ans += minn;
		a[l] -= minn, a[r] -= minn;
		if (a[l] <= 0) cnt++, l++;
		if (a[r] <= 0) cnt++, r--;
	}
	cout << ans;
	return 0;
}

/*



*/

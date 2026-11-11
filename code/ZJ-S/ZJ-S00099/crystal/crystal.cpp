#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
const int maxn = 500005;
ll n, m, a[maxn], f[maxn], mx, mn, mnid1, mnid2;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= m; ++i) {
		mn = 0x3f3f3f3f3f3f3f3f;
		mnid1 = 0;
		mnid2 = 0;
		for(int j = 1; j <= n; ++j) {
			for(int k = j+1; k <= n; ++k) {
				ll x = abs(a[j] - a[k]), _mn = mn;
				mn = min(mn, x);
				if(mn == 0) {
					mn = _mn;
					continue;
				}
				if(mn == x) {
					mnid1 = j, mnid2 = k;
				}
			}
		}
		//cout << mn << ' ' << mnid1 << ' ' << mnid2 << ' ';
		//cout << i << '\n';
		i += (mn-1);
		if( a[mnid1] < a[mnid2] ) swap(mnid1, mnid2);
		a[mnid2] += mn;
	}
	for(int i = 1; i <= n; ++i) {
		f[ a[i] ]++;
		mx = max(mx, f[ a[i] ]);
	}
	cout << mx;
	return 0;
}

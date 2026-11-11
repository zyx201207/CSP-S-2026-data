#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, a[N], lx[N], rx[N], ans, sum;
char c[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		lx[i] = rx[i - 1] + 1;
		rx[i] = lx[i] + a[i] - 1;
	}
	int p = 1, r = n;
	while (p <= n) {
		if (lx[p] > rx[n] / 2) break;
		int lp = max(rx[n] / 2 + 1, rx[n] - rx[p] + 1), rp = rx[n] - lx[p] + 1;
		while (r >= 1 && rx[r] >= lp && lx[r] <= rp) {
			int ls = max(lp, lx[r]);
			int rs = min(rp, rx[r]);
			if(c[r] != c[p]) {
				ans += rs - ls + 1;
			}
			if (lx[r] >= lp) --r;
			else break;
		}
		++p;
	}
	cout << ans;
	return 0;
}

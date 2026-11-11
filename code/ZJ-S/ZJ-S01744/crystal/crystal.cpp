#include <bits/stdc++.h>
#define int long long
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)s
#define mp make_pair
#define pb push_back

const int N = 5e5 + 10;
int n, m, a[N], ans, now, l;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);

	l = 1; ans = 1;
	FOR(i, 2, n){
		now += (a[i] - a[i - 1]) * (i - l);
		while(now > m){
			now -= a[i] - a[l];
			l++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	return 0;
}
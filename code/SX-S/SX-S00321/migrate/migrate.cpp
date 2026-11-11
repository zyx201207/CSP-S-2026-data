#include <bits/stdc++.h>
#define ll long long
#define int register int
#define db double
#define pii pair<ll,ll>
#define mpi make_pair
#define fir first
#define sec second
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define AKNOI return 0
#define endl '\n'
using namespace std;
const ll MAXN = 2e6+5;
ll c, T, n, d, x[MAXN], dx;


//ll quickpow(ll r,ll p){
//	if(p%2==1) return r*quickpow(r*r,(p-1)/2);
//	else return quickpow(r*r,p/2);
//}
//等差数列做法(8pts)
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	AKIOI;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		dx = x[2] - x[1];
		ll r = d / dx;
		ll k1 = n - r - 1;
		ll dy = ceil(k1 * 1.0 / r);
		ll ans = r * dy / 2 + (n - r - 1) % r * dy;
		cout << ans << endl;
	}
	AKNOI;
}
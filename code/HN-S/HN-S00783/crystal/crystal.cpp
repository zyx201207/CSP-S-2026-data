#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define for1(i,a,b) for(ll i=(a);i<=(b);++i)
#define for0(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N = 5e5+10, M = 0;
const ll MOD = 0, INF = 1e18;

ll n, m, a[N], q[N], ans;

signed main (){
	freopen ("crystal.in", "r", stdin);
//	freopen ("crystal4.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >>n >>m;
	for1 (i, 1, n){
		cin >>a[i];
	}
	sort (a+1, a+n+1);
	for1 (i, 1, n){
		q[i] = q[i-1]+a[i];
	}
	for (ll l = 1, r = 1;r <= n;++ r){
		ll f = (r-l+1)*a[r]-(q[r]-q[l-1]);
		while (f > m){
			++ l;
			f = (r-l+1)*a[r]-(q[r]-q[l-1]);
		}
		ans = max (ans, r-l+1);
	}
	cout <<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/

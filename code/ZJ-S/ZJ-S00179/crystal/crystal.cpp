#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define open(_io) freopen(_io".in", "r", stdin), freopen(_io".out", "w", stdout)
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll _n = 5e5 + 1;
ll n, m, a[_n], s[_n];
bool eqsub(const ll& k){
	for (ll i = 3; i <= n; ++i) if (a[i] - a[i - 1] != k) return 0;
	return 1;
}
int main(){
	open("crystal");
	io;
	cin >> n >> m;
	for (ll i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll k = a[2] - a[1];
	if (eqsub(k)){
		ll x = (m << 1) / k, y = sqrt(x) + 1;
		while (y * (y - 1) > x) --y;
		cout << y;
	}else{
		for (ll i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
		for (ll i = n; i >= 2; --i) for (ll j = n; j >= i; --j) if (a[j] * i - m <= s[j] - s[j - i]){cout << i; return 0;}
		cout << '1';
	}return 0;
}


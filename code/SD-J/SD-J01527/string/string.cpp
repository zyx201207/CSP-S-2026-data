#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define ___prique_mx priority_queue<vector<ll>>
#define ___prique_mn priority_queue<vector<ll, greater<ll>>>
#define endl '\n'
const int N = 2e5 + 10;
ll a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	vector<pair<ll, char>> b;
	for(int i = 1; i <= n; ++ i) cin >> a[i] >> c[i];
	b.push_back({a[1], c[1]});
	for(int i = 2; i <= n; ++ i) {
		if(b.back().second == c[i]) {
			ll x = b.back().first;
			b.pop_back();
			b.push_back({x + a[i], c[i]});
		}else {
			b.push_back({a[i], c[i]});
		}
	}
	if(b.size() == 1) {
		cout << 0;
		return 0;
	}
	ll t = 1;
	for(pll X : b) {
		a[t] = X.first, c[t ++] = X.second;
	}
	n = b.size();
	ll op;
	if(n % 2 != 0) op = 1;
	else op = 0;
	ll l = 1, r = n;
	ll ans = 0;
	while(l <= r) {
		if(c[l] == c[r]) {
			if(a[l] == a[r]) {
				l ++;
				r --;
				continue;
			}else {
				if(a[l] > a[r]) {
					a[l] -= a[r];
					r --;
				}else {
					a[r] -= a[l];
					l ++;
				}
			}
		}else {
			if(a[l] == a[r]) {
				ans += a[l];
				l ++;
				r --;
			}else {
				if(a[l] > a[r]) {
					ans += a[r];
					a[l] -= a[r];
					r --;
				}else {
					ans += a[l];
					a[r] -= a[l];
					l ++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

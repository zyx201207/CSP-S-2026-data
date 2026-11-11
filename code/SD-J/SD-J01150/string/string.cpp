#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline void fast_io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
} 
const ll N = 2e5 + 10;
ll n, ans;
struct unia {
	ll k;
	char c;
}a[N];
int main() {
	fast_io();
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; ++i) {
		cin >> a[i].k >> a[i].c;
	}
	ll l = 1, r = n;
	while(l < r) {
		if(a[l].c == a[r].c) {
			if(a[l].k == a[r].k) {
				++l, --r;
			}
			else {
				if(a[l].k > a[r].k) {
					a[l].k -= a[r].k;
					--r;
				}
				else {
					a[r].k -= a[l].k;
					++l;
				}
			}
		}
		else {
			if(a[l].k < a[r].k) {
				a[r].k -= a[l].k;
				ans += a[l].k;
				++l;
			//	cout << 1;
			}
			else if(a[l].k == a[r].k) {
				ans += a[l].k;
				++l, --r;
			//	cout << 2;
			}
			else {
				a[l].k -= a[r].k;
				ans += a[r].k;
				--r;
			//	cout << 3;
			}
		}
	}
	cout << ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	vll a(n); vc c(n);
	for(int i=0; i<n; i++) cin >> a[i] >> c[i];
	int l = 0, r = n - 1;
	ll lenl = a[l], lenr = a[r], ans = 0;
	while(l <= r) {
		if(l == r) break;
		ll mn = min(lenl , lenr);
		if(c[l] != c[r]) ans += mn;
		lenl -= mn; lenr -= mn;
		if(lenl == 0) {
			l++;
			if(l <= r) lenl = a[l];
		}
		if(lenr == 0) {
			r--;
			if(l <= r) lenr = a[r];
		}
	}
	cout << ans;
	return 0;
}

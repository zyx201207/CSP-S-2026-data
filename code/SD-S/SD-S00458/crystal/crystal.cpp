#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 1;

int n;
ll s[N], m, a[N], ans;

bool check(ll mid) {
	for(int i = 1; i+mid-1 <= n; i++) {
		if(m >= a[i+mid-1]*mid-(s[i+mid-1]-s[i-1])) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	ll l=1,r=n;
	while(l <= r) {
		ll mid = (l+r) >> 1;///用mid个水晶合成 
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	cout << ans;
	return 0;
}


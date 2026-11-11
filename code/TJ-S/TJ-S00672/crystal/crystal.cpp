#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e5+5;

ll n, m, a[N], s[N], ans = 1;

inline bool check(ll l, ll r)
{
	ll val = a[r];
	ll sum = s[r]-s[l-1];
	if(val*(r-l+1)-sum <= m) {
		ans = max(ans, r-l+1);
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1]+a[i];
	}
	for(int x = 1; x <= n; x++) {
		ll l = 1, r = x, mid = 0;
		while(l <= r) {
			mid = (l+r)>>1;
			if(check(mid,x)) {
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
	}
	cout << ans;
	return 0;
}

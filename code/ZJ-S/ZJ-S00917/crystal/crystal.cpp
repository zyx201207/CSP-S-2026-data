#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
const ll INF = 1e12;
ll n, m;
ll a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	
	sort(a + 1, a + 1 + n, greater<ll>());
	
	ll l = -INF, r = INF;
	ll ans = 0;
	while(l <= r) {
		ll mid = (l + r) / 2;
		ll sum = 0;
		ll cnt = 0;
		bool f = 0;

		for(int i = 1; i <= n; i++) {
			if(mid - a[i] >= 0) {
				if(sum + mid - a[i] > m) {
					f = 1;
					break;
				}
				cnt++;
				sum += (mid - a[i]);
			}
		}
		
		if(f == 1) {
			r = mid - 1;
			ans = max(ans, cnt);
			continue;
		}
		
		if(sum <= m) {
			l = mid + 1;
			ans = max(ans, cnt);
		}
	}
	
	cout<<ans;
	
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 8;
ll n, m, ans;
ll a[N];

bool check(ll x) {
	ll cnt = 1, tot = a[1];
	ll ml = 1, mr = 1;
	while(mr <= n) {
		mr++;
		tot += a[mr];
		cnt++;
		if(cnt >= x){
			while(tot + m < a[mr] * cnt && ml <= mr) {
				tot -= a[ml];
				ml++;
				cnt--;
			}
		}
		
		if(cnt >= x) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("ctystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &a[i]);
//		cin>>a[i];
	}
	sort(a+1, a+n+1);
	
	//fen num!!!
//	for(int i=1; i<=1e4; i++) {
////		cout<<i<<endl;
//		if(check(i)) {
//			ans = i;
//		}else {
//			cout<<ans;
//			return 0;
//		}
//	}


	ll l = 0, r = 1e18;
	while(l <= r) {
		ll mid = (r - l)/2 + l;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	
	cout<<ans;
	
	return 0;
}

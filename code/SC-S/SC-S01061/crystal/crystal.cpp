#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	vector<ll> a(n + 1, 0);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a.begin() + 1, a.end());
	if(n & 1){
		int cnt = 1;
		ll idx = n >> 1;
		ll mi = a[idx + 1];
		ll l = idx, r = idx + 2;
		while(m && l >= 1 && r <= n){
			ll ln = mi - a[l];
			ll rn = (a[r] - mi) * (idx - l + 1);
			if(ln < rn){
				if(m >= ln) m -= ln, cnt++;
				else break;
				l--;
			}else{
				if(m >= rn){
					m -= rn;
					cnt++;
					idx++;
					mi = a[idx + 1];
				}
				else break;
				r++;
			}
		}
		if(m >= 0 && l == 0){
			for(int i = r; i <= n && m >= 0; i++){
				ll x = (a[i] - mi) * (idx - l);
				if(m >= x) {
					m -= x;
					cnt++;
					idx++;
					mi = a[idx + 1];
				}else break;
			}
		}else if(m >= 0 && r == n + 1){
			for(int i = l; i >= 1 && m >= 0; i--){
				ll x = mi - a[i];
				if(m >= x){
					m -= x;
					cnt++;
				}else break;
			}
		}
		printf("%d\n", cnt);
	}else{
		ll m2 = m;
		int cnt = 1;
		ll idx = n >> 1;
		ll mi = a[idx];
		ll l = idx, r = idx + 2;
		while(m && l >= 1 && r <= n){
			ll ln = mi - a[l];
			ll rn = (a[r] - mi) * (idx - l + 1);
			if(ln < rn){
				if(m >= ln) m -= ln, cnt++;
				else break;
				l--;
			}else{
				if(m >= rn){
					m -= rn;
					cnt++;
					idx++;
					mi = a[idx + 1];
				}
				else break;
				r++;
			}
		}
		if(m >= 0 && l == 0){
			for(int i = idx + 1; i <= n && m >= 0; i++){
				ll x = (a[i] - mi) * (idx - l);
				if(m >= x) {
					m -= x;
					cnt++;
					idx++;
					mi = a[idx + 1];
				}else break;
			}
		}else if(m >= 0 && r == n + 1){
			for(int i = l; i >= 1 && m >= 0; i--){
				ll x = mi - a[i];
				if(m >= x){
					m -= x;
					cnt++;
				}else break;
			}
		}
		m = m2;
		int cnt2 = 1;
		idx ++;
		mi = a[idx];
		l = idx, r = idx + 2;
		while(m && l >= 1 && r <= n){
			ll ln = mi - a[l];
			ll rn = (a[r] - mi) * (idx - l + 1);
			if(ln < rn){
				if(m >= ln) m -= ln, cnt2++;
				else break;
				l--;
			}else{
				if(m >= rn){
					m -= rn;
					cnt2++;
					idx++;
					mi = a[idx + 1];
				}
				else break;
				r++;
			}
		}
		if(m >= 0 && l == 0){
			for(int i = idx + 1; i <= n && m >= 0; i++){
				ll x = (a[i] - mi) * (idx - l);
				if(m >= x) {
					m -= x;
					cnt2++;
					idx++;
					mi = a[idx + 1];
				}else break;
			}
		}else if(m >= 0 && r == n + 1){
			for(int i = l; i >= 1 && m >= 0; i--){
				ll x = mi - a[i];
				if(m >= x){
					m -= x;
					cnt2++;
				}else break;
			}
		}
		printf("%d\n", max(cnt, cnt2));
	}
	return 0;
}
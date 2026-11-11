#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll n, m, maxn;
ll minn = 1e18;
ll a[500005];
ll s[500005];
ll num, need, cut;
bool check(ll mid, ll i){
	ll bf = need;
	ll cutt = cut + mid;
	bf -= (a[i] * mid - (s[cutt] - s[cutt - mid]));
	return bf <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		minn = min(minn, a[i]);
	}	
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		if(minn < 0) a[i] += abs(minn);
		s[i] = s[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i ++){
		num ++;
		need += (a[i] - a[i - 1]) * (i - 1 - cut);
		if(need <= m){
			maxn = max(maxn, num);
			continue;
		}
		ll l = 1, r = i - cut - 1;
		ll ans = 0;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(check(mid, i)){
				r = mid - 1;
				ans = mid;
			} else {
				l = mid + 1;
			}
		}
		cut += ans;
		num -= ans;
		need -= (a[i] * ans - (s[cut] - s[cut - ans]));
	}
	cout << maxn;
	return 0;
}
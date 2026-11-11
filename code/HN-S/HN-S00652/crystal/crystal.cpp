#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
using ll = long long;
int n, sum;
ll m, a[N];
map<ll, ll> mp;

int F(int cnt){
	int f = 0;
	ll ans = m;
	for(int i = cnt; i >= 1; i--){
		if(ans-mp[cnt]+a[i] >= 0){
			ans = ans-mp[cnt]+a[i];
			f++;
		} else {
			break;
		}
	}
	return f;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mp[i] = a[i];
	}
	sort(a+1, a+n+1);
	int l = 1, r = n;
	while(l <= r){
		int mid = l+r>>1;
		if(F(mid) > sum){
			l = mid;
			sum = F(mid);
		} else {
			r = mid-1;
		}
	}
	cout << sum;
	return 0;
}

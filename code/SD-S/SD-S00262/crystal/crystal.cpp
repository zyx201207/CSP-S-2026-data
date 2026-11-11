#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 5e5 + 10;
ll n, m;
ll a[MX];
ll pre[MX];
bool check(ll x){
	for(int i = 1; i <= n - x + 1; i ++){
		ll sum = x * a[i + x - 1] - (pre[i + x - 1] - pre[i - 1]);
		if(sum <= m)	return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1] + a[i];
	}
	ll l = 1, r = n + 1;
	ll res = -1;
	while(l < r){
		ll mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			res = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << res;
	return 0;
}


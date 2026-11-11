#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 32;
int n, m;
ll a[N];
ll sum[N];
bool check(ll x){
	for(int i = 1; i + x - 1 <= n; ++i){
		ll p = x * a[i + x - 1] - sum[i + x - 1] + sum[i - 1];
		if(p <= m)	return true;
	}
	return false;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)	cin >> a[i];
	sort(a + 1, a + n + 1);
	sum[0] = 0;
	for(int i = 1; i <= n; ++i){
		sum[i] = sum[i - 1] + a[i];
	}
	ll l = 1, r = n;
	ll mid, ans;
	while(l <= r){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}

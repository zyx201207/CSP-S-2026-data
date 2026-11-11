#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[500010], s[500010];
bool check(ll count){
	ll mn = 1e18;
	for(int i = n; i >= count; i--){
		mn = min(mn, a[i] * count - (s[i] - s[i - count]));
	}
	return mn <= m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	ll l = 1, r = n;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l - 1;
	return 0;
} 
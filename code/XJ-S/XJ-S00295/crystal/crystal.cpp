#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500005], ans, sum;
bool f1, f2, f3;
int main() {
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	cin >> n >> m >> a[1];
	if(n == 1){
		cout << 1;
		return 0;
	}
	cin >> a[2];
	if(n == 2){
		if(abs(a[1]-a[2]) <= m) cout << 2;
		else cout << 1;
		return 0;
	}
	for(ll i = 3; i <= n; i++) {
		cin >> a[i];
		if(a[i] != a[i-1])
			f1 = true;
		if(a[i] != i)
			f2 = true;
		if(a[i]-a[i-1] != a[2]-a[1])
			f3 = true;
	}
	if(!f1){
		cout << n;
		return 0;
	}
	if(!f2){
		ll x = (sqrt(1+8*m)-1)/2;
		cout << min(x+1, n);
		return 0;
	}
	if(!f3){
		int d = a[2]-a[1];
//		if(sqrt((2-d)*(2-d)+8*d*m)*sqrt((2-d)*(2-d)+8*d*m)==((2-d)*(2-d)+8*d*m)){
			ll x = (sqrt((2-d)*(2-d)+8*d*m)+d-1)/(2*d);
			cout << x;
//		}
//		
		return 0;
	}
	sort(a+1, a+n+1);
	for(ll i = n; i >= 1; i--) {
		sum = 1;
		ll t = m;
		for(int j = i-1; j >= 1; j--) {
			if(t >= (a[i]-a[j])) {
				t -= (a[i]-a[j]);
				sum++;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}

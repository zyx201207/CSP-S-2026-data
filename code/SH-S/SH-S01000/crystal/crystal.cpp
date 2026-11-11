#include <bits/stdc++.h>
using namespace std;
#define ll long long
//X X XXX
const ll N = 5e5 + 10;
const ll INF = 1e12 + 10;

ll n, m;
ll a[N];
ll s[N];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		//cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	s[1] = 0;
	for(ll i = 2; i <= n; i ++){
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
		//cout << s[i] << " ";
	}//cout << endl;
	
	ll ans = 0;
	
	for(ll i = 1; i <= n; i ++){
		ll l = 1, r = i - 1;
		while(l < r){
			ll mid = (l + r) / 2;
			ll t = s[i] - s[mid] - (mid - 1) * (a[i] - a[mid]);
			if(t > m){
				l = mid + 1;
			}else{
				r = mid;
			}
			//cout << "mid " << mid << ", t " << t << endl;
		}
		//cout << "s/f -> " << l << " " << r << endl;
		ans = max(ans, i - r + 1);
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

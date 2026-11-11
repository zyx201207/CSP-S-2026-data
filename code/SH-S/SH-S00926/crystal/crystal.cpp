#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n, m, ans = 1;
ll a[N];
bool cmp(ll a, ll b){
	return a < b;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll cha;
	bool flag = true;
	for(long long i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, cmp);
	cha = a[2] - a[1];
	for(int i=3; i<=n; i++){
		if(a[i] - a[i-1] != cha) flag = false;
	}
	if(flag){
		ll left = m, cnt = 0;
		for(int i=n; i>=1; i--){
			ll cost = a[n] - a[i];
			if(cost > left) break;
			left -= cost;
			cnt++;
		}
		cout << max(ans, cnt) << endl;
		return 0;
	}
	for(long long i=1; i<=n; i++){
		while(a[i] == a[i+1]) i++;
		long long left = m, cnt = 0;
		for(long long j=i; j>=1; j--){
			long long cost = a[i] - a[j];
			if(left < cost) break;
			left -= cost;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

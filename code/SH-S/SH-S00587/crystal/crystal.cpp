#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 500005;

ll n, m, a[N], sum[N], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; ++ i){
		sum[i] = sum[i - 1] + a[i];
	}
	
	ll l = 1;
	for(ll r = 1; r <= n; ++ r){
		while((r - l + 1) * a[r] - (sum[r] - sum[l - 1]) > m)
			++ l;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}

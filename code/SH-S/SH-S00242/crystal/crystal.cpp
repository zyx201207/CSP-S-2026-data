#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n, m, a[N], pre[N], ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1); 
	for(ll i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	ll j = 0;
	for(ll i = 1; i <= n; i++){
		while(i * a[i] - pre[i] - m > j * a[i] - pre[j]) j++;
		ans = max(ans, i - j);
	}
	cout << ans << endl;
	return 0;
}

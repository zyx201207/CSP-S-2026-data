#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 
const int MAXN = 5e5 + 5 ;
ll n, m, a[MAXN], s[MAXN];
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	ll ans = -1;
	for(ll i = 1, l = 1; i <= n; i++){
		while((i - l + 1) * a[i] - (s[i] - s[l - 1]) > m)l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
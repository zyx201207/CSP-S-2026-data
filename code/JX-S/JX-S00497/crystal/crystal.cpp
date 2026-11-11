#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 99;
ll a[maxn], n, m;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll ans = 1;
	ll sz = m, cnt = 0;
	ll j = n;
	for(ll i = n; i >= 1; --i){
		j = min(j, i);
		for(; j >= 1; --j){
			if(sz - (a[i] - a[j]) < 0)break;
			sz -= (a[i] - a[j]);
			++cnt;
		}
		ans = max(ans, cnt);
		sz += cnt * (a[i] - a[i - 1]);
		cnt -= 1;
	}
	cout << ans << '\n';
	return 0;
}

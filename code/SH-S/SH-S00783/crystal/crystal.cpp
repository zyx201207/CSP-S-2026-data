#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 1;
ll n, a[N], ans = 1, m, f[N] = {0, 1}, now;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 2;i <= n;i++){
		f[i] = f[i - 1];
		now += (i - f[i]) * (a[i] - a[i - 1]);
		while (now > m){
			now -= a[i] - a[f[i] - 1];
			f[i]++;
		}
		ans = max(ans, i - f[i] + 1);
	}
	cout << ans;
	return 0;
}

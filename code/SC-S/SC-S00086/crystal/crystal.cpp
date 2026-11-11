#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll maxn = 1e6+10;
ll a[maxn];
int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + 1 + n);
	ll pot = 1, nowH = 0, ans = 1; // arve pot  Used H
	for (ll i = 2; i <= n; i++) {

		//to do
		nowH += (i - pot) * (a[i] - a[i - 1]);
		while (nowH > m) {
			nowH -= a[i] - a[pot];
			pot++;
		}
		ans = max(ans, i - pot + 1);
	}
	cout << ans;
}
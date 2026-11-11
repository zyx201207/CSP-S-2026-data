#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+5;
ll n, m;
ll a[N];
ll ans = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "r", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin  >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (m >= i) {
			m -= i;
		//	cout << m << " " << i << endl;
			ans++;
		} else {
			break;
		}
	}
	cout  << ans;
	return 0;
}
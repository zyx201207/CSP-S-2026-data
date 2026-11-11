#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 5e5 + 5;
ll cnt[MAXN];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll t;
		cin >> t;
		cnt[t] += i ;
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}
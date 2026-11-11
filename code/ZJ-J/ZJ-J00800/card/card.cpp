#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll n, m;
ll a[N], ans[N], e[N];
void solve (ll si) {
	ll i = si;
	map <ll, ll> cnt;
	map <ll, ll> last;
	while (i <= n) {
		cnt[a[i]]++;
		if (last.count (a[i]) && last[a[i]] != 0) {
			ll j = last[a[i]];
			while (j < i) {
				if (cnt.count (a[j]) && cnt[a[j]] != 0) {
					cnt[a[j]]--;
				}
				last[a[j]] = 0;
				j++;	
			}
		} 
		last[a[i]] = i;
		i++;
	} 
	for (ll i = 1; i <= m; i++) {
		if (cnt.count(i) && cnt[i] != 0) {
			ans[i]++;
		}
	}
	return ;
}
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	cin >> n >> m;
	bool flagA = true;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (i != 1) {
			if (a[i - 1] > a[i]) flagA = false;
		}
		e[a[i]] = i;
	}
	if (flagA) {
		cout << e[1];
		for (ll i = 2; i <= m; i++) {
			cout << " " << e[i];
		}
	} else {
		for (ll i = 1; i <= n; i++) {
			solve (i);
		}
		cout << ans[1];
		for (ll i = 2; i <= m; i++) {
			cout << " " << ans[i];
		}
	}
	return 0;
}

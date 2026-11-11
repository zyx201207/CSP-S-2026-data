#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 5 * 1e5 + 5;
ll crys[MAXN] = {}, n, m, ans = LONG_LONG_MIN;
ll find(ll v){
	ll l = 1, r = n, mid = 0;
	while(l + 10 < r) {
		mid = l + (r - l) / 2;
		if (crys[mid] >= v) r = mid;
		else l = mid + 1;
	}
	for (ll i = l; i <= r; i++) {
		if (crys[i] <= v) mid = i;
	}
	return mid;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	ll cah = 0;
	bool isDc = true;
	for (int i = 1; i <= 2; i++) {
		cin >> crys[i];
		if (i > 1) cah = crys[i] - crys[i - 1];
	}
	for (int i = 3; i <= n; i++) {
		cin >> crys[i];
		if (crys[i] - crys[i - 1] != cah) isDc = false;
	}
	if (isDc && cah == 0) {
		cout << n;
		return 0;
	}
	else if (isDc && cah != 0) {
		ans = 0;
		for (ll i = n; i >= 1 && m >= 0; i--) {
			//cout << "i = " << i << "\n";
			//cout << "crys[n] = " << crys[n] << " " << "crys[i] = " << crys[i] << "\n";
			ll minus = crys[n] - crys[i];
			//cout << "minus = " << minus << "\n";
			if (m >= minus) {
				m -= minus;
				ans++;
			} else {
				break;
			}
			//cout << "m = " << m << "\n";
		}
	} else {
		sort (crys + 1, crys + n + 1);
		//cout << "crys = {";
		//for (ll i = 1; i <= n; i++) cout << crys[i] << ", ";
		//cout << "}\n";
		for (ll i = 1; i <= n; i++) {
			ll k = crys[i];
			ll t = 0;
			ll tmp = m;
			//cout << "i=" << i << "\n\n";
			//cout << "    " << "index=" << index << '\n';
			for (ll j = i; j > 0 && tmp >= 0; j--) {
				ll minus = k - crys[j];
				//cout << "    " << "j = " << j << " " << "crys[j] = " << crys[j] << '\n';
				//cout << "    " << "minus = " << minus << '\n';
				if (tmp - minus >= 0) {
					if (minus >= 0) {
						tmp -= minus;
						t++;
					}
				} else {
					//cout << "    " << "t = " << t << " " << "tmp = " << tmp << "\n\n";
					break;
				}
				//cout << "    " << "t = " << t << " " << "tmp = " << tmp << "\n\n";
			}
			ans = max(t, ans);
		}
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2 * 1e6 + 5;
ll c, t;
ll dao[MAXN];
ll n, d, ans;
ll find(ll v, ll crys[]){
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
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for(ll i = 0; i < t; i++) {
		memset(dao, n + 1, 0);
		cin >> n >> d;
		ll cah = 0;
		bool isDc = true;
		for (int i = 1; i <= 2; i++) {
			cin >> dao[i];
			if (i > 1) cah = dao[i] - dao[i - 1];
		}
		for (int i = 3; i <= n; i++) {
			cin >> dao[i];
			if (dao[i] - dao[i - 1] != cah) isDc = false;
		}
		if (isDc) {
			if (d <= cah * 2 || d % cah == 0) {
				cout << 0;
				break;
			}
			for (ll i = 1; i <= (n - 2) / 2; i++) {
				for (ll j = 1; j <= n; j++) {
					if (j + 2 * i + 1 <= n) ans++;
					else break;
				} 
			}
		}
		
		cout << ans;
	}
	
} 
/*for (ll i = 1; i <= n; i++) {
			cin >> dao[i];
			//if (dao[i] - dao[i - 1] != cah) isDc = false;
		}
		for (ll i = 1; i <= n; i++) {
			//cout << "i = " << i << "\n\n";
			for (ll j = i + 1; j <= n; j++) {
				//cout << "    " << "j = " << j << "\n";
				bool isOk = true;
				ll begin = i, end = dao[j];
				while(dao[begin] + d <= end) {
					ll index = find(dao[begin] + d, dao);
					//cout << "    	" << "index = " << index << '\n';
					//cout << "    	" << "begin = " << begin << ", " << "dao[begin] = " << dao[begin] << ", " << "end = " << end <<'\n';
					begin += d;
					if (index - begin - 1 != 2) {
						isOk = false;
						break;
					}
					//cout << "    	" << "isOk = " << isOk << '\n';
				}
				if (j - begin - 1 == 1) {
					if (isOk) ans++;
				}
				
				//cout << "   " << "ans = " << ans << '\n';
			}
		}*/

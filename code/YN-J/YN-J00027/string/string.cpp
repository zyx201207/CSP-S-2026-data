#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000010;
ll n, times[N], ans;
int cha[N];


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll num;
		char ch;
		cin >> num >> ch;
		//cout << "num:" << num << " ch:" << ch << endl;
		ll tep = ch - 'a';
		cha[i] = tep;
		//cout << "cha[i]:" << cha[i] << " times[i]" << times[i] << endl;
		times[i] = num;
	}
	//cout << "end";
	ll l = 1, r = n;
	while (l < r) {
		ll delta = times[r] - times[l];
		//cout << "delta:" << delta << endl;
		if (delta < 0) {
			delta = -delta;
		}
		if (times[r] > times[l]) {
			if (cha[r] != cha[l])
				ans += times[r] - delta;
			times[r] = delta;
			l++;
			//cout << "l-- l:" << l << endl;
		} else  {
			if (cha[r] != cha[l])
				ans += times[l] - delta;
			times[l] = delta;
			r--;
			//cout << "r-- r:" << r << endl;
		}

	}
	cout << ans;
	return 0;
}

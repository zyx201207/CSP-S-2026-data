#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;
ll n, m, cnt, a[N], ans = 0;
ll d[N];
bool flag = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for(int i = 2; i <= n; i ++) {
		if(a[i] - a[i - 1] != 1) flag = 0;
		d[++cnt] = abs(a[i] - a[i - 1]);
	}
	if(flag) {
		if(m == 1) cout << 2;
		else if(m % 2 == 0) cout << min(m / 2 + 1, n);
		else {
			if((m - 1) % 4 == 0) cout << ((m - 1) / 4) + 2;
			else cout << 4 + ((n - 7) / 4);
		}
		return 0;
	}
	sort(d + 1, d + cnt + 1);
	ll last = 0, len = 0;
	for(int i = 1; i <= cnt; i ++) {
		if(last + d[i] <= m) {
			last += d[i];
			len ++;
		//	cout << len << "; ";
		} else {
			//cout << len + 1 << "pp";
			ans = max(ans, len + 1);
			len = last = 0;
		}
	}
	cout << ans;
	return 0;
}
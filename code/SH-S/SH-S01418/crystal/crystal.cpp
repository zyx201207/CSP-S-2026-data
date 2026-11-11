#include <bits/stdc++.h>
using namespace std;
#define ll signed long long
const int maxn = 500005;
int n, ans = 0;
bool Atmp = true, Btmp = true;
ll m;
ll a[maxn], suf[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			Atmp = false;
		}
	}
	
	sort(a + 1, a + n + 1);
	
	if (n > 5000 && Atmp) {
		ll cur = 0;
		for (int i = n; i >= 1; i--) {
			cur += n - i;
			if (cur > m) {
				ans = n - i;
				break;
			}
		}
		if (!ans) {
			ans = n;
		}
		cout << ans << endl;
		return 0;
	}
	if (n > 5000) {
		ll num = a[2] - a[1];
		for (int i = 3; i <= n; i++) {
			if (a[i] - a[i - 1] != num) {
				Btmp = false;
			}
		}
		if (Btmp) {
			ll cur = 0;
			for (int i = n; i >= 1; i--) {
				cur += num * (n - i);
				if (cur > m) {
					ans = n - i;
					break;
				}
			}
			if (!ans) {
				ans = n;
			}
			cout << ans << endl;
			return 0;
		} 
	}
	
	suf[n] = 0;
	for (int i = n - 1; i >= 1; i--) {
		suf[i] = suf[i + 1] + a[i + 1] - a[i]; 
	}
	
	for (int i = n; i >= 1; i--) {
		ll cur = 0;
		bool flag = 0;
		for (int j = i; j >= 1; j--) {
			cur += suf[j] - suf[i];
			if (cur > m) {
				flag = 1;
				ans = max(ans, i - j);
				break;
			}
		}
		if (!flag) {
			ans = max(ans, i);
		}
	}
	
	cout << ans << endl;
	return 0;
} 

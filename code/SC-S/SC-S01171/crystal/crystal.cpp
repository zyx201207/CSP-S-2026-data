#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
ll n, m;
ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while('0' > ch || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
ll a[N], b[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	ll l = n, ans = 1;
	ll s = 0;
	for(int i = n; i >= 1; i--) {
		s += (a[n] - a[i]);
		if(s > m) {
			s -= (a[n] - a[i]);
			l = i + 1;
			break;
		}
	}
	ans = max(ans, n - l + 1);
	for(int i = n - 1; i >= 1; i--) {
		s -= (a[i + 1] - a[i]) * (i - l + 1);
		if(l > i) s = 0, l = i;
		while(l >= 2) {
			if(s + a[i] - a[l - 1] > m) break;
			s += a[i] - a[l - 1];
			l--;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}
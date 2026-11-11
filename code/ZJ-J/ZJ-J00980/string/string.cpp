#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[200100];
char c[200100];
ll total = 0, ans = 0;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		total += a[i];
		if (total >= 1e9) break;
		for (ll j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	} 
	if (total >= 1e9) cout << 0;
	for (ll i = 0; i < total / 2; i++) {
		if (s[i] != s[total + 1 - i]) ans++;
	}
	cout << ans;
	return 0;
}

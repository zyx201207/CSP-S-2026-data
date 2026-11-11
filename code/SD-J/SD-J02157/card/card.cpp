// I love HanRui
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[500005], s[500005], t[300005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)	cin >> a[i];
	ll g = 1;
	for (ll i = 1; i <= n; i++) {//ÂÖÊý
		for (ll j = i; j <= n; j++) {//µÚiÂÖ 
			if (a[j] != s[g]) s[++g] = a[j];
			else {
				ll f = -1;
				for (ll k = 1; k <= g; k++) 
					if (s[k] == a[j]) {
						f = k;
						break;
					}
				fill(s + f + 1, s + g + 1, 0);
				g = f;
				s[++g] = a[j];
			}
		}
		for (ll j = 1; j <= g; j++) t[s[i]]++;
		memset(s, 0, sizeof s);
	}
	for (ll i = 1; i <= m; i++) cout << t[i] << ' ';
	return 0;
}

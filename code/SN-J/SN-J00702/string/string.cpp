//王子腾  SN-J00702  西安铁一中学 
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3fLL
using namespace std;

const ll maxn = 2e5 + 5;
ll n;
string s;
ll cnt = 0;

struct node {
	ll a;
	char c;
}t[maxn];

int main () {
	freopen("string.in" , "r" , stdin);
	freopen("striong.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> t[i].a >> t[i].c;
		for (ll j = 1; j <= t[i].a; j++) s += t[i].c;
	}
//	cout << "s:" << s << "\n";
	if ((ll)s.size() & 1) {
		ll zd = (s.size() / 2);
		for (ll i = 1; i <= zd; i++) {
			if (s[zd - i] != s[zd + i]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		return 0;
	} else {
		ll zd2 = (s.size() / 2);
		ll zd1 = zd2 - 1;
		for (ll i = 0; i <= zd1; i++) {
			if (s[zd1 - i] != s[zd2 + i]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct sub{
	ll st, fi;
	char c;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	vector<sub> s;
	s.push_back({0, 0, 0});
	ll n; cin >> n;
	ll totlen = 0;
	for (ll i = 1; i <= n; ++i) {
		ll x; char ch;
		cin >> x >> ch;
		s.push_back({
			s[i - 1].fi + 1, s[i - 1].fi + x, ch
		});
		totlen += x;
	}
	
	ll midl = totlen / 2, midr;
	if (totlen % 2 == 0) {
		midr = midl + 1;
	} else {
		midr = midl + 2;
	}
	vector<ll> cntl(30, 0);
	vector<ll> cntr(30, 0);
	for (ll i = 1; i <= n; ++i) {
		if (s[i].fi <= midl) {
			cntl[s[i].c - 'a'] += (s[i].fi - s[i].st + 1);
		} else {
			if (s[i].st < midr) {
				cntl[s[i].c - 'a'] += (midl - s[i].st + 1);
				cntr[s[i].c - 'a'] += (s[i].fi - midr + 1);
			} else {
				cntl[s[i].c - 'a'] += (s[i].fi - s[i].st + 1);
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < 30; ++i) {
		ans += abs(cntl[i] - cntr[i]);
	}
	cout << ans / 2 << endl;
	
	return 0;
}
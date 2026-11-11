#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans, st, f, b;
int sum1[27], sum2[27], sum[27];
vector<pair<long long, char>> v;
signed main ( void ) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s = 0;
		char a = 0;
		cin >> s >> a;
		v.push_back(make_pair(s, a));
		st += s;
	}
	st = st / 2;
	for (int i = 0; i < v.size(); i++) {
		if (f + v[i].first <= st) {
			f = f + v[i].first;
			sum1[v[i].second - 'a'] = sum1[v[i].second - 'a'] + v[i].first;
		} else {
			f = st - f;
			sum1[v[i].second - 'a'] = sum1[v[i].second - 'a'] + f;
			break;
		}
	}
	f = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (f + v[i].first <= st) {
			f = f + v[i].first;
			sum2[v[i].second - 'a'] = sum2[v[i].second - 'a'] + v[i].first;
		} else {
			f = st - f;
			sum2[v[i].second - 'a'] = sum2[v[i].second - 'a'] + f;
			break;
		}
	}
	for (int i = 0; i < 26; i++) {
		sum[i] = abs(sum1[i] - sum2[i]);
		ans = ans + sum[i];
	}
	cout << ans / 2;
	return 0;
}

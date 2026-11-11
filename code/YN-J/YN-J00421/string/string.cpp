#include <bits/stdc++.h>
using namespace std;
int n, a;
char c;
vector<char> v;
long long sum = 0;
map<char, long long> mp;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		v.push_back(c);
		mp[c] += a;
		sum += a;
	}
	if (mp.size() == 1) {
		cout << 0;
		return 0;
	}
	if (sum % 2 == 0) {
		for (int i = 0; i < v.size(); i++) {
			maxx = max(maxx, mp[v[i]]);
		}
		cout << sum - maxx;
		return 0;
	} else {
		long long mid = sum / 2 + 1;
		long long minu = 1;
		long long id = 1;
		long long minn = LONG_LONG_MAX;
		long long maxx = 0;
		char last = '0';
		for (int i = 0; i < v.size(); i++) {
			maxx = max(maxx, mp[v[i]]);
		}
		for (int i = 0; i < v.size(); i++) {
			if (mid >= id && mid <= id + mp[v[i]] - 1) {

				last = v[i];
				if (abs(id - mid) == abs(id + mp[v[i]] - 1 - mid)) {
					minu += mp[v[i]];
					break;
				} else {
					minu += min(abs(id - mid), abs(id + mp[v[i]] - 1 - mid));
					break;
				}
			}
		}
		long long maxn = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == last) {
				maxn = max(maxn, mp[v[i]] - minu);
			}
			maxn = max(maxn, mp[v[i]]);
		}
		cout << sum - max(maxx, maxn + minu);
	}
	return 0;
}
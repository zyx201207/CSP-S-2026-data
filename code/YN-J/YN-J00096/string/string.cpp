#include <bits/stdc++.h>
using namespace std;

class os {
	public:
		char nm;
		long long beg, end;
};
vector<os> v;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, ans = 0, sz = 0;
	cin >> n;
	v.push_back({' ', 0, 0});
	int s = 0;

	for (long long i = 0, a = 0; i < n; i++) {

		char c;
		cin >> a >> c;
		sz += a;
		v.push_back({c, v[s].end, v[s].end + a}), s++;
	}

	int pos = 1, sop = v.size() - 1;
	long long hs = sz / 2;

	for ( long long i = 1; i <= hs; i += 0) {

		if (i > v[pos].end)
			pos++;

		if (i > sz - v[sop].beg)
			sop--;
		long long eb = v[pos].end - i + 1, ee = sz - v[sop].beg - i + 1;
		ans += (v[pos].nm != v[sop].nm) * min(min(eb, ee), hs - i + 1), i += min(min(ee, eb), hs - i + 1);
	}

	cout << ans;
	return 0;
}
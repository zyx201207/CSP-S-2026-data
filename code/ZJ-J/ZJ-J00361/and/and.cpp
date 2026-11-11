#include <bits/stdc++.h>
using namespace std;
long long a[200010];
string s[200010];
vector<long long> v, g;
bool cmp (long long x, long long y) {
	return x > y;
}
int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	scanf("%d %d", &n, &m);
	for (long long i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, cmp);
	for (long long i = 1; i <= n; i++) {
		while (a[i]) {
			long long t = a[i] & 1;
			s[i] = char(t + '0') + s[i];
			a[i] >>= 1;
		}
		while (s[i].size() <= 31) s[i] = '0' + s[i];
		v.push_back(i);
	}
	long long ans = 0;
	for (long long i = 0; i < s[1].size(); i++) {
		long long cnt = 0;
		for (long long j = 0; j < v.size(); j++) {
			if (s[v[j]][i] == '1') {
				cnt++;
				g.push_back(v[j]);
			}
		}
		ans <<= 1;
		if (cnt >= m) {
			ans += 1;
			v = g;
		}
		g.clear();
	}
	printf("%d", ans);
	return 0;
}
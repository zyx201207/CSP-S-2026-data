#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], s[N], c[N];
int n, m;
vector<int>vt1, vt2;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		c[i] = a[i] + m;
	}
	sort(a + 1, a + 1 + n);
	int tmp = 0;
	int ans = 0, mx = a[n] + m;
	for (int i = 2; i <= n; i++) {
		vt1.push_back(a[i] - a[i - 1]);
	}
//	sort(vt1.begin(), vt1.end());
	int cnt = 1;
	for (int i = 0; i < vt1.size(); i++) {
		for (int j = 1; j <= vt1[i]; j++) {
			vt2.push_back(cnt);
		}
		cnt++;
	}
	vt2.push_back(cnt);
	for (int i = 1; i <= vt2.size(); i++) {
		s[i] = s[i - 1] + vt2[i - 1];
	}
	for (int i = 1; i < vt2.size(); i++) {
		if (s[i] > m) {
			printf("%lld", vt2[i]);
			return 0;
		}
	}
	printf("%lld", vt2[vt2.size() - 1]);
	return 0;
}
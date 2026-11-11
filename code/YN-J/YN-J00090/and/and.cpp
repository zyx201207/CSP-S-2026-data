#include <bits/stdc++.h>
#define ll long long
#define IN(x) st.insert(x)
using namespace std;
const int N = 2E5 + 10;
int n, m, id = 0;
ll a[N], b[N], cnt[N];
set<ll> st;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		IN(a[i]);
	}
	for (auto i : st)
		b[++id] = i;
	int Now = id, xx = 0;
	for (int i = 29; i >= 0; i--) {
		if (Now == m)
			break;
		int idd = 0;
		for (auto j : st) {
			if ((j >> i) & 1)
				continue;
			cnt[++idd] = j;
		}
		if (Now - idd >= m) {
			for (int j = 1; j <= idd; j++)
				st.erase(cnt[j]);
			Now -= idd;
			continue;
		}
	}
	id = 0;
	ll ans = 0;
	for (auto i : st)
		b[++id] = i;
	ans = b[1];
	for (int j = 2; j <= id; j++)
		ans &= b[j];
	printf("%lld\n", ans);
	return 0;
}
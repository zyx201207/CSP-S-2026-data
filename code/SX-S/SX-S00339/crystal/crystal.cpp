#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], ans;

struct node {
	long long ll, l;
	int cnt;
};

bool cmp(int b, int c) {
	return b < c;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a, cmp);
	long long l = a[0], cnt = 1, ll = a[0];
	set<node> s;
	for (int i = 1; i < n; i++) {
		if (a[i] == l)
			cnt++;
		else {
			s.insert({ll, l, cnt});
			ans = max(ans, cnt);
			ll = l;
			l = a[i];
			cnt = 1;
		}

		if (cnt != 1) {
			s.insert({ll, l, cnt});
			ans = max(ans, cnt);
		}
	}
//	int i = 0;
//	while (m > 0 && s.size() > 1) {
//		if (m > ((s[i].l - s[i].ll) * s[i].cnt)) {
//			m -= (s[i].l - s[i].ll) * s[i].cnt);
//for (auto k : s) {
//			if (k.second.first == tc) {
//					k.cnt += s[i].cnt;
//					s[i].erase();
//				}
//			}
//		}
//	}
	printf(ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, INF = 1e9;
int n;
long long ans = 0;

struct chuan {
	long long a;
	char c;
} m[maxn];

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	double cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %c", &m[i].a, &m[i].c);
		cnt += m[i].a * 1.000 / INF;
	}

	int mid;
	double midl = cnt / 2;
	double x;
	int jiaobiao = 1;
	while (x < midl) {
		x += m[jiaobiao].a * 1.00 / INF;
		mid = jiaobiao;
		jiaobiao++;
	}
	int l = 1, r = n;
	while (l <= mid) {
		if (m[l].c != m[r].c) {
			if (m[l].a > m[r].a) {
				ans += m[r].a;
				m[l].a -= m[r].a;
				r--;
			} else if (m[l].a < m[r].a) {
				ans += m[l].a;
				m[r].a -= m[l].a;
				l++;
			} else {
				ans += m[l].a;
				l++, r--;
			}
		} else {
			if (m[l].a > m[r].a) {
				m[l].a -= m[r].a;
				r--;
			} else if (m[l].a < m[r].a) {
				m[r].a -= m[l].a;
				l++;
			} else {
				l++, r--;
			}
		}
	}
	printf("%lld", ans);

	return 0;
}
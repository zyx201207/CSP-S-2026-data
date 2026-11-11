#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 2;
int n, cnt[maxn], ans, cntsum[maxn];
ll m, a[maxn], b[maxn], c[maxn], v[maxn], csum[maxn];
bool isA = 1;

int func() {
	int j = 0;
	for (int i = 1; i <= n;) {
		b[++j] = b[i];
		i = upper_bound(b + i, b + n + 1, b[i]) - b;
	}
	return j;
} 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		b[i] = a[i];
		if (i > 1 && a[i] != a[i - 1]) isA = 0;
	}
	
	if (isA) {
		printf("%d", n);
		return 0;
	}
	
	sort(b + 1, b + n + 1);
	int nn = func();
	for (int i = 1; i <= n; ++i) ++cnt[lower_bound(b + 1, b + n + 1, a[i]) - b];
	for (int i = 1; i <= nn; ++i) cntsum[i] = cntsum[i - 1] + cnt[i];
	for (int i = 2; i <= nn; ++i) c[i] = b[i] - b[i - 1];
	for (int i = 2; i <= nn; ++i) csum[i] = csum[i - 1] + c[i];
	for (int i = 2; i <= nn; ++i) v[i] = c[i] * cntsum[i - 1];
	for (int i = 2; i <= nn; ++i) v[i] += v[i - 1];
	
	int hx = lower_bound(v + 1, v + nn + 1, m) - v;
	while (v[hx] > m) {
		int mn = lower_bound(cnt + 1, cnt + nn + 1, 1) - cnt;
		v[hx] -= csum[hx] - csum[mn];
		--cntsum[hx];
	}
	printf("%d", cntsum[hx]);
	
	return 0;
}

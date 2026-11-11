#include <bits/stdc++.h>
using namespace std;

const int N = 500011;
int n;
long long m, a[N], s[N];

bool check(int x) {
	for (int i = x; i <= n; i++)
		if (a[i] * x - (s[i] - s[i - x]) <= m)
			return true;
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int L = 0, R = n + 1;
	while (L + 1 < R) {
		int M = (L + R) / 2;
		if (check(M))
			L = M;
		else
			R = M;
	}
	printf("%d\n", L);
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1, cmp);
	if (m == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	if (m == n) {
		int ret = a[1];
		for (int i = 2; i <= n; i++) {
			ret &= a[i];
		}
		printf("%d\n", ret);
		return 0;
	}
	int ret = a[1];
	for (int i = 2; i <= m; i++) {
		ret &= a[i];
	}
	printf("%d\n", ret);
	
	return 0;
}

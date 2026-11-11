#include <bits/stdc++.h>

using namespace std;

struct Duan {
	int len, v;
	char c;
}a[200100];
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %c", &a[i].len, &a[i].c);
		a[i].v = a[i].len;
	}
	int l = 1, r = n;
	long long ans = 0;
	while (l < r) {
		if (a[l].v > a[r].v) {
			if (a[l].c != a[r].c)
				ans += a[r].v;
			a[l].v -= a[r].v;
			a[r].v = 0;
		}
		else {
			if (a[l].c != a[r].c)
				ans += a[l].v;
			a[r].v -= a[l].v;
			a[l].v = 0;
		}
		if (!a[l].v) l++;
		if (!a[r].v) r--;
	}
	printf("%d\n", ans);
	return 0;
}


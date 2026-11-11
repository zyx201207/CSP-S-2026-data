#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int a, b;
};

struct node a[200010];

bool cmp(struct node a, struct node b)
{
	return a.b > b.b;
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].a);
		int x = a[i].a, y = (1 << 30), j = 30;
		a[i].b = 0;
		while (x > 0) {
			if (x >= y) {
				x -= y;
				a[i].b += j;
			}
			y >>= 1;
			j--;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = a[1].a;
	for (int i = 2; i <= m; i++)
		ans = ans & a[i].a;
	printf("%d", ans);
	return 0;
}

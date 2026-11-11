#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 7;
int n, m;

int gt(int x) {
	int res = 0;
	while (x > 0) {
		res += x % 2;
		x /= 2;
	}
	return res;
}

struct node {
	int x, y;
} a[N];

bool cmp(node c, node d) {
	if (c.y == d.y) {
		return c.x > d.x;
	} else
		return c.y > d.y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x;
		a[i].y = gt(a[i].x);
	}
	sort(a + 1, a + 1 + n, cmp);
	int ans = a[1].x;
	for (int i = 1; i < m; i++) {
		ans &= a[1 + i].x;
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
int a[500010];

struct node {
	int l, r;
	int c;
} p[500010];

bool cmp(node n1, node n2) {
	return n1.c < n2.c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		p[i].l = i - 1;
		p[i].r = i;
		p[i].c = a[i] - a[i - 1];
		if (p[i].c == 0)
			p[i].c = INT_MAX;
	}
	sort(p + 2, p + n + 2, cmp);
	while (m > 0) {
		for (int i = 2; i <= n; i++) {
			if (m < p[i].c)
				m = 0;
			m -= p[i].c;
			ans++;
			p[i].c = INT_MAX;
			sort(p + 2, p + n + 2, cmp);
			//	cout << ans << " ";
		}
	}
	cout << ans << endl;
	return 0;
}
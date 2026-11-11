#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node {
	int a;
	char c;
} a[200010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].c;
	int l = 1, r = n;
	while (l < r) {
		int t = min(a[l].a, a[r].a);
		ans += (a[l].c != a[r].c) * t;
		a[l].a -= t;
		a[r].a -= t;
		l += (a[l].a == 0);
		r -= (a[r].a == 0);
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 15;
int n;

struct node {
	int x;
	char ch;
} p[maxn];
long long len = 0;
long long ans = 0;

int main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> p[i].x >> p[i].ch;
	int l = 1, r = n;
	while (l <= r) {
		if (p[l].x < p[r].x) {
			if (p[l].ch != p[r].ch)
				ans += p[l].x;
			p[r].x -= p[l].x;
			l ++;
		} else if (p[l].x > p[r].x) {
			if (p[l].ch != p[r].ch)
				ans += p[r].x;
			p[l].x -= p[r].x;
			r --;
		} else {
			if (p[l].ch != p[r].ch)
				ans += p[l].x;
			l ++, r --;
		}
	}
	cout << ans << endl;
	return 0;
}
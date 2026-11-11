#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
int a[500005];
int l[500005], p = 1;
int x[500005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.txt", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int sum = -1, pi = 1, len = 0, mi = 0; //pi: ÕýÔÚÉ¾
	for (int i = 1; i <= n; i++) {
		int h = upper_bound(a + 1, a + n + 1, a[i]) - a; // >
		l[p] = h - i;
		x[p] = a[i];
		len += l[p - 1];
		while (len * (a[i] - a[i - 1]) + mi > m) {
			len--;
			l[pi]--;
			mi -= a[i - 1] - x[pi];
			if (l[pi] == 0) {
				pi++;
			}
		}
		mi += len * (a[i] - a[i - 1]);
		sum = max(sum, len + l[p]);
		p++;
		i = h - 1;
	}
	cout << sum;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5 * 10e5+10;
ll n, m;
ll a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int nmx = a[i];
		int mm = m;
		int ans1 = 1;
		for (int j = i + 1; j <= n; j++) {

			int cc = nmx - a[j];
			if (cc <= mm) {
				ans1++;
				mm -= cc;
			} else {
				break;
			}
//			cout << a[i] << " " << a[j] << " " << " " << cc << " " << mm << " " << ans1 << "\n";
		}
		ans = max(ans1, ans);
	}
	cout << ans;


	return 0;
}
/*e.g.
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/



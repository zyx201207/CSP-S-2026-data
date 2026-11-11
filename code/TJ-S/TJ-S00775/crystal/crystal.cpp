#include <bits/stdc++.h>

using namespace std;

long long n, m, a[500005], sum[500005];

long long l, r, t, mid;

bool flag; 

int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
	l = 1, r = n;
	while (l < r) {
		flag = false;
		mid = (l + r) / 2 + 1;
		for (int i = mid; i <= n; i++) {
			t = sum[i] - sum[i - mid];
			//cout << a[i] * mid << " " << t << endl;
			if (a[i] * mid - t <= m) {
				flag = true;
				break;
			}
		}
		if (!flag) r = mid - 1;
		else l = mid;
		//if (l == r - 1) break;
		//cout << l << " " << mid << " " << r << endl;
		//else cout << mid, exit (0);
		 
	}
	cout << l;
	fclose (stdin);
	fclose (stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
bool f1, f2;
int n, a[N + 3], ans;
long long m;
vector <int> dirr[N + 3];
int sl3 (int idx) {
	long long mm = m;
	int x = 0;
	for (int i = 0; i < dirr[idx].size (); i ++) {
		if (mm < dirr[idx][i]) break;
		mm -= dirr[idx][i];
		x ++;	
	}
	return x + 1;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);cout.tie (0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != i) f1 = 1;
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) f2 = 1;
	}
	if (!f1) {
		for (int i = 1; i <= n - 1; i ++) {
			if (m - i  < 0) break;
			m -= i;
			ans ++;
		}
		cout << ans;
	}
	else if (!f2) {
		int x = a[n] - a[n - 1];
		for (int i = 1; i <= n; i ++) {
			if (m - x < 0) break;
			m -= x, x += x;
			ans ++;
		} 
		cout << ans;
	} 
	else {
		sort (a + 1, a + n + 1);
		for (int i = 1; i <= n; i ++) {
			for (int j = i - 1; j >= 1; j --) {
				dirr[i].push_back (a[i] - a[j]);
			}
		}
		for (int i = 1; i <= n; i ++) {
			ans = max (ans, sl3 (i));
		}
		cout << ans;
	}
	return 0;
} 

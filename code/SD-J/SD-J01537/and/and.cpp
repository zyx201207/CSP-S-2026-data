#include <bits/stdc++.h>
using namespace std;
int a [200010];
bool cmp (int x,int y) {
	return x > y;
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m;
	cin >> n >> m;
	cin >> a [1];
	int s = a [1];
	for (int i = 2;i <= n;i ++) {
		cin >> a [i];
		s = s & a [i];
	}
	sort (a + 1, a + n + 1, cmp);
	if (m == 1){
		cout << a [1];
		return 0;
	}
	if (m == n) {
		cout << s;
		return 0;
	}
	if (m == 2) {
		int ns = INT_MIN;
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= n;j ++) {
				if (i != j) {
					ns = max (ns, a [i] & a [j]); 
				} 
			}
		}
		cout << ns;
		return 0;
	}
	else {
		int ans = a [1];
		for (int i = 1;i <= m;i ++) {
			ans = ans & a [i];
		}
		cout << ans;
	}
	return 0;
} 


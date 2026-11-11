#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, mx = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
	}
    if (m == 1) {
    	for (int i = 1; i <= n; i ++) {
    		mx = max(a[i], 0LL + mx);
		}
		cout << mx;
		return 0;
	}
	if (m == n) {
		for (int i = 1; i <= n; i ++) {
			mx &= a[i];
		}
		cout << mx;
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				mx = max(a[i] & a[j], 0LL + mx);
			}
		}
		cout << mx;
		return 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
int c, T, n;
ll d, ans;
ll a[N];
bool sizA = true, sizB, sizC;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		ans = 0;
		ll dA;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i == 2) dA = a[2] - a[1];
			if (a[i] - a[i - 1] != dA && i >= 2) sizA = false; 
		}
		if (sizA) {
			if (dA >= d || a[n] - a[1] < 2 * d - 1) {
				cout << 0 << "\n";
				continue;	
			} else {
				cout << ((a[n] - a[1]) - d) / dA << "\n";
				continue; 
			}
		}
		sizB = (a[n / 2] - a[1] <= d && a[n] - a[n / 2] <= d) || (a[n / 2 + 1] - a[1] <= d && a[n] - a[n / 2 + 1] <= d);
		if (sizB) {
			cout << 0 << "\n";
			continue;
		}
		sizC = ((a[n] - a[1]) <= 10 * d);	
		for (int i = 1; i <= n - 3; i++) {
			for (int j = i + 3; j <= n && a[j] - a[i] <= 2 * d; j++) {
				for (int k = i + 1; k <= j; k++) {
					if (a[k] - a[i] > d || a[j] - a[k] > d) continue;
				//	cout << i << " " << j << " " << k << "\n";
					ans++;
				}
			}
		}
		cout << ans / 2 << "\n";
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

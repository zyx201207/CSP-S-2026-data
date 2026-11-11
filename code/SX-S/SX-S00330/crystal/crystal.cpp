#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005] ;

int main() {
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	int sum = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j <= m; j++) {
			sum++;
			a[i] += sum;
			if (a[i - 1] == a[i]) {
				ans++;
			}


		}
	}
	cout << ans;
	return 0;
}

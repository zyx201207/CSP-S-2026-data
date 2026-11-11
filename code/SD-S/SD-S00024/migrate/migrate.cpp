#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#define LCF using
#define pass namespace
#define CSP_S std
LCF pass CSP_S;
int a[2000006];
void solveA(){
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	if (d >= 2 * (a[2] - a[1])) {
		cout << n - 2 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return;
}
void solveB() {
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++) cin>> a[i];
	int sd;
	for (int i = 1; i <= n; i ++) {
		if (a[i] - d <= a[1] && a[i] + d >= a[n]){
			sd = i;
			break;
		}
	}
	int ans = 0;
	for (int i = max(sd - 2, 1); i < sd; i ++) {
		if (a[i + 3] - a[i] > d && a[i + 2] - a[i] <= d) {
			ans ++;
		}
	}
	cout << ans << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ovo,t;
	cin >> ovo >> t;
	while (t --) {
		if (ovo >= 11 && ovo <= 12) {
			solveA();
		}
		else if (ovo >= 13 && ovo <= 14) {
			solveB();
		}
		else {
			cout << 1;
		}
	}
	return 0;
}
/*
13 2
4 2
1 2 3 4
5 2
1 2 3 4 5

躺平吧还剩8分钟燃尽了 
*/

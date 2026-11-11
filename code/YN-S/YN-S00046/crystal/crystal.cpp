#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500050];
int d;//公差
int jia;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d = a[2] - a[1];
	jia = m / d;
	int cnt = 1;
	for (int i = 1; jia > 0; i++) {//1 3 5 7 9,d=2.当m=d时,ans=2;当m=2d时,ans=2;当m=3d时,ans=3;
		jia -= i;
		if (jia >= 0) {
			cnt++;
		} else {
			break;
		}
	}
	cout << cnt;
	return 0;
}
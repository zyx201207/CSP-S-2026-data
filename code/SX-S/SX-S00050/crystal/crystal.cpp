#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
bool flag = 1;
int a[500005];
int ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			flag = 0;
			break;
		}
	}
	if (flag == 1)
		cout << n;
	int i = 0;
	if (flag == 0) {
		int gc = a[2] - a[1]; //Çó¹«²î
		while (ans <= m) {
			++i;
			ans = ans + gc * i;
		}
		cout << i;
	}

	return 0;
}
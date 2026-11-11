#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, a[N], sum[N], num;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		if(a[i]<a[i-1])flag=1;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	if (n <= 10000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (a[i] * (i - j + 1) - (sum[i] - sum[j - 1]) > m) {
					cout << i - 1;
					return 0;
				}
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[i]*i - sum[i] > m) {
				cout << i - 1;
				return 0;
			}
		}
	}
//	else{
//
//	}
	return 0;
}
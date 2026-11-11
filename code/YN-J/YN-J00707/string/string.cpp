#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ll n, cnt = 0;
	cin >> n;
	ll a[n + 1];
	char b[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= n / 2; i++) {
		if (b[i] != b[n - i + 1])
			cnt += a[i];
	}
	cout << cnt ;
	return 0;
}
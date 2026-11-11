#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100001];
string c[100001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, ans = 0, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> c[i];
	}
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		if (c[1] == c[2] && c[1] != c[i]) {
			ans++;
		}
		if (c[1] == c[2] && c[2] != c[i - 1]) {
			sum++;
		}
	}
	cout << ans + sum;
	return 0;
}

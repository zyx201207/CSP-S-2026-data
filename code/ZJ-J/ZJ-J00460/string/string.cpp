#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e5 + 10;
ll n, sum, a[N], b[N];
char c[N], d[N];
char s[100000010];
int tt;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[i] = a[n - i + 1];
		d[i] = c[n - i + 1];
		sum += a[i];
	}
	if (sum <= 1e8) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				s[++tt] = c[i];
			} 
		}
		int ans = 0;
		for (int l = 1, r = tt; l <= r; l++, r--) ans += (s[l] != s[r]);
		cout << ans << '\n';
		return 0;
	}
	return 0;
}

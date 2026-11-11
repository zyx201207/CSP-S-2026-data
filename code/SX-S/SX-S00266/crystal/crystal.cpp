#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
int n, ans;
long long m, a[maxn], s[maxn];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ans = n;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]*i - s[i] + s[0] > m) {
			ans = i - 1;
			break;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
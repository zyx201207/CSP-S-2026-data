#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[500010], dp[100][100];
ll s[110][110];
ll ans, ans1;
ll tem, temp;
vector<ll>v;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[i][j] = a[j] - a[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = s[i][j] = s[i - 1][j] + dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v.push_back(s[i][j]);
		}
	}
	for (auto x : v) {
		if (x <= m) {
			temp = x;
			continue;
		}
		cout << temp;
		return 0;
	}
	return 0;
}
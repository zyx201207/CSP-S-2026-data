#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, m, ans;
ll p[N];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	sort(p + 1, p + n + 1);
	ans = p[n];
	for (int i = n - 1; i >= n - m + 1; i--) {
		ans = ans & p[i];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
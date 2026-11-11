#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+1;
ll n, m;
int maxx = -1e9;
ll s[N];
ll qzh[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++)
		qzh[i] = s[i] + qzh[i - 1];
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l <= r) {
			int mid = (l + r + 1) / 2;
			ll ans = s[i] * (i - mid + 1) - (qzh[i] - qzh[mid - 1]);
			if (ans > m)
				l = mid + 1;
			else {
				maxx = max(maxx, i - mid + 1);
				r = mid - 1;
			}
		}
	}
	cout << maxx;
	return 0;
}

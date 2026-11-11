#include<bits/stdc++.h>
using namespace std;
int n, ans;
long long m, a[500010], res;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int l = 1, r = 1; r <= n; r++) {
		res += (a[r] - a[r - 1]) * (r - l);
		while(1) {
			if(res <= m) {
				ans = max(ans, (r - l + 1));
				break;
			}
			res -= (a[r] - a[l]);
			l++;
		}
	}
	cout << ans;
	return 0;
}
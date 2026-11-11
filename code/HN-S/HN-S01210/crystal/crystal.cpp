#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long m;
long long a[N];
long long d[N];
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for(int i = n; i > 1; i--) {
		if(d[i] <= m) {
			ans = i;
			break;
		}
	} 
	cout << ans << '\n';
	return 0;
}

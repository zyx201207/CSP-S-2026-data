#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 500007;

int n, m;
int a[N];
int ans;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	int l = 1, r = 0, cst = 0;
	while(r < n) {
		r++;
		cst += (r-l) * (a[r] - a[r-1]);
		while(cst > m) cst -= (a[r] - a[l]), l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;

int n, m;
int a[N], s[N];

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n>> m;
	for(int i = 1; i<= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] + a[i];
	}
	int ans = 0;
	for(int l = 1, r = 1; l <= n; l ++){
		while(r + 1 <= n && a[r + 1] * (r - l + 2) - (s[r + 1] - s[l - 1]) <= m) r ++;
		ans = max(ans, r - l + 1);
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[200005], l, r, ans;
char c[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> c[i]; 
	l = 1, r = n;
	while (l < r){
		if (a[l] < a[r]) ans += (c[l] != c[r]) * a[l], a[r] -= a[l], l++;
		else if (a[l] > a[r]) ans += (c[l] != c[r]) * a[r], a[l] -= a[r], r--;
		else ans += (c[l] != c[r]) * a[l], l++, r--;
	}cout << ans;
	return 0;
}

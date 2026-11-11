#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500010], ans;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1, j=1, w=0; i<=n; i++){
		while (j < n && w + (j - i + 1) * (a[j+1] - a[j]) <= m){
			w += (j - i + 1) * (a[j+1] - a[j]);
			++j;
		}
		ans = max(ans, j-i+1);
		w -= a[j] - a[i];
	}
	cout << ans;
}
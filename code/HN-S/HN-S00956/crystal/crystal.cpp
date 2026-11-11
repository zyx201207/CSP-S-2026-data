#include<bits/stdc++.h>
#define int long long
#define fore(i,a,b) for(int i=(a);i<=(b);++i)
#define repe(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N = 5e5 + 1e3 + 10;
int n, m;
int a[N];
int ans;
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	fore(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1;
	int res = 0;
	fore(i, 1, n) {
		if(i > 1) {
			res = res + 1ll * (i - l) * (a[i] - a[i - 1]);
		}
		while(res > m && l < i) {
			res -= (a[i] - a[l]);
			l ++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
	
	return 0;
}
















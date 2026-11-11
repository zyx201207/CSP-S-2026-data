#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 5e5+10;
int n,m;
int a[N],s[N]; 

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i ++) s[i] = s[i-1]+a[i];
	int l = 1,ans = 1;
	for (int r = 2;r <= n;r ++) {
		int nd = a[r]*(r-l)-s[r-1]+s[l-1];
		while (nd > m && l < r) l ++,nd = a[r]*(r-l)-s[r-1]+s[l-1];
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}


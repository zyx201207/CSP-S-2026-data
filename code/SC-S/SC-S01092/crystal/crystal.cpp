#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int n,m,ans=1,a[N],s[N],ss[N],sss[N];
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i=1;i<=n;i++) {
		s[i] = a[i] - a[i-1];
		ss[i] = ss[i-1] + s[i];
		sss[i] = sss[i-1] + ss[i];
	}
	for(int i=1;i<=n;i++) {
		int l = 0,r = i-1,res = -1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(mid * ss[i] - (sss[i-1] - sss[i-mid-1]) <= m) {
				res = mid;
				l = mid + 1;
			}else {
				r = mid - 1;
			}
		}
		if(res != -1)
		ans = max(ans,res + 1);
	}
	cout << ans;
	return 0;
}
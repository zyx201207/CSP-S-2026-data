#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5+5;
int n,m,a[N],sum[N];

bool check(int l,int r) {
	if(l>=r) return 1;
	return (r-l)*a[r+1]-(sum[r]-sum[l]) <= m;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i-1]+a[i]; 
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		int l = 0,r = i-1;
		while(l < r) {
			int mid = (l+r)>>1;
			if(check(mid,i-1)) r = mid;
			else l = mid+1;
		}
		ans = max(ans,i-l);
	} 
	cout << ans;
	return 0;
}

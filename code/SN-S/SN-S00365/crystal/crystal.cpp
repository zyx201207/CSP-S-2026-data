/*
西安辅轮中学
韩谦益 
SN-S00365
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int x) {
	int sum = 0,ans = 0;
	for(int i = 1;i<=x;i++) {
		sum+=a[x]-a[i];
	}
	ans = sum;
	for(int i = x+1;i<=n;i++) {
		sum+=x*(a[i]-a[i-1]);
		sum-=(a[i]-a[i-x]);
		ans = min(ans,sum);
	}
	if(ans > m) {
		return false;
	}
	return true;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = n,ans = 1;
	while(l <= r) {
		int mid = (l+r)/2;
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}

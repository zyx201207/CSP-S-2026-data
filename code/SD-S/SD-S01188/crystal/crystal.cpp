#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll sum[500005];
ll n,m;
bool check(int x) {
	for(int i=1; i<=n-x+1; ++i) {
		int r=i+x-1;
		ll cnt=a[r]*x;
		ll ad=cnt-(sum[r]-sum[i-1]);
		if(ad<=m) {
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; ++i) {
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r+1)/2;
		if(check(mid)) {
			l=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}

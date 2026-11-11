#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long pre[500010];
bool check(long long mid) {
	for(long long l=1; l<=n-mid+1; l++) {
		long long r=l+mid-1;
		long long val=a[r]*mid-(pre[r]-pre[l-1]);
		if(val<=m)return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1; i<=n; i++) {
		pre[i]=pre[i-1]+a[i];
	}
	long long l=1;
	long long r=n;
	long long ans=1;
	while(l<=r) {
		long long mid=(l+r)/2;
		if(check(mid)) {
			ans=mid;
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
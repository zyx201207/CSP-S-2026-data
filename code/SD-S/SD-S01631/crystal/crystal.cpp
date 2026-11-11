#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool check(long long x) {
	long long now=m;
	for(long long i=1; i<=x; i++) {
		now-=(a[x]-a[i]);
		if(now<0) return 0;
	}
	return 1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<r-10) {
		long long mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	for(long long x=l; x<=r; x++) {
		long long now=m;
		for(long long i=1; i<=x; i++) {
			now-=(a[x]-a[i]);
			if(now<0) {
				cout<<ans;
				return 0;
			}
		}
		ans=x;
	}
	cout<<ans;
	return 0;
}//¶þ·Ö£¿

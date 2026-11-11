#include<bits/stdc++.h>

using namespace std;
long long n,m,a[10000005],s[10000005],ans,a1[10000005],s1[100000005];
long long cmp(long long aa,long long bb) {
	return aa>bb;
}
long long check(long long x) {
	if((x*a[x])-s[x]<=m) {//||s1[x]-(x*a1[x])<=m
		return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		a1[i]=a[i];
	}
	if(m>1e8) { //1 3 5 7 9 11 13 15 17 19
		long long t=a[2]-a[1];
		for(long long i=1; i<=n; i++) {
			if(a[i]*i-(a[1]+a[i])*((a[1]+a[i])/2/t)<=m) {
				ans=i;
			} else {
				cout<<ans;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	sort(a1+1,a1+1+n,cmp);
	for(long long i=1; i<=n; i++) {
		s[i]=s[i-1]+a[i];
		s1[i]=s1[i-1]+a1[i];
	}
	long long l=1;
	long long r=n;
	while(l<=r) {
		long long mid=(l+r)/2;
		if(check(mid)==1) {
			l=mid+1;
			ans=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
2 1 2 4 8 9
5 8
-3 -1 2 2 7
*/
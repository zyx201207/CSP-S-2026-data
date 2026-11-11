#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m;
long long a[5*N];
long long s[5*N];
bool check(long long mid){
	for(long long i=mid;i<=n;i++){
		long long x=a[i]*mid-s[i]+s[i-mid];
		if(x<=m) return 1;
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	long long l=1,r=n;
	sort(a+1,a+n+1);
	long long mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

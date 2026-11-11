#include<bits/stdc++.h>
using namespace std;
long long qkread() {
	long long n1=0,qkf=1;
	char qkc=getchar();
	while(qkc<'0'||qkc>'9') {
		if(qkc=='-') qkf=-1;
		qkc=getchar();
	}
	while(qkc>='0'&&qkc<='9') {
		n1=n1*10+qkc-48;
		qkc=getchar();
	}
	return n1*qkf;
}
long long n,m,a[500001],s[500001],l,r,mid,ans;
bool check(long long n1) {
	for(int i=n1; i<=n; i++) {
		if(n1*a[i]-s[i]+s[i-n1]<=m) return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=qkread(),m=qkread();
	for(int i=1; i<=n; i++) a[i]=qkread();
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	l=1,r=n;
	while(l<=r) {
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

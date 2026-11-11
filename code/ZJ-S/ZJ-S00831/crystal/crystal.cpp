#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
	ll f=1;
	ll k=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void write(ll x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x<10) {
		putchar(x+'0');
	} else {
		write(x/10);
		putchar(x%10+'0');
	}
}
ll n,m,i,ans,x,l,r,mid,cnt,a[500005],b[500005],c[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(i=1; i<=n; i++) {
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(i=2; i<=n; i++) {
		b[i-1]=a[i]-a[i-1];
	}
	x=0;
	c[1]=0;
	for(i=1; i<=n-1; i++) {
		c[i+1]=c[i]+b[i]*i;
	}
	l=1;
	r=n;
	while(l<r){
		mid=l+(r-l+1)/2;
		if(c[mid]<=m){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cnt=l;
	ans=cnt;
	for(i=cnt+1; i<=n; i++) {
		l=1;
		r=i;
		while(l<r) {
			mid=l+(r-l)/2;
			x=c[i]-c[mid-1]-(mid-1)*(a[i]-a[mid-1]);
			if(x<=m) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}
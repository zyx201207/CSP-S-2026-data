#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=500005;
inline ll read() {
	ll x=0,f=1;
	ll ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline ll write(ll x) {
	if(x<0) {
		x=-x;
		putchar('-');
	}
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}
ll n,m,a[N],d[N],s[N];
bool check(ll x) {
	ll minn=1000000000005;
//	cout<<x<<endl;
	for(ll i=x; i<=n; i++) {
//		cout<<minn<<' ';
		minn=min(minn,s[i]-s[i-x]+a[i]*x);
	}
//	cout<<endl;
	if(minn<=m) {
		return false;
	}
	return true;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
//	cout<<n<<endl;
	for(ll i=1; i<=n; i++) {
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(ll i=1; i<=n; i++) {
		d[i]=0-a[i];
		s[i]=s[i-1]+d[i];
	}
//	for(int i=1; i<=n; i++) {
//		cout<<s[i]<<' ';
//	}
//	cout<<endl;
	ll l=1,r=n;
	while(l<r) {
		ll mid=(l+r)>>1;
		if(check(mid)) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	write(l-1);
	return 0;
}
/*
5 5
-1 -2 -3 -4 -5
*/

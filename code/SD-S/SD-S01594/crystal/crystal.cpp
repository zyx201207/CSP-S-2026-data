#include<bits/stdc++.h>
#define ll long long
#define ac read()
#define N (500005)
using namespace std;
inline ll read() {
	ll x=0,f=1;
	int c=getchar();
	while(!isdigit(c)) {
		f=(c=='-')?-1:1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
ll n,m;
ll a[N],tot;
ll Nee[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=ac,m=ac;
	for(int i=1; i<=n; ++i) {
		a[i]=ac;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(ll i=1; i<=n; ++i) {
		Nee[i]=Nee[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
		if(m>=Nee[i]) {
			ans=max(ans,i);
		} else {
			ll erf=Nee[i]-m,er=0;
			ll l=0,r=i-1;
			while(l<=r) {
				ll mid=(l+r)>>1;
				ll NUM=Nee[mid]+1ll*mid*(a[i]-a[mid]);
				if(NUM>=erf) {
					er=mid;
					r=mid-1;
				} else {
					l=mid+1;
				}
			}
			ans=max(ans,i-er);
		}
	}
	cout<<ans<<"\n";
	return 0;
}

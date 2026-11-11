#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,a[N]; 
char c[N];
ll ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %s",&a[i],&c[i]);
		sum+=a[i];
	}
	ll suml=1,sumr=sum;
	ll l=1,r=n,sl=a[1],sr=a[n];
	ll midl=(suml+sumr)>>1LL*1;
	ll midr=midl+(!(sum&1));
	while(suml<=midl&&sumr>=midr){
		ll mi=min(sl,sr);
		if(c[l]!=c[r]){
			ans+=mi;
		}
		sl-=mi;
		sr-=mi;
		suml+=mi;
		sumr-=mi;
		if(sl==0){
			l++;
			sl=min(a[l],midl+1-suml);
		}
		if(sr==0){
			r--;
			sr=min(a[r],sumr-midr+1);
		}
	} printf("%lld",ans);
	return 0;
}

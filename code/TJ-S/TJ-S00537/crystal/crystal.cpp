#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],b[N],maxx,num;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	ll l=1,r=1;
	while(l<=r&&r<=n){
		m-=b[r]*(r-l);
		while(m<0){
			m+=a[r]-a[l];
			l++;
		}
		ll ans=r-l+1;
		maxx=max(maxx,ans);
		r++;
	}
	printf("%lld",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

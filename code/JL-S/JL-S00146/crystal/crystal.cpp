#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ll n,m,ans=0,pos=0;
	scanf("%lld%lld",&n,&m);
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a.begin(),a.end(),greater<ll>());
	
	for(ll i=a[0];i>=a[n-1];i--){
		while(a[pos]>i)
			pos++;
		ll t=m,cnt=0;
		for(ll j=pos;j<n;j++){
			ll cost=i-a[j];
			if(t-cost<0)break;
			t-=cost;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%lld\n",ans);

	return 0;
}

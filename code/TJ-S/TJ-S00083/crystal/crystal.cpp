#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N];
vector<ll> v[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);;
	bool flag=true;
	ll z;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		z=a[i]-a[i-1];
		if(a[i]!=i) flag=false;
	}
	if(flag){
		for(ll i=2;i<=n;i++){
			ll o=(i*i-i)/2*z;
			if(o>m){
				printf("%lld",i-1);
				return 0;
			}
		}
		printf("%lld",n);
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			v[i].push_back(a[j]-a[i]);
		}
	}
	ll ans=-1;
	for(ll i=n;i>=1;i--){
		ll cnt=0,m1=m;
		for(ll j=v[i].size()-1;j>=0;j--){
			if(m1+v[i][j]>=0){
				m1+=v[i][j];
				cnt++;
			}else break;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans+1);
	return 0;
} 

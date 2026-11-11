#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
ll read(){
	ll x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
ll n[N],sum[N];
//Oct31==Dec25?

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll a,b;
	a=read(),b=read();
	for(int i=1;i<=a;i++){
		n[i]=read();
	}
	sort(n+1,n+a+1);
	for(int i=1;i<=a;i++){
		sum[i]=sum[i-1]+n[i];
	}
	ll ans=0;
	for(ll i=1;i<=a;i++){
		ll l=1,r=i;
		ll t=i;
		while(l<=r){
			ll mid=l+r>>1;
			if((i-mid+1ll)*n[i]-(sum[i]-sum[mid-1])<=b){
				r=mid-1;
				t=mid;
			}else l=mid+1;
		}
		//cout<<i<<" "<<i-t+1<<"\n";
		ans=max(ans,i-t+1);
	}
	cout<<ans<<"\n";
	return 0;
}
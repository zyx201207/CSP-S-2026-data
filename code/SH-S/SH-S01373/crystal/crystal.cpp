#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,mx,mn=1e18,a[500009];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool fl1=1,fl2=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,abs(a[i]));
		mn=min(mn,a[i]);
		if(a[i]!=i) fl1=0;
		if(i>2&&a[i]-a[i-1]!=a[2]-a[1]) fl2=0;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ll cnt=m,x=1;
			for(ll j=i-1;j>=1;j--)
				if(cnt>=a[i]-a[j])
					x++,cnt-=(a[i]-a[j]);
			ans=max(ans,x);
		}
		cout<<ans<<"\n";
	}else if(mx<=100){
		ll ans=1;
		for(ll i=mn;i<=100;i++){
			ll l=0,r=n+1,cnt=m,x=0;
			while(l+1<r){
				ll mid=(l+r)/2;
				if(a[mid]<=i) l=mid;
				else r=mid;
			}
			for(ll j=l;j>=1&&cnt;j--)
				if(cnt>=i-a[j])
					x++,cnt-=(i-a[j]);
			ans=max(ans,x);
		}
		cout<<ans<<"\n";
	}else if(fl1){
		ll l=0,r=n+1;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(mid*(mid+1)/2<=m) l=mid;
			else r=mid;
		}
		cout<<l+1<<"\n";
	}else if(fl2){
		ll d=a[2]-a[1];
		ll l=0,r=n+1;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(d*mid*(mid+1)/2<=m) l=mid;
			else r=mid;
		}
		cout<<l+1<<"\n";
	}
	return 0;
}

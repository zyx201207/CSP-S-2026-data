#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ll n,m;
	cin>>n>>m;
	ll e,f=0;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		if(i==2) e=a[i]-a[i-1];
		if(i>=2&&a[i]-a[i-1]!=e) f=1;
	}
	if(!f){
		ll p=m/e*2;
		ll y=sqrt(p);
		if(y*(y+1)>p) ans=min(y,n);
		else ans=min((y+1),n);
	}
	else{
		for(ll i=1;i<=n;i++){
		    ll cc=0,k=i-1;
		    while(k>=1){
			    ll p=a[i]-a[k];
			    if(cc+p>m) break;
			    else{
				    cc+=p;
				    k--;
			    }
		    }
		    ans=max(ans,i-k);
	    }
	}
	cout<<ans;
	return 0;
}
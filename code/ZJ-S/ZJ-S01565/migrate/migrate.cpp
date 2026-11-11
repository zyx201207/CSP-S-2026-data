#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d;
ll x[2000010];
ll f[2000010];
bool ch(int i){
	return x[i]-x[i-1]<=d&&x[i-1]-x[i-3]<=d&&x[i-2]-x[i-3]<=d&&x[i]-x[i-2]<=d&&x[i]-x[i-3]>d;
}
ll upp(ll xx){
	ll l=0,r=n;
	while(l<r){
		ll mid=(l+r-1)/2;
		if(x[mid]>xx){
			r=mid;
		}
		else l=mid+1;
	}
	return r; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ll ans=0;
		bool b=1;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		for(ll i=4;i<=n;i++){
			if(ch(i)){
				ans++;
				ll up=upp(x[i-1]-d);
				if(!ch(i-3)&&!ch(i-2)&&!ch(i-1))ans+=up;}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
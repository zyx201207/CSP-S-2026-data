#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
		}
		n=(n+1)>>1+1;
		if((n-k)%3==0) cout<<(n-k)/3<<"\n";
		else cout<<(n-k)/3+1<<"\n";
	}
	return 0;
} 

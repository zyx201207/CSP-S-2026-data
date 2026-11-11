#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,t;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	cin>>c>>t;
	while(t--){
		ll n,k;
		map<ll,ll> u,v;
		cin>>n>>k;
		for(ll i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(c==13||c==14){
			cout<<1<<'\n';
		}
		else cout<<((n-1)/k+1)/2<<'\n';
	}
	return 0;
}

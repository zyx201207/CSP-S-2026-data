#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll a,b;
	cin>>a>>b;
	for(ll i=0;i<b;i++){
		ll c,d;
		cin>>c>>d;
		ll mn=1;
		for(ll j=0;j<d-1;j++){
			ll q,w;
			cin>>q>>w;
			mn=max(mn,w-q);
		}
		cout<<mn<<'\n';
	}
	return 0;
} 

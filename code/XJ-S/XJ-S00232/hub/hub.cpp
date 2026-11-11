#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
		}
		cout<<(n+7)/8-(k-1)/4;
	}
	return 0;
}


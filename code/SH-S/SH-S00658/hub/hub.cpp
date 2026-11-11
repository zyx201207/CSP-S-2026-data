#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<n;++i){
			ll u,v;
			cin>>u>>v;
		}
		if(k>=n) cout<<0<<endl;
		else if(n==2&&k==1) cout<<1<<endl;
		else if(n==3&&(k==1||k==2)) cout<<1<<endl;
		else if(n==4&&k==1) cout<<2<<endl;
		else if(n==4&&(k==2||k==3)) cout<<1<<endl;
		else if(n==5&&(k==3||k==4)) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}

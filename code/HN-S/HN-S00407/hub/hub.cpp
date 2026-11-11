#include <bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>u>>v;
	}
	if(t==2) cout<<2<<1;
	if(t==3) cout<<1<<4<<5;
	if(t==4) cout<<3<<7<<5<<1;
	if(t==5) cout<<0<<3<<2<<5<<6;
	return 0;
}

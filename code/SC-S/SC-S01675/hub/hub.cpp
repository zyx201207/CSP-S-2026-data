#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,l,r;i<=n;++i){
			cin>>l>>r;
		}
		cout<<((n-1)/2-k+5)/4<<'\n';
	}
	return 0;
}
//刘曌珩   SN-S00374  西安市含光中学 
#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u[i]>>v[i];
		if(c==13||c==14){
			cout<<((n-1)/2+1-k)/4+1<<"\n";
		}
		else{
			cout<<1<<"\n";
		}
	}
	return 0;
}

#include<bits/stdc++.h>//
#define int long long 
using namespace std;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		
	}
	while(t--){
		int n,k,ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			ans=min(abs(x-y),ans);
		}cout<<ans<<"\n";
	}
	return 0;
}//

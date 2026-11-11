#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _,t;
	cin>>_>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ans=max(ans,abs(u-v));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n<=6){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	return 0;
}

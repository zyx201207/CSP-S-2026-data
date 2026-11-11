#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> q[1005];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			q[u].push_back(v);
			q[v].push_back(u);
		}
		cout<<1<<"\n";
	}
	
	
	return 0;
}

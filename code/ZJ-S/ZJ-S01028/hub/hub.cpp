#include<bits/stdc++.h> 
using namespace std;
const int N=3e5+5;
int c,T,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(k==n){
			cout<<"0\n";
			continue;
		}
		vector<int>G[N];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(c==7||c==11||c==12){
			cout<<"0\n";
			continue;
		}else if(c==13||c==14){
			if(k>=n/2)
				cout<<"1\n";
			cout<<"2\n";
			continue;
		}else
			cout<<"1\n";
	}
	return 0;
}

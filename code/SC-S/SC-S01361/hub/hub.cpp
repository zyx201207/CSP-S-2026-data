#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<pair<int,int> > path;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			path.push_back({u,v});
		}
		while(true);
	}
	return 0;
} 
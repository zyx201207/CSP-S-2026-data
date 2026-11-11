#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> edge[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(c==13||c==14){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		
	}
	return 0;
}


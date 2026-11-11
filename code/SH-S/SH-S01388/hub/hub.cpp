#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int ans=0;
		vector<vector<int>>e(2000010);
		for(int i=1;i<=n;++i){
			int u,v;
			cin>>u>>v;
			if(i<=(n-1)/2){
				++ans;
			}
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

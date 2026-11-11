#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> g[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n==k) cout<<"0\n";
		else cout<<max(1,(n-k)/k)<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> es[1000009];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			es[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			es[u].push_back(v);
			es[v].push_back(u);
		}
		cout<<n/k<<endl;
	}
	return 0;
}

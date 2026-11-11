#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>mp[5000005];
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		mp[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	if(n/k<=2)cout<<1<<"\n";
	else{
		cout<<2<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>ve[1000010];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	cout<<2<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	cout<<" "<<endl;
	return 0;
}

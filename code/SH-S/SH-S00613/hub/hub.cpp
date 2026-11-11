#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		int u,v;
		cin>>u>>v;
	}
	cout<<max(k/n, n/k)<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

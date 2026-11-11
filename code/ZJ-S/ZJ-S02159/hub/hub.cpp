#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	if(k==n-1){
		cout<<1<<'\n';
		return;
	}
	if(k>=n/2){
		cout<<1<<'\n';
		return;
	}
	
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int C,t;
	cin>>C>>t;
	while(t--){
		solve();
	}
	return 0;
}
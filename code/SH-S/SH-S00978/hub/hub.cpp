#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;

void solve(){
	if(n<=k){
		cout<<0<<"\n";
		return;
	}
	cout<<1<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		solve();
	}
	return 0;
}

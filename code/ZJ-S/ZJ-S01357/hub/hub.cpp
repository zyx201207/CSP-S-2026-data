#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++) cin>>u>>v;
		if(n==k) cout<<"0\n";
		else if(n/k==1) cout<<"1\n";
		else cout<<n/k-1<<'\n';
	}
	return 0;
}
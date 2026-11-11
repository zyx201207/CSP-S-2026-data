#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(n==k)cout<<0<<endl;
		else if(n<=k+3)cout<<1<<endl;
		else cout<<n/k-1<<endl;
	}
	return 0;
}

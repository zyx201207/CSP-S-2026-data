#include<bits/stdc++.h>
using namespace std;
int c,t;
int g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u]=v;
			g[v]=u;
		}
		if(k<=2){
			cout<<0;
		}else if(k==3){
			cout<<1;
		}else if(k<n){
			cout<<k/2;
		}else{
			cout<<n/2+n%2;
		}
	}
	return 0;
}

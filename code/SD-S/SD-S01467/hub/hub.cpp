#include<bits/stdc++.h>
using namespace std;
#define int long long
bool g[10005][4005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,c;cin>>c>>t;
	while(t--){
		int n,m,u,v;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
		if(m>=n){
			cout<<0<<"\n";
			continue;
		}
		if(2*m+1>=n){
			cout<<1<<"\n";
			continue;
		}else{
			cout<<2<<"\n";
		}
	}
	
	return 0;
}

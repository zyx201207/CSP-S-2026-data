#include<bits/stdc++.h>
using namespace std;
vector<int> g[1145141];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,k,n,u,v;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		if(k==n){
			cout<<0<<endl;
			continue;
		}
		if(k==n-1 || k==n-2){
			cout<<1<<endl;
			continue;
		}
		if(n<=5 && k>=2){
			cout<<1<<endl;
			continue;
		}
		if(n<=10){
			int mx=0;
			for(int i=1;i<=n;i++) mx=max(mx,(int)g[i].size());
			if(n<=5 && mx>=4){
				cout<<1<<endl;
				continue;
			}
			if(n<=5){
				cout<<2<<endl;
				continue;
			}
			if(mx>=4) cout<<2;
			else cout<<3;
			continue;
		}
		int m=(n+3)/2;
		m-=k;
		cout<<(m-1)/4+1<<endl;
	}
	return 0;
}
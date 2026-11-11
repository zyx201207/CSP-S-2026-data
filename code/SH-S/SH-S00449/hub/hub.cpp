#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>g[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		bool f=1;
		if(n%2==0)f=0;
		for(int i=1;i<=n;i++){
			int u,v;cin>>u>>v;
			if(i<=n/2&&(u!=i||v!=i+1))f=0;
			if(i>n/2&&(u!=i-n/2||v!=i+1))f=0;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(f){
			if(k==n)cout<<0<<endl;
			else if(k==1)cout<<(n/2+1)/2<<endl;
			else cout<<max(1,(n/2+1-k)/3)<<endl;
		}
	}
	return 0;
}


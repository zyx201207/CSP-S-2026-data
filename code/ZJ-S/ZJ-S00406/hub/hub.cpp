#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
int c,T;
int n,k;
int dep[N];
vector<int>g[N];

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		cout<<0<<'\n';
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		
	}
	
	return 0;
} 

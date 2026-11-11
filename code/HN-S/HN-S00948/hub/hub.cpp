#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1000006];
int n,k,c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
	}
	
	return 0;
}

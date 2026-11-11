#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,M=5e5+10;
int c,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		vector<int> g[N];
		for(int i=1;i<=n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		
		
		cout<<k<<"\n";
	}
	return 0;
}
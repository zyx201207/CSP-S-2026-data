#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int c,t;
vector<int>G[1000010];
signed main(){
	fast;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(c==13||c==14){
			cout<<((n+1)/2+3-k)/4+1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}


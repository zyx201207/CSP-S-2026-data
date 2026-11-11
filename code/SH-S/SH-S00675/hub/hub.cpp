#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c;
ll t;
vector<ll> g[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		
		
	}
	return 0;
} 

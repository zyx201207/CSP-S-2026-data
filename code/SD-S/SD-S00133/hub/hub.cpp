#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v;
vector<int>ve[2000005];
void solve(){
	for(int i=0;i<=2000002;i++){
		ve[i].clear();
	}
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve(); 
	} 
	return 0;
}


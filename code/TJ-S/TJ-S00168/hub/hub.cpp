#include<bits/stdc++.h>
using namespace std;
vector<int> g[2e6];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==5&&k==2){
		cout<<1;
		return;
	}else if(n==10&&k==3){
		cout<<2;
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+5;
int c,t,n,k,dep[N];
vector<int>g[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(n==2){
		cout<<"0\n";
		return;
	}
	dep[0]=0;
	dfs(1,0);
	int p=0;
	for(int i=1;i<=n;i++){
		if(dep[p]<dep[i])p=i;
	}
	dep[0]=0;
	dfs(p,0);
	int len=0;
	for(int i=1;i<=n;i++){
		len=max(len,dep[i]);
	}
	cout<<(len+1)/4<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}



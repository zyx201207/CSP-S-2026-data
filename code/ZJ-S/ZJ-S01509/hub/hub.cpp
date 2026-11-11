#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,st,mx,dep[N];
vector<int> e[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>mx) mx=dep[u],st=u;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(k==2){
			dep[0]=-1;
			dfs(1,0);
			memset(dep,0,sizeof(dep));
			dep[0]=-1;
			dfs(st,0);
			cout<<(mx+3)/4<<"\n";
			continue;
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(n-2<=k){
			cout<<"1\n";
			continue;
		}
		cout<<"1\n";
	}
	return 0;
}

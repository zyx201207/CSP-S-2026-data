#include<bits/stdc++.h>
using namespace std;
vector<int>g[500005];
int dep[500005];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	for(auto v:g[u])
		if(v!=f)dfs(v,u);
}

void solve(){
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int st2=0;
	for(int i=1;i<n;i++)
		if(dep[i]>dep[st2])st2=i;
	dfs(st2,0);
	int mx=-1;
	for(int i=1;i<n;i++)
		mx=max(mx,dep[i]);
	cout<<(mx-1)/2<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000;
long long n,k,f[maxn+5];
int ans;
vector<int> e[maxn+5];
bool vis[maxn+5];
int chs[maxn+5];
int dfs2(int u,int fa){
	if(vis[u]){
		return 0;
	}
	int res=INT_MAX;
	for(int v:e[u]){
		if(v==fa){
			continue;
		}
		res=min(res,dfs2(v,u));
	}
	return res+1;
}
void dfs(int p,int tot){
	if(tot>k){
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			ans=max(ans,dfs2(i,0));
		}
		return ;
	}
	for(int v=p+1;v<=n;v++){
		vis[v]=1;
		chs[tot]=v;
		dfs(v,tot+1);
		vis[v]=0;
	}
}
void solve(){
	ans=0;
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(0,1);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
//		cout<<"T"<<t<<"\n";
		solve();
	}
	return 0;
}
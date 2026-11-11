#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[1000005];
int vis2[1000005];
int n,ans=0,k;
vector<int>e[1000005];
void sfd(int u,int fa){
//	cout<<u<<' ';
//	if(vis[u]&&fa!=-1)return;
	for(auto v:e[u]){
		if(v==fa)continue;
		if(vis[v]&&(!vis[u]))continue;
		vis2[v]=min(vis2[v],vis2[u]+1);
		sfd(v,u);
	}
	return;
}
int check(){
	memset(vis2,0x3f,sizeof(vis2));
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&vis2[i]==0x3f3f3f3f3f3f3f3f){
			cnt++;
			if(cnt>2)return 0x3f3f3f3f3f3f3f3f;
		}
		if(vis[i]){
			vis2[i]=0;
			sfd(i,-1);
//			cout<<'!';
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)res=max(res,vis2[i]);
//	cout<<"test:"<<res<<'\n';
//	for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
//	cout<<'\n';
//	}
	return res;
} 
void dfs(int step){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=vis[i];
	}
	if(cnt>k)return;
	if(step>n){
		ans=min(ans,check());
		return;
	}
	vis[step]=0;
	dfs(step+1);
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	return;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=0x3f3f3f3f3f3f3f3f;
		memset(vis,0,sizeof(vis));
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
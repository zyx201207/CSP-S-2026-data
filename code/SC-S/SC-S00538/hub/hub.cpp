#include<bits/stdc++.h>
using namespace std;
#define int long long
int o,t,ans=1e9,n,m,vis[15],f[15],c[100005];
vector<int>v[100005];
void dfs1(int x,int y){
	vis[x]=1;
	for(auto i:v[x]){
		if(i!=y&&c[i]){
			dfs1(i,x);
		}
	}
}
void dfs2(int x,int y){
	if(c[x]){
		f[x]=0;
	}
	for(auto i:v[x]){
		if(i!=y){
			dfs2(i,x);
			f[x]=min(f[x],f[i]+1);
		}
	}
}
void check(){
	memset(vis,0,sizeof vis);
	int cnt=0,ct=0;
	for(int i=1;i<=n;i++){
		f[i]=1e9;
		if(vis[i]==0&&c[i]){
			dfs1(i,0);
			cnt++;
		}
	}
	if(cnt>2){
		return;
	}
	for(int i=1;i<=n;i++){
		dfs2(i,0);
		ct=max(f[i],ct);
	}
	ans=min(ct,ans);
}
void dfs(int x){
	if(x>m){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			c[i]=1;
			dfs(x+1);
			c[i]=0;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>o>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1);
		cout<<ans<<"\n";
		ans=1e9;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
} 
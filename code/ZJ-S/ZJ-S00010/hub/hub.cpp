#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int C,T;
int n,k,ans;
int c[maxn];
int vis[maxn];
vector<int>e[maxn];
int dfss(int u,int fa){
	if(vis[u])return 1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa){
			int kk=dfss(v,u);
			if(kk)return 1;
		}
	}
	return 0;
}
int check(int u){
	int now=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		int k=dfss(v,u);
		if(k)now++;
	}
	return now>1;
}
int ddfs(int u,int fa){
	int lst=1e18;
	if(vis[u])return 0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa){
			lst=min(ddfs(v,u)+1,lst);
		}
	}
	return lst;
}
void dfs(int now,int sum){
	if(sum>k||n+1-now+sum<k)return;
	if(now==n+1){
		int f=0;
		for(int i=1;i<=n;i++)if(!vis[i]&&check(i))f++;
		if(f>1)return ;
		int sum=0;
		for(int i=1;i<=n;i++)sum=max(sum,ddfs(i,0));
		ans=min(ans,sum);
		return;
	}
	vis[now]=1;
	dfs(now+1,sum+1);
	vis[now]=0;
	dfs(now+1,sum);
}
void solve(){
	cin>>n>>k;
	ans=1e18;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)solve();
}

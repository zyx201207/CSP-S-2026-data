#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=1e6+10;//±©Á¦15 
int c,t;
vector <int> G[Maxn];
int ans=INT_MAX;
int n,k;
vector <int> v;
int sum[Maxn];
int res[Maxn];
int vis[Maxn];
int viss[Maxn];
void anss(int x,int op){
	res[x]=1;
	vis[x]=min(vis[x],op);
	for(auto it:G[x]){
		if(res[it])	continue;
		anss(it,op+1);
	}
}
void dfs(int l){
	if(l==k){
		for(int i=1;i<=n;i++)	vis[i]=INT_MAX;
		for(auto it:v){
			for(int i=1;i<=n;i++)	res[i]=0;
			anss(it,0);
		}
		int sum=INT_MIN;
		for(int i=1;i<=n;i++){
			sum=max(sum,vis[i]);
//			cout<<vis[i]<<" "; 
		}
//		cout<<"\n";
//		if(sum==1){
//			for(int i=1;i<=n;i++)	cout<<vis[i]<<" ";
//			cout<<"\n";
//		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(viss[i]==1)	continue;
		viss[i]=1;v.push_back(i);
		dfs(l+1);
		viss[i]=0;v.pop_back();
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			sum[i]=INT_MAX;
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0);
		cout<<ans<<"\n";
		ans=INT_MAX;
	}
	return 0;
}

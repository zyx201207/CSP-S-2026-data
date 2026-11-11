#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,inf=1e9;
int n,k;


namespace solve1{
vector<int> vec[N];
int dis[N];
bool vis[N],sp[N];
int res;
void dfs(int u){
	vis[u]=1;
	for(auto &v:vec[u]){
		if(vis[v]||!sp[v])continue;
		dfs(v);
	}
} 
void dfs2(int u){
	vis[u]=1;
	if(sp[u])dis[u]=0;
	for(auto &v:vec[u]){
		if(vis[v])continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfs2(v);
	}
}
void solve(){
	for(int i=1;i<=n;i++)vec[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		vec[u].push_back(v),vec[v].push_back(u);
	}
	int ans=inf;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		for(int j=1;j<=n;j++)vis[j]=0,dis[j]=inf,sp[j]=0;
		for(int j=1;j<=n;j++)if(i>>(j-1)&1)sp[j]=1;
		int cnt=0;
		vector<int> v;
		for(int j=1;j<=n;j++)if(!vis[j]&&sp[j])cnt++,dfs(j),v.push_back(j);
		if(cnt>2)continue;
		res=0;
		for(int j:v){
			for(int k=1;k<=n;k++)vis[k]=0;
			dfs2(j);
		}
		for(int j=1;j<=n;j++)res=max(res,dis[j]);
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
}


signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t;cin>>c>>t;	
	while(t--){
		cin>>n>>k;
		if(n<=10)solve1::solve();
	}
	return 0;
}

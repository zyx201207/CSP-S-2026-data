#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+5;
int n,k;
vector<int> g[N];
int fa[N],sz[N];
int dis[N];
int is[N],dep[N];
map<string,int> m;
void dfs1(int u,int f){
	fa[u]=f;
	sz[u]=1;
	dep[u]=dep[f]+1; 
	for(auto v:g[u]){
		if(v==f)continue;
		dfs1(v,u);
		sz[u]+=sz[v]; 
	}
}
void dfs2(int u,int f,int rest){
	if(rest==0)return ;
	is[u]=1;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs2(v,u,rest-1);
	}
}
void dfs3(int u,int f){
	dis[u]=min(dis[u],dis[f]+1);
	for(auto v:g[u]){
		if(v==f)continue;
		dfs3(v,u);
	}
}
int check(){
	
	vector<int> V;
	int cnt=0;
	string s;
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		if(is[i]==1)
		{
			cnt++;
			V.push_back(i);
		}
		s+=(is[i]==1?'1':'0');
	}
	if(m.find(s)!=m.end())return INF;
	if(cnt!=k)return INF;
	m[s]=1;
	for(auto x:V){
		dis[x]=0;
		dfs3(x,0);
	}
	int res=0;
//	cout<<s<<" ";
	for(int i=1;i<=n;i++)
	{
		res=max(res,dis[i]);
//		cout<<dis[i];
	}
//	cout<<" "<<res<<"\n";
	return res;
}
void solve(){
	cin>>n>>k;
	m.clear();
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[0]=0;
	dfs1(1,0);
//	for(int i=1;i<=n;i++){
//		cout<<sz[i]<<" "<<fa[i]<<" "<<dep[i]<<"\n"; 
//	}
	int ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int g=0;g<k;g++){
				if(sz[i]<g||sz[j]<k-g)continue;
				for(int i=1;i<=n;i++){
					is[i]=0;
				}
				if(dep[j]>dep[i]){
					dfs2(j,fa[j],k-g);
					dfs2(i,fa[i],g);					
				}
				else{
					dfs2(i,fa[i],g);
					dfs2(j,fa[j],k-g);
				}
				int x=check();
				ans=min(ans,x);
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
}


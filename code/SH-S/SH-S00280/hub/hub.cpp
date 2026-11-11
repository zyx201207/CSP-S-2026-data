#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int dep[20],fa[20][20];

void dfs1(int u,vector<vector<int>> &g,vector<bool> &vis){
	vis[u]=0;
	for(auto v:g[u])
		if(vis[v]==1)
			dfs1(v,g,vis);
}
bool check(long long mask,vector<vector<int>> &g,vector<int> &p){
	int cnt=0;
	vector<bool> vis(n+10); 
	for(int i=0;i<n;i++)
		if((mask>>i)&1)
	 		cnt++,p.push_back(i+1),vis[i+1]=1;
	if(cnt!=k) return 0;
//	return 1;
	int i=1;
	for(;i<=n;i++)
		if(vis[i]){
			dfs1(i,g,vis);
			break;
		}
	for(;i<=n;i++)
		if(vis[i]){
			dfs1(i,g,vis);
			break;
		}
	for(;i<=n;i++) if(vis[i]) return 0;
	return 1;
}
int dfs2(int u,int d,int fa,vector<vector<int>> g,int s){
	int ret=-1;
	if(u==d) return s;
	for(auto v:g[u])
		if(v!=fa) ret=max(ret,dfs2(v,d,u,g,s+1));
//	cout<<ret<<'\n';
	return ret;
}
void solve(){
	cin>>n>>k;
	vector<vector<int>> g(n+10);
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y),g[y].push_back(x); 
	}
	int ans=INT_MAX;
	for(long long mask=0;mask<=(1ll<<n)-1;mask++){
		vector<int> p;
		if(!check(mask,g,p)) continue;
//		cout<<111;
		int maxs=0;
		for(int i=1;i<=n;i++){
			int mins=INT_MAX;
			for(auto d:p){
				int ret=dfs2(i,d,-1,g,0);
				if(ret!=-1)
					mins=min(mins,dfs2(i,d,-1,g,0));
			}
			maxs=max(maxs,mins);
		}
		ans=min(ans,maxs);
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c<=3) solve();
//		else if(c==7) solve2();
//		else if(c==13||c==14)solveA();
		else cout<<0<<"\n";
	}
	return 0;
}

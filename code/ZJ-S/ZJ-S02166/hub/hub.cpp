#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
using namespace std;
const int N=5e5+5;
ll _C,_T;
ll n,k;
ll u,v;
vector<int> g[15];



int a[15];

int vis[15];

int vis1[15];
int res0;



void dfs2(int u){
	for(auto v:g[u]){
		if(vis1[v]==-1){
			if(a[v]){
				res0=min(res0,vis1[u]+1);
			}else{
				vis1[v]=vis1[u]+1;
				dfs2(v);
			}
		}
	}
}



void dfs1(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v]&&a[v]) dfs1(v);
	}
}



int ans;
void dfs(int k0){
	if(k0==n+1){
		
		int tmp=0;
		for(int i=1;i<=n;i++) if(a[i]) tmp+=1;
		if(tmp!=k) return;
		
		
		
		int tot=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++) if(!vis[i]&&a[i]) dfs1(i),tot+=1;
		if(tot>2) return;
		
		
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]) continue;
			
			res0=1e9;
			memset(vis1,-1,sizeof vis1);
			vis1[i]=0;
			dfs2(i);
			res=max(res,res0);
		}
		
		
		
		ans=min(ans,res);
		
		return;
	}
	a[k0]=0;
	dfs(k0+1);
	a[k0]=1;
	dfs(k0+1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	ans=1e9;
	dfs(1);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) g[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>_C>>_T;
	while(_T--) solve();
	return 0;
}

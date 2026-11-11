#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
vector<int> e[N];		
int n,k,ans,vis[N],fl[N];

int dfs(int x,int fa,int p) {
	if(vis[x]) return p; 
	for(auto v:e[x]) if(v!=fa) return dfs(v,x,p+1);
}

void dfs2(int x,int fa) {
	fl[x]=1;
	for(auto v:e[x]) if(vis[v] and v!=fa) dfs2(v,x);
}

void solve(int x) {
	if(x==k) {
		int p=0;
		for(int i=1;i<=n;i++) 
			if(vis[i] and !fl[i]) dfs2(i,0),p++;
		if(p>2) return;
		int res=0;
		for(int i=1;i<=n;i++) 
			res=max(dfs(i,0,0),res);
		ans=min(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i])continue;
		vis[i]=1;
		solve(x+1);
		vis[i]=0;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ans=1e9+7;
	int c,t;
	cin>>c>>t;
	while(t--) {
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		solve(0);
		cout<<ans<<"\n";
	}
	return 0;
}


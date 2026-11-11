#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,a[10010],ans=INT_MAX,vis[10001];
vector<int> g[10011];
struct s{
	int x,fa,b;
};
int sol(){
	int res=0;
	for(int p=1;p<=n;p++){
	    
		queue<s> q;
		q.push({p,-1,0});
		while(a[p]!=1){
			int x=q.front().x,f=q.front().fa,b=q.front().b;
			q.pop();
			if(a[x]==1){
				res=max(res,b);
				break;
			}
			
			for(int i=0;i<g[x].size();i++){
				if(g[x][i]==f) continue;
				q.push({g[x][i],x,b+1});
			}
		}
	}
	return res;
}
int dfss(int y){
	int res=1;
	vis[y]=1;
	for(int i=0;i<g[y].size();y++){
		if(vis[g[y][i]]==1||a[g[y][i]]==0) continue;
		res+=dfss(g[y][i]);
	}
	return res;
}
bool pa(int l){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	int r=dfss(l);
	if(r==k) return 1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&a[i]==1){
            return ((r+dfss(i))==k);
		}
	}
}

void dfs(int d,int x){
	if(x==k){
	    if(pa(d-1)){
	        ans=min(ans,sol());
		}
		return ;
	}
	if(n-d+1<x) return ;
	a[d]=1;
	dfs(d+1,x+1);
	a[d]=0;
	dfs(d+1,x);
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}

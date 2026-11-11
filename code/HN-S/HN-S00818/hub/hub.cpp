#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5,M=48;
int c,_,n,k;
int ans;
int a[N],fa[N],dp[N][M],dep[N];
struct EDGE{
	int u,v;
}e[N];
vector<int> G[N];

int fnd(int x){
	return (x==fa[x]?x:fa[x]=fnd(fa[x]));
}
void init(int cur,int f){
	dep[cur]=dep[f]+1;
	dp[cur][0]=f;
	for(int i=1;(1<<i)<=dep[cur];i++)
		dp[cur][i]=dp[dp[cur][i-1]][i-1];
	for(int i:G[cur]){
		if(i==f)
			continue;
		init(i,cur);
	}
}
int get(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=34;i>=0;i--)
		if(dep[dp[x][i]]>=dep[y])
			x=dp[x][i];
	if(x==y)
		return x;
	for(int i=34;i>=0;i--)
		if(dp[x][i]!=dp[y][i])
			x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}
void dfs(int cur){
	if(cur==n+1){
		int tot=0;
		for(int i=1;i<=n;i++)
			fa[i]=i,tot+=a[i];
		for(int i=1;i<n;i++){
			if(a[e[i].u]&&a[e[i].v]){
				int u=fnd(e[i].u),v=fnd(e[i].v);
				if(u!=v) fa[u]=v;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(a[i]&&fnd(i)==i)
				cnt++;
		if(cnt<=2&&tot==k){
			int mx=-1e18;
			for(int i=1;i<=n;i++){
				int mn=1e18;
				for(int j=1;j<=n;j++){
					if(a[j]){
						int lca=get(i,j);
						mn=min(mn,dep[i]+dep[j]-2*dep[lca]);
					}
				}
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		return;
	}
	a[cur]=0;
	dfs(cur+1);
	a[cur]=1;
	dfs(cur+1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		G[i].clear(); 
	ans=1e18;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		e[i]={u,v};
	}
	init(1,0);
	dfs(1);
	cout<<ans<<'\n';
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>_;
	while(_--)
		solve();
	return 0;
}


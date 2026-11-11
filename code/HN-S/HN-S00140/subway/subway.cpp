#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxx=1e3+10;
struct node{
	int line,walk;
};
vector<node> G[maxx];
vector<int> E[maxx];
int w[maxx],a[maxx][maxx],t[maxx][maxx],k[maxx];
bool vis[maxx];
int c,n,m,d,q,ans,x,y;
void dfs(int cur,int l,int t,int fa){
	if(cur==y){
		ans=min(ans,t);
		return;
	}
	int ow=0;
	for(auto iter:G[cur]){
		if(iter.line==l){
			ow=iter.walk;
			break;
		}
	}
	for(auto iter:G[cur]){
		if(iter.line==l) continue;
		int line=iter.line;
		int walk=iter.walk;
		dfs(cur,l,t+walk+ow,fa);	
	}
	for(auto nxt:E[cur]){
		if(nxt==fa) continue;
		if(vis[nxt]==1) continue;
		vis[nxt]=1;
		dfs(nxt,l,t,cur);
		vis[nxt]=0;
	}
	return;
}
void solve(int x,int y){
	int t=w[x]+w[y];
	ans=1e18;
	for(auto iter:G[x]){
		dfs(x,iter.line,0,0);
	} 
	cout<<ans+t<<"\n";
	return;
}
signed main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			E[a[i][j]].push_back(a[i][j-1]);
			E[a[i][j-1]].push_back(a[i][j]);
			G[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		solve(x,y);
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
const int INF=2e6+10;
int c,n,k,res=INF;
bool vis[N],book[N];
vector<int> g[N];
void dfs(int x){
	book[x]=true;
	for(int i=0;i<g[x].size();i++){
		if(book[g[x][i]]) continue;
		if(!vis[g[x][i]]) continue;
		dfs(g[x][i]);
	}
}
int dfs2(int x,int sum){
	book[x]=true;
	if(vis[x]) return sum;
	int best=INF;
	for(int i=0;i<g[x].size();i++){
		if(book[g[x][i]]) continue;
		best=min(best,dfs2(g[x][i],sum+1));
	}
	return best;
}
void solve(){
	cin>>n>>k;res=INF;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=0;i<(1<<n);i++){
		int num=0,best=0,sum=0;
		for(int j=1;j<=n;j++)vis[j]=(i>>(j-1))&1,book[j]=0;
		for(int j=1;j<=n;j++) if(vis[j]) sum++;
		if(sum!=k) continue;
		for(int j=1;j<=n;j++) if(!book[j] && vis[j]) dfs(j),num++;
		if(num>2 || num==0) continue;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			for(int k=1;k<=n;k++) book[k]=0;
			best=max(best,dfs2(j,0));
		}
		res=min(res,best);
	}	
	cout<<res<<"\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

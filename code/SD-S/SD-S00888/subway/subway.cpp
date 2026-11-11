#include<bits/stdc++.h>
#define int long long
using namespace std;
struct E{
	int v,w;
};
int cc,n,m,d,q,w[500510],k,a,t,s,e,ans;
bool vis[500510];
vector<E> g[500510];

void dfs(int x,int dis){
	if(x==e){
		ans=min(ans,dis);
		return;
	}
	for(int i=0;i<g[x].size();i++){
		if(!vis[g[x][i].v]){
			vis[g[x][i].v]=1;
			dfs(g[x][i].v,dis+g[x][i].w);
			vis[g[x][i].v]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	while(q--){
		ans=0x3f3f3f3f3f3f3f3f;
//		bool vis[500510]={0};
		memset(vis,0,sizeof(vis));
		cin>>s>>e;
		dfs(s,0);
		cout<<ans+w[s]+w[e]<<'\n';
	}
	return 0;
}
/*
16:10 监考老师终于开窗户了
差点被闷死 
 
暴力DFS 
预计48pts 
*/

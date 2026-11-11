#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,s,e,ans;
int w[150010],k[510];
bool vis[150010];
vector<int> a[510],t[510],g[150010];
map<pair<int,int>,int> mp;
void dfs(int x,int sum,int lst){
	if(sum>=ans) return ;
	if(x==e){
		sum+=t[lst][mp[{x,lst}]];
		ans=min(ans,sum);
		return ;
	}
	for(int i=0;i<g[x].size();i++){
		int id=g[x][i];
		int nxt=mp[{x,id}]+1;
		if(nxt==k[id]) nxt=0;
		if(id==lst){
			if(vis[a[id][nxt]]) continue;
			vis[a[id][nxt]]=1;
			dfs(a[id][nxt],sum,lst);
			vis[a[id][nxt]]=0;
		}
		else{
			if(vis[a[id][nxt]]) continue;
			vis[a[id][nxt]]=1;
			int y=a[id][nxt];
			dfs(y,sum+(lst?t[lst][mp[{x,lst}]]:0)+t[id][mp[{x,id}]],id);
			vis[y]=0;
		}
	}
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			g[x].push_back(i);
			mp[{x,i}]=j-1;
		}
	}
	int x,y;
	while(q--){
		cin>>s>>e;
		ans=1e18;
		for(int i=1;i<=m;i++) vis[i]=0;
		dfs(s,0,0);
		cout<<ans+w[s]+w[e]<<"\n";
	}
	return 0;
}

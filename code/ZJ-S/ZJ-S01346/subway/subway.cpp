#include<bits/stdc++.h>
#define int long long
#define endl '\n';
using namespace std;

int c,n,m,d,q,w[500010],k[510],vis[500010],ans;
vector<pair<int,int> >G[500510];
void dfs(int x,int v,int cnt){
	if(cnt>=ans)return;
	if(x==v){
		ans=min(ans,cnt);
		return;
	}
	for(auto y:G[x]){
		if(!vis[y.first]){
			vis[y.first]=1;
			dfs(y.first,v,cnt+y.second);
			vis[y.first]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){//k[i]<=20
			int a,t;
			cin>>a>>t;
			G[m+i].emplace_back(a,w[a]);
			G[a].emplace_back(m+i,t);//d<=20,zhe`shi`yi`ge`ju`da`de`tu`po`dian`
		}
	}
	while(q--){
		ans=1e18;
		int u,v;
		cin>>u>>v;
		memset(vis,0,sizeof(vis));
		//er`fen`tu`de`xing`zhi
		dfs(u,v,0);
		cout<<ans<<endl;
	}
	
//	for(int i)
	return 0;
}


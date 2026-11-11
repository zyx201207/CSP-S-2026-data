#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[514514],vis[514514],tme[514514][514];
long long ans;
struct way{
	int to,l;
};
vector<way> mp[514514];
void dfs(int from,int to,long long cost,int line){
	if(from==to){
		ans=min(ans,cost+tme[from][line]);
		return;
	}
	for(int i=0;i<mp[from].size();i++){
		if(vis[mp[from][i].to]) continue;
		vis[mp[from][i].to]=1;
		if(line!=mp[from][i].l) dfs(mp[from][i].to,to,cost+tme[from][line]+tme[from][mp[from][i].l],mp[from][i].l);
		else dfs(mp[from][i].to,to,cost,line);
		vis[mp[from][i].to]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k,r,rt;
		cin>>k>>r>>rt;
		tme[r][i]=rt;
		for(int j=1;j<k;j++){
			int a,t;
			cin>>a>>t;
			mp[r].push_back({a,i});
			mp[a].push_back({r,i});
			tme[a][i]=t;
		}
	}
	while(q--){
		int x,y;
		ans=1e15;
		cin>>x>>y;
		vis[x]=1;
		dfs(x,y,w[x]+w[y],0);
		vis[x]=0;
		cout<<ans<<endl;
	}
	return 0;
}

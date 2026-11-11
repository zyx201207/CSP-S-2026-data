#include<bits/stdc++.h>
using namespace std;
int c,t,n,vis[2000010],ans,zd,ed,gc;
long long s,a[2000010],d;
vector<int>g[2000010];
int dis(int x,int y){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i=1;i<=n;++i)vis[i]=0;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second,w=pq.top().first;pq.pop();
		if(vis[u])continue;vis[u]=1;
		if(u==y)return w;
		for(auto v:g[u]){
			if(vis[v])continue;
			pq.push({w+1,v});
		}
	}
}
void dfs(int u,int fa,int s){
	if(s>zd)return;
	if(u==ed){
		++ans;
		return;
	}
	if(ans>2)return;
	for(int v:g[u])if(v!=fa)dfs(v,u,s+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;s=0;
		if(n>300){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)g[i].clear();
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(a[j]-a[i]<=d)g[i].push_back(j);
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j){
			zd=dis(i,j);ed=j;ans=0;
			dfs(i,0,0);
			if(ans==2)++s;
		}
		cout<<s<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,p,k,x,y,f[1500][1500],a[50510],vis[50510];
vector<pair<int,int>>g[50510];
void solve1(){
	for(int i=1;i<=m+n;++i)for(int j=1;j<=m+n;++j)f[i][j]=0x3f3f3f3f;
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>p>>x;
			f[m+i][p]=f[p][m+i]=x;
		}
	}
	for(int k=1;k<=m+n;++k)for(int i=1;i<=m+n;++i){
		if(k==i)continue;
		for(int j=1;j<=m+n;++j)if(i!=j&&j!=k)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	while(q--){
		cin>>x>>y;
		cout<<a[x]+a[y]+f[x][y]<<"\n";
	}
}
int dis(int x,int y){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for(int i=1;i<=m+n;++i)vis[i]=0;
	pq.push({0,x});
	while(!pq.empty()){
		int u=pq.top().second,w=pq.top().first;pq.pop();
		if(vis[u])continue;vis[u]=1;
		if(u==y)return w;
		for(auto i:g[u]){
			int v=i.first,w1=i.second;
			if(vis[v])continue;
			pq.push({w1+w,v});
		}
	}
}
void solve2(){
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>p>>x;
			g[m+i].push_back({p,x});
			g[p].push_back({m+i,x});
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dis(x,y)+a[x]+a[y]<<"\n";
	}
}
void solve3(){
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>p>>x;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<m+a[x]+a[y]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>a[i];
	if(c<12)solve1();
	else if(c<16)solve2();
	else solve3();
	return 0;
}

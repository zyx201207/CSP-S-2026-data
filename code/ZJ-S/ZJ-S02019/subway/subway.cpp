#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
我们可以认为一条线为一个超级节点
一个站厅最多有d条边 
综上(i,j)等价于W[i]+W[j]+min(dis[i能达到的Super Node][j能达到的Super Node]+(i->line)+(j->line)) 在线处理：所以单次Q为O（1） 
如何求G，显然枚举地铁站 当地铁站能到达Super Node时 直接make边 
然后n次dijkstra即可 
*/
int n,m,d,q;
int dis[505][505];
vector<pair<int,int>>ed[505];
bool vis[505];
vector<vector<int>>line;//地铁站有关的Super Node ID 
vector<int>w;
vector<int>a[505],t[505];//尊重题面 
void dij(int s){
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<ed[u].size();i++){
			int v=ed[u][i].first;
			int w=ed[u][i].second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
	return;
}
int f9178(int nodeid,int stid){
	return t[nodeid][lower_bound(a[nodeid].begin(),a[nodeid].end(),stid)-a[nodeid].begin()];
}
int Get(int x,int y){
//	cout<<x<<"->"<<y<<'\n';
	int res=INT_MAX;
	for(auto i:line[x]){
		for(auto j:line[y]){
			res=min(res,dis[i][j]+f9178(i,x)+f9178(j,y));
//			cout<<i<<" "<<j<<' '<<dis[i][j]<<" "<<f9178(i,x)+f9178(j,y)<<'\n';
		}
	}
	return w[x]+w[y]+res;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	int C;
	cin>>C;
	cin>>n>>m>>d>>q;
	line.resize(m+1);w.resize(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		a[i].resize(k+1);t[i].resize(k+1);
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			line[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		int le=line[i].size();
		int u,v;
		for(int j=0;j<le;j++){
			for(int k=j+1;k<le;k++){
				u=line[i][j],v=line[i][k];
				ed[u].push_back({v,f9178(u,i)+f9178(v,i)});
				ed[v].push_back({u,f9178(u,i)+f9178(v,i)});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<Get(x,y)<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
struct node{
	int v,w;
};
vector<int>vec[N];
vector<node>vec1[N];
int t[505][N];
vector<int> a[505];
bool vis[N];
int c,n,m,d,q;
int W[N];
int dis[N];
void bl(){
	//做n条地铁线路之间的最短路 
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int k=j+1;k<vec[i].size();k++){
				vec1[vec[i][j]].push_back({vec[i][k],t[vec[i][j]][i]+t[vec[i][k]][i]});
				vec1[vec[i][k]].push_back({vec[i][j],t[vec[i][j]][i]+t[vec[i][k]][i]});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
		fill(dis,dis+n+1,1e18);
		fill(vis,vis+n+1,0);
		for(int i=0;i<vec[x].size();i++){
			q.push({t[vec[x][i]][x],vec[x][i]});
			dis[vec[x][i]]=t[vec[x][i]][x];
		}
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=true;
			for(auto f:vec1[u]){
				int v=f.v,w=f.w;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		}
		int ans=1e18;
		for(int i=0;i<vec[y].size();i++){
			ans=min(ans,dis[vec[y][i]]+t[vec[y][i]][y]);
		}
		cout<<W[x]+W[y]+ans<<'\n';
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x>>t[i][j];
			a[i].push_back(x);
			vec[x].push_back(i); 
		}
	}
	if(n==1){//只有一条线路不可能要换线 
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<W[x]+W[y]<<'\n';//直接输出 
		}
		return 0; 
	}
	if(n==2){
		bl();
		return 0;
	}
	bl();
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
using namespace std;
const int mx=1e4+5;
const int inf=1e9+7;
int c,n,d,x[mx],ans,dist[305][305],ds[305][305];
int vis[305],dis[305];
vector<int> e[mx];
void dij(int st){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
//	vector<int> vis(n+1,0);
//	vector<int> dis(n+1,inf);
	dis[st]=0;
	priority_queue<pi,vector<pi>,greater<pi> > q;
	q.push({0,st});
	while(!q.empty()){
	//	ans++;
		pi u=q.top(); q.pop();
	//	if(u.second==ed) sum++;
		if(vis[u.second]) continue;
		vis[u.second]=1;
		for(int v:e[u.second]){
			if(dis[v]>dis[u.second]+1){
				dis[v]=dis[u.second]+1;
			//	dist[st][v]=1;
				q.push({dis[v],v});
			}
		//	else if(dis[v]==u.first+1) dist[st][v]++;
		}
	}
//	cout<<st<<":";
	for(int i=1;i<=n;i++){
		ds[st][i]=dis[i];
	//	cout<<ds[st][i]<<' ';
	}
//	cout<<'\n';
}
void dij1(int st){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	int inf=dis[st];
	dis[st]=0;
	priority_queue<pi,vector<pi>,greater<pi> > q;
	q.push({0,st});
	while(!q.empty()){
		pi u=q.top(); q.pop();
		if(dis[u.second]==ds[st][u.second]) dist[st][u.second]++;
	//	else if(ds[st][st]+dis[u.second]==ds[st])
	//	if(vis[u.second]) continue;
	//	vis[u.second]=1;
		for(int v:e[u.second]){
			
			if(dis[v]>=dis[u.second]+1){
				dis[v]=dis[u.second]+1;
				q.push({dis[v],v});
			}
		}
	}
}
void solve(){
	memset(dist,0,sizeof dist);
	memset(ds,0,sizeof ds);
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(llabs(x[j]-x[i])<=d){
				e[i].push_back(j);
				e[j].push_back(i);
			//	cout<<i<<"->"<<j<<'\n';
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		dij(i);
	}
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i==k||i==j||k==j) continue;
//				if()
//			}
//		}
//	}
	for(int i=1;i<=n;i++) dij1(i);
	int cnt=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dist[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dist[i][j]==2){
			//	cout<<i<<" "<<j<<'\n';
				cnt++;
			} 
		}
	//	cout<<'\n';
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++) e[i].clear();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate3.in","r",stdin);
//	freopen("q.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
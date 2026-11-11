#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int c,n,m,d,q1,w[N],k,a,t,dist[505][505],vis[505],x,y;
vector<pair<int,int>>v[N],E[N];
priority_queue<pair<int,int>>q;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto now:v[i]){
			for(auto now1:v[i]){
				if(now.first==now1.first) continue;
				E[now.first].push_back({now1.first,now.second+now1.second});
				E[now1.first].push_back({now.first,now.second+now1.second});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		q.push({0,i});
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		dist[i][i]=0;
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto now:E[u]){
				if(dist[i][now.first]>dist[i][u]+now.second){
					dist[i][now.first]=dist[i][u]+now.second;
					q.push({-dist[i][now.first],now.first}); 
				}
			} 
		}
	}
	for(int i=1;i<=q1;i++){
		cin>>x>>y;
		int ans=1e18;
		for(auto now:v[x]){
			for(auto now1:v[y]){
				ans=min(now.second+now1.second+dist[now.first][now1.first],ans);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

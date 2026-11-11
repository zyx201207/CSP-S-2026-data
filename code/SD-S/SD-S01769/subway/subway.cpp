#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qu,w[500010],k[510],dist[1010][1010],dis[1010];
vector<int> a[510],t[510];
struct node{
	int v;
	int cost;
};
bool vis[1010];
vector<node> e[1010];
priority_queue<pair<int,int> > q;
set<int> dian[500010],edge[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+9);
		t[i].resize(k[i]+9);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	if(c>=7&&c<=11){
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=n;i++){
			e[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
			e[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
		}
		for(int i=1;i<=m;i++){
			memset(dis,0x3f,sizeof dis);
			memset(vis,0,sizeof vis);
			while(!q.empty())q.pop();
			dis[i]=0;
			q.push({0,i});
			while(!q.empty()){
				int x=q.top().second;
				q.pop();
				if(vis[x])continue;
				vis[x]=1;
				for(int j=0;j<e[x].size();j++){
					int y=e[x][j].v;
					if(dis[y]>dis[x]+e[x][j].cost){
						dis[y]=dis[x]+e[x][j].cost;
						q.push({-dis[y],y});
					}
				}
			}
			for(int j=1;j<=m;j++){
				dist[i][j]=min(dis[j],dist[i][j]);
				dist[j][i]=min(dis[j],dist[j][i]);
			}
		}
		int x,y;
		for(int i=1;i<=qu;i++){
			cin>>x>>y;
			cout<<dist[x][y]+w[x]+w[y]<<endl;
		}
	}
	if(c>=12&&c<=19){
		int T=t[1][1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				dian[a[i][j]].insert(i);
			}
		}
		for(int i=1;i<=m;i++){
			for(auto x:dian[i]){
				for(auto y:dian[i]){
					edge[x].insert(y);
					edge[y].insert(x);
				}
			}
		}
		memset(dist,0x3f,sizeof dist);
		for(int i=1;i<=n;i++){
			memset(dis,0x3f,sizeof dis);
			memset(vis,0,sizeof vis);
			while(!q.empty())q.pop();
			dis[i]=0;
			q.push({0,i});
			while(!q.empty()){
				int x=q.top().second;
				q.pop();
				if(vis[x])continue;
				vis[x]=1;
				for(auto y:edge[x]){
					if(dis[y]>dis[x]+T*2){
						dis[y]=dis[x]+T*2;
						q.push({-dis[y],y});
					}
				}
			}
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dis[j],dist[i][j]);
				dist[j][i]=min(dis[j],dist[j][i]);
			}
		}
		int x,y;
		for(int j=1;j<=qu;j++){
			int ans=1e17;
			cin>>x>>y;
			for(auto l:dian[x]){
				for(auto r:dian[y]){
					ans=min(ans,dist[l][r]);
				}
			}
			cout<<ans+w[x]+w[y]+T*2<<endl;
		}
	}
	return 0;
}


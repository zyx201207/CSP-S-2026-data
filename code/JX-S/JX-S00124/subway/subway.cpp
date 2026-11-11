#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq;
vector<pair<long long,long long> >g[500505];
map<pair<long long,long long>,long long>f;
long long w[500505];
priority_queue<pair<long long,long long> >q;
long long dis[500505];
bool vis[500505];
void dj(int s){
	for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		long long x=q.top().second;
		q.pop();
		if(vis[x])continue;
		else vis[x]=1;
		//cout<<x<<'\n';
		for(int i=0;i<(int)g[x].size();i++){
			long long yy=g[x][i].second,xx=g[x][i].first;
			if(dis[xx]>dis[x]+yy){
				dis[xx]=dis[x]+yy;
				q.push({-dis[xx],xx});
			}
		}
	}
	for(int i=1;i<=n;i++)f[{s,i}]=dis[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			g[i+m].push_back({u,v});
			g[u].push_back({i+m,v});
		}
	}
	n+=m;
	while(qq--){
		int u,v;
		cin>>u>>v;
		if(f[{u,v}]!=0){
			cout<<w[u]+w[v]+f[{u,v}]<<'\n';
			continue;
		}else if(f[{v,u}]!=0){
			cout<<w[u]+w[v]+f[{v,u}]<<'\n';
			continue;
		}else{
			dj(u);
			cout<<w[u]+w[v]+f[{u,v}]<<'\n';
		}
	}
	return 0;
}

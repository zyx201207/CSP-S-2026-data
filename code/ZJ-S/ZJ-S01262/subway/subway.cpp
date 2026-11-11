#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[100005],k[100005],a[505][505],t[505][505],l,r,ans=1e18,dis[100005];
bool vis[305];
vector<pair<int,int>> node[305];
void dij(){
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[l]=0;
	pq.push({0,l});
	while(pq.size()){
		int u=pq.top().second;
		//cout<<u<<' '<<dis[u]<<"\n";
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto s:node[u]){
		//	cout<<s.first<<"\n";
			for(int j=1;j<=k[s.first];j++){
				int i=s.first,qqq=s.second;
				int lt=t[i][j];
				if(t[i][qqq]+t[i][j]+dis[u]<dis[a[i][j]]){
					dis[a[i][j]]=t[i][qqq]+t[i][j]+dis[u];
					pq.push({dis[a[i][j]],a[i][j]});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			node[a[i][j]].push_back({i,j});
		}
	}
		for(int i=1;i<=q;i++){
			cin>>l>>r;
			dij();
			cout<<w[l]+w[r]+dis[r]<<'\n';
		}
	return 0;
}

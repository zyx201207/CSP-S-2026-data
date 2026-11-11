#include<bits/stdc++.h>
#define ll long long//!!!
#define pii pair<ll,int>
using namespace std;
int c,n,m,d,q,w[500005],k[505],x,y;
ll dis[1005][1005];
vector<int> a[505],t[505];
vector<pii> g[500005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
				g[a[i][l]].push_back({a[i][j],t[i][j]+t[i][l]});
			}
		}
	}
	for(int s=1;s<=m;s++){
		pq.push({0,s});
		vis[s]=1;
		for(int i=1;i<=m;i++)dis[s][i]=1e18,vis[i]=0;
		dis[s][s]=0;
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(pii v:g[u]){
				if(dis[s][v.first]>dis[s][u]+v.second){
					dis[s][v.first]=dis[s][u]+v.second;
					pq.push({dis[s][v.first],v.first});
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

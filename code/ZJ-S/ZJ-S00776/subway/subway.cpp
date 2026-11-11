#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
ll a[500005],t[500005];
vector<pair<ll,ll> >mp[500005];
ll way[1005][1005];
bool vis[500005];
bool vis2[500005];
void dij(int s,int e){
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
	q.push({0,s});
	way[s][s]=0;
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		if(vis[p.second])continue;
		vis[p.second]=1;
		for(auto i:mp[p.second]){
			if(way[s][i.second]>way[s][p.second]+i.first){
				way[s][i.second]=way[s][p.second]+i.first;
			//	way[i.second][s]=way[s][i.second];
				q.push({way[s][i.second],i.second});
			}
		}
	}
	//cout<<way[e]+w[s]+w[e]<<'\n';
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(way,0x3f,sizeof(way));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				mp[a[x]].push_back({t[x]+t[y],a[y]});
				mp[a[y]].push_back({t[x]+t[y],a[x]});
			}
		}
	}

	for(int i=1;i<=q;i++){
		int h,u;
		cin>>h>>u;
		if(vis2[h]){
			cout<<way[h][u]+w[h]+w[u]<<'\n';
		}
		else if(vis2[u]){
			cout<<way[u][h]+w[h]+w[u]<<'\n';
		}
		else {
			dij(h,u);
			cout<<way[h][u]+w[h]+w[u]<<'\n';
			vis2[h]=1;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct str{
	ll w;
	int id;
	bool operator <(const str &x)const{
		return x.w<w;
	}
};
int c,n,m,d,q;
ll dis[1505][1505];
int w[1505];
bool vis[1505];
vector<pair<int,int>> edge[1505];
ll dijstra(int x){
	priority_queue<str> ma;
	for(int i = 1;i<n+m+1;i++){
		dis[x][i] = LLONG_MAX;
	}
	dis[x][x] = 0;
	memset(vis,0,sizeof vis);
	ma.push({0,x});
	for(int op = 1;op<m+n+2;op++){
		ll lx;
		int lid;
		int pl = true;
		while(ma.size()){
			pl = false;
			str lkm = ma.top();
			ma.pop();
			lx = lkm.w;
			lid = lkm.id;
			if(!vis[lid]){
				break;
			}
		}
		if(pl) break;
		vis[lid] = true;
		for(int i = 0;i<edge[lid].size();i++){
			int ny = edge[lid][i].first;
			int nw = edge[lid][i].second;
			if(vis[ny]) continue;
			ll lw = lx+nw;
			if(dis[x][ny]>lw){
				dis[x][ny] = lw;
				ma.push({lw,ny});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		int id = m+i;
		for(int j = 0;j<k;j++){
			int ai,ti;
			cin>>ai>>ti;
			edge[id].push_back({ai,ti});
			edge[ai].push_back({id,ti});
		}
	}
	for(int i = 1;i<=m;i++){
		dijstra(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<(dis[x][y]+w[x]+w[y])<<'\n';
	}
	return 0;
}
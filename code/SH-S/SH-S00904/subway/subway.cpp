#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int id,dt,ti;//当前站台/上次坐的车/时间 
};
int csdbh,n,m,d,q,w[500009],k[509],a[502][50002],t[502][50002],xx[502][50002];
vector<pair<int,int> > zt[500009];
bool vis[500009];
int bfs(int xr,int yr){
	queue<node> q;
	for(auto p:zt[xr])
		q.push({xr,p.first,t[p.first][p.second]});
	vis[xr]=1;
	while(!q.empty()){
		node head=q.front();
		q.pop();
		int id=head.id,dt=head.dt,ti=head.ti;
		if(id==yr)
			return ti+t[dt][xx[dt][yr]];
//		cout<<id<<" "<<dt<<" "<<ti<<endl<<endl;	
		for(auto p:zt[id]){//经过这个站台的车
//			cout<<p.first<<"   "<<p.second<<endl; 
			for(int j=1;j<=k[p.first];j++){//对于这辆车的每个站点 
				if(p.first==dt){//同一辆 
					if(vis[a[p.first][j]]==0){
						vis[a[p.first][j]]=1;
						q.push({a[p.first][j],dt,ti});
//						cout<<a[p.first][j]<<" "<<dt<<" "<<ti<<endl;
					}
				}
				else{//不同一辆
					if(vis[a[p.first][j]]==0){
						vis[a[p.first][j]]=1;
						q.push({a[p.first][j],p.first,ti+t[dt][id]+t[p.first][p.second]});
//						cout<<a[p.first][j]<<" "<<p.first<<" "<<ti<<" "<<t[dt][id]<<" "<<t[p.first][p.second]<<"----------------"<<endl;
					}
				}
			}
		}
	}
	return -1;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>csdbh>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			xx[i][a[i][j]]=j;
			zt[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		memset(vis,0,sizeof vis);
		int xr,yr;
		cin>>xr>>yr;
		cout<<bfs(xr,yr)+w[xr]+w[yr]<<endl;
//		cout<<bfs(xr,yr)<<" "<<w[xr]+w[yr]<<endl;
	}
	return 0;
}

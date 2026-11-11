#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,T; 
int w[505];
int vis[505];
int k[500005];
long long dis[505][505];
int ax[505],tx[505];
map<pair<int,int>,long long> t;//对于i号点j号线 
vector<pair<int,int> > v[505];  
vector<int> xu[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ax[j]>>tx[j];
			xu[ax[j]].push_back(i);
			t[{ax[j],i}]=tx[j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				v[ax[j]].push_back({ax[l],i});
				v[ax[l]].push_back({ax[j],i});
			}
		}
	}
	priority_queue<pair<long long,pair<int,int> >,vector<pair<long long,pair<int,int> > >,greater<pair<long long,pair<int,int> > > > q;
	for(int chu=1;chu<=m;chu++){
		memset(vis,0,sizeof(vis));
		for(int i=0;i<xu[chu].size();i++){
			q.push({t[{chu,i+1}],{chu,xu[chu][i]}});
		}
		for(int i=1;i<=m;i++) dis[chu][i]=LONG_LONG_MAX;
		dis[chu][chu]=0;
		while(!q.empty()){
			long long u=q.top().first,vv=q.top().second.first,x=q.top().second.second;//步行时间，站点，几号线 
			q.pop();
			if(vis[vv]&&vv!=chu) continue;
			vis[vv]=1;
			//if(chu==2) cout<<u<<" "<<vv<<" "<<x<<'\n';
			for(int i=0;i<v[vv].size();i++){
				if(x!=v[vv][i].second){
					if(u+t[{vv,x}]+t[{vv,v[vv][i].second}]+t[{v[vv][i].first,v[vv][i].second}]<dis[chu][v[vv][i].first]){
						dis[chu][v[vv][i].first]=u+t[{vv,x}]+t[{vv,v[vv][i].second}]+t[{v[vv][i].first,v[vv][i].second}];
						q.push({dis[chu][v[vv][i].first],{v[vv][i].first,v[vv][i].second}});
					}
				}
				else{
					if(vv==chu&&u+t[{v[vv][i].first,x}]<dis[chu][v[vv][i].first]){
						dis[chu][v[vv][i].first]=u+t[{v[vv][i].first,x}];
						q.push({dis[chu][v[vv][i].first],{v[vv][i].first,x}});
					}
					else if(u+t[{v[vv][i].first,x}]-t[{vv,x}]<dis[chu][v[vv][i].first]){
						dis[chu][v[vv][i].first]=u+t[{v[vv][i].first,x}]-t[{vv,x}];
						q.push({dis[chu][v[vv][i].first],{v[vv][i].first,x}});
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			dis[chu][i]=dis[chu][i]+w[chu]+w[i];
		}
		dis[chu][chu]=0;
	}
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]<<'\n';
	}
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5145;
const ll inf=1e18;
int c,n,m,d,T;
int b[N];
vector<pair<int,int>>g[N];
vector<pair<int,int>>EA[N];
ll dis[N];
ll dist[514][514];
int v[N];
void dj(int stt){
	memset(v,0,sizeof(v));
	memset(dis,0x3f,sizeof(dis));
	dis[stt+m]=0;
	priority_queue<pair<int,int>>q;
	q.push({0,stt+m});
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(auto i:g[x]){
			int y=i.first,w=i.second;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				if(y>m){
					dist[y-m][stt]=min(dist[y-m][stt],dis[y]);
					dist[stt][y-m]=min(dist[stt][y-m],dis[y]);
				}
				q.push({-dis[y],y});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			g[m+i].push_back({u,w});
			g[u].push_back({m+i,w});
			EA[u].push_back({i,w+b[u]});
		}
	}
	
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int i=1;i<=n;i++){
		dj(i);
	}
	
	while(T--){
		int st,ed;
		cin>>st>>ed;
		ll ans=inf;
		for(auto i:EA[st]){
			for(auto j:EA[ed]){
				int x=i.first,y=j.first;
				ll w1=i.second,w2=j.second;
				ans=min(ans,w1+w2+dist[x][y]);
//				cout<<st<<" "<<ed<<" "<<x<<" "<<y<<" "<<dist[x][y]<<"\n";
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//WSY
//non terrae plus ultra

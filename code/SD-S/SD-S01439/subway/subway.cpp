#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,k,cnt;
long long dist[500010],w[500010],vis[500010],y;
vector<pair<int,long long>> v[500010];
vector<long long> t[510];
unordered_map<int,int> cn[510],a[510];
void dij(){
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> h;
	for(int i=1;i<=cnt+2;i++) dist[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	h.push({0,cnt+1});
	dist[cnt+1]=0;
	while(!h.empty()){
		auto t=h.top();
		h.pop();
		if(vis[t.second]) continue;
		vis[t.second]=1;
		for(auto i:v[t.second]){
			if(dist[i.first]>dist[t.second]+i.second){
				dist[i.first]=dist[t.second]+i.second;
				h.push({dist[i.first],i.first});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int last=0;
		cin>>last>>y;
		a[i][last]=++cnt;
		t[i].push_back(y);
		cn[i][last]=0;
		for(int j=2;j<=k;j++){
			cin>>x>>y;
			++cnt;
			v[cnt-1].push_back({cnt,0});
			v[cnt].push_back({cnt-1,0});
			a[i][x]=cnt;
			t[i].push_back(y);
			cn[i][x]=j-1;
		}
	}
	for(int z=1;z<=m;z++){
		for(int i=1;i<=n;i++){
			if(cn[i].count(z)){
				for(int j=i+1;j<=n;j++){
					if(cn[j].count(z)){
						v[a[i][z]].push_back({a[j][z],t[i][cn[i][z]]+t[j][cn[j][z]]});
						v[a[j][z]].push_back({a[i][z],t[i][cn[i][z]]+t[j][cn[j][z]]});
					}
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;
		v[cnt+1].clear();
		for(int i=1;i<=n;i++)v[cnt+1].push_back({a[i][x],w[x]+t[i][cn[i][x]]});
		for(int i=1;i<=n;i++)v[a[i][y]].push_back({cnt+2,w[y]+t[i][cn[i][y]]});
		dij();
		cout<<dist[cnt+2]<<"\n"; 
		for(int i=1;i<=n;i++) v[a[i][y]].pop_back();
	}
	return 0;
}


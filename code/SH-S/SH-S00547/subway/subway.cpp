#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 505005; 
const ll inf = 4e18;
//const int maxq = 1e5+10;
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > p;
struct ed{
	ll to,v;
};
vector<ed> e[maxn];
//int qu[maxq],qv[maxq];
ll dis[maxn];
int c,n,m,d,q;

void dfs(int start,int end){
	dis[start]=0;
	int k,value;
	for(auto ee:e[start]){
		p.push({ee.v,ee.to});
		dis[ee.to]=ee.v;
	}
	while(!p.empty()){
		value=p.top().first;
		k=p.top().second;
		p.pop();
		if(value>dis[k]) continue;
		for(auto ee:e[k]){
			if(ee.to==k) continue;
			if(dis[ee.to]>dis[k]+ee.v){
				dis[ee.to]=dis[k]+ee.v;
				p.push({dis[ee.to],ee.to});
			}
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;// c编号 n线路 m地铁站 d每站最多 q出行计划数 
	int w,x,y;
	for(int i=1;i<=m;i++){
		cin>>w;
		e[i].push_back({i+m,w});
		e[i+m].push_back({i,w});
		
	} 
	int ce=2*m;
	for(int i=1;i<=n;i++){
		ce++;
		cin>>w;
		for(int j=1;j<=w;j++){
			cin>>x>>y;
			e[ce].push_back({m+x,y});
			e[m+x].push_back({ce,y});
		}
	}
	for(int i=1;i<=q;i++){
		memset(dis,0x3f,sizeof(dis));
		long long ans=0;
		cin>>x>>y;
		dfs(x,y);
		cout<<dis[y]<<'\n';
	}
	cout<<endl;
	return 0;
}

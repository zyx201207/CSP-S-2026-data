#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,n,m,d,q,dis[N],o;
vector<pair<int,int> > g[N];
void dij(int qd){
	for(int i=1;i<=o;i++){
		dis[i]=1e18; 
	}	
	priority_queue<pair<int,int> > q;
	dis[qd]=0;
	q.push({0,qd});
	while(q.size()){
		int cur=q.top().second;
		q.pop();
		for(int i=0;i<g[cur].size();i++){
			int y=g[cur][i].first,w=g[cur][i].second;
			if(dis[cur]+w<dis[y]){
				dis[y]=dis[cur]+w;
				q.push({dis[y],y});
			}
		}
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	o=2*m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		g[i].push_back({i+m,x});
		g[i+m].push_back({i,x});
	}
	for(int i=1;i<=n;i++){
		int sl;
		cin>>sl;
		o++;
		for(int i=1;i<=sl;i++){
			int a,t;
			cin>>a>>t;
			g[o].push_back({a+m,t});
			g[a+m].push_back({o,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]<<"\n";
	}
	return 0;
}

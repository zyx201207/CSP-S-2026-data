#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<vector<edge> > Map(2*m+n+1);
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		Map[i].push_back({m+i,w});
		Map[m+i].push_back({i,w});
	}
	vector<vector<int> > a(n+1);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int b,t;
			cin>>b>>t;
			a[i].push_back(b);
			Map[2*m+i].push_back({b+m,t});
			Map[m+b].push_back({2*m+i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		q.push({0,s});
		vector<int> dis(2*m+n,2e9);
		dis[s]=0;
		while(!q.empty()){
			pair<int,int> now=q.top();
			q.pop();
			if(now.first!=dis[now.second]) continue;
			for(auto t:Map[now.second]){
				if(dis[t.v]>dis[now.second]+t.w){
					dis[t.v]=dis[now.second]+t.w;
					q.push({dis[t.v],t.v});
				}
			}
		}
		cout<<dis[e]<<endl;  
	}
	return 0;
}

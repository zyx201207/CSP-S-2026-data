#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+5;
int w[MAX];
vector<pair<int,int> >graph[MAX];
int dijstra(int start ,int end){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	vector<int>dis(MAX,1e9);
	vector<bool>vis(MAX,false);
	dis[start]=0;
	q.push({0,start});
	while(!q.empty()){
		auto top=q.top();
		q.pop();
		if(vis[top.second])	continue;
		vis[top.second]=true;
		for(auto edge:graph[top.second]){
			int w=edge.first,v=edge.second;
			if(dis[top.second]+v<dis[w]){
				dis[w]=dis[top.second]+v;
				q.push({dis[w],w});
			}
		}
	}
	return dis[end];
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,last=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(j>1){
				graph[a+m*(i-1)].push_back({last,t});
				graph[last].push_back({a+m*(i-1),t});
			}
			last=a+m*(i-1);
		}
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<i<<"\n";
//		for(auto j:graph[i])	cout<<j.first<<" "<<j.second<<"\n";
//		cout<<"\n";
//	}
	while(q--){
		int start,end;
		cin>>start>>end;
		cout<<w[start]+dijstra(start,end)+w[end]<<"\n";
	}
	return 0;
}
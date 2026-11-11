#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,d,q;
int w[510000];
int k[510];
int dis[510000];
vector<pair<int,int> >ed[510000];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int d=t.first;
		int u=t.second;
		if(dis[u]<d){
			continue;
		}
		for(auto e : ed[u]){
			int v=e.first;
			int w=e.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			ed[m+i].push_back(make_pair(a,t));
			ed[a].push_back(make_pair(m+i,t));
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		//if(12<=c&&c<=19){
			
		//}
		//else{
			for(int i=1;i<=n+m;i++){
				dis[i]=9e11;
			}
			dij(x);
			cout<<dis[y]+w[x]+w[y]<<endl;
		//}
	}
	return 0;
}
//big baoli

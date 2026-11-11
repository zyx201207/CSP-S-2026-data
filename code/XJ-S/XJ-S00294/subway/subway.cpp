#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500005];
struct node{
	int a,t;
};
vector<node> a[500505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i+m].push_back({x,y});
			a[x].push_back({i+m,y});
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		vector<long long> dis(m+n+1,1e18);
		dis[x]=0;
		priority_queue<pair<long long,int>,
						vector<pair<long long,int> >,
						greater<pair<long long,int> > > q;
		q.push({0,x});
		while(!q.empty()){
			pair<long long,int> f=q.top();
			q.pop();
			long long d=f.first;
			int u=f.second;
			if(d>dis[u])continue;
			for(int i=0;i<a[u].size();i++){
				int v=a[u][i].a,t=a[u][i].t;
				if(dis[v]>d+t){
					dis[v]=d+t;
					q.push({dis[v],v});
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

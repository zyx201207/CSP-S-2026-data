#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,r,e,w[500005],dist[600005],p[1505][1505];
vector<pair<int,int>>v[600005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void d(int s){
	for(int i=1;i<=n+m;i++){
		dist[i]=1e18;
	}
	dist[s]=0;
	q.push({0,s});
	while(q.size()>=1){
		pair<int,int>t=q.top();
		q.pop();
		if(dist[t.second]==t.first){
			for(pair<int,int>i:v[t.second]){
				if(dist[i.first]>t.first+i.second){
					dist[i.first]=t.first+i.second;
					q.push({dist[i.first],i.first});
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>r>>e;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[m+i].push_back({a,t});
			v[a].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n+m;i++){
		d(i);
		for(int j=1;j<=n+m;j++){
			p[i][j]=dist[j];
		}
	}
	while(e--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+p[x][y]<<"\n";
	}
	return 0;
}
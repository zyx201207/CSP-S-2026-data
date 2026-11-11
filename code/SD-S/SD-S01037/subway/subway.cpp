#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,T,x,y,p,t,z,w[500005],dis[500005],vis[500005];
vector<pair<long long,long long>> h[500005];
vector<pair<long long,long long>> h2[505];
set<int> s[505];
void solve(int u){
	priority_queue<pair<long long,long long>> q;
	long long minn=2e16;
	for(int i=1;i<=m;i++) dis[i]=2e16,vis[i]=0;
	dis[u]=0;
	q.push({0,u});
	while(q.size()){
		pair<long long,long long> pl=q.top();
		q.pop();
		long long b=-pl.first,k=pl.second;
		if(vis[k]) continue;
		vis[k]=1;
		for(int i=0;i<h[k].size();i++){
			for(int j=0;j<h2[h[k][i].first].size();j++){
				if(dis[h2[h[k][i].first][j].first]>b+h2[h[k][i].first][j].second+h[k][i].second){
					dis[h2[h[k][i].first][j].first]=b+h2[h[k][i].first][j].second+h[k][i].second;
					q.push({-b-h2[h[k][i].first][j].second-h[k][i].second,h2[h[k][i].first][j].first});
				}
				//What am I writing?!!!
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>z;
		for(int j=1;j<=z;j++){
			cin>>p>>t;
			h[p].push_back({i,t});
			h2[i].push_back({p,t});
			s[i].insert(p);
		}
	}
	while(T--){
		cin>>x>>y;
		solve(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}

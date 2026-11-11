#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
vector<pair<long long,long long>>G[500005];
long long V[500005],dis[500005];
bool vis[500005];
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<long long,long long>>q;
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto t:G[x]){
			long long y=t.first,v=t.second;
			if(dis[y]>dis[x]+v){
				dis[y]=dis[x]+v;
				q.push({-dis[y],y});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>V[i];
	while(n--){
		long long t;
		cin>>t;
		for(int i=1;i<=t;i++){
			long long x,y;
			cin>>x>>y;
			G[x].push_back({x+n,y});
			G[x+n].push_back({x,y});
		}
	}while(q--){
		memset(vis,0,sizeof(vis));
		long long x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+V[y]+V[x]<<"\n";
	}
	return 0;
} 

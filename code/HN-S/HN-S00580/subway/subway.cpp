#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+100;
const int M = 510;

long long c,n,m,d,Q,k,a,t;
long long x,y;
long long w[N]={};
vector<pair<int,long long>> mp[N+M+100]={}; 

bool vis[N+M+100]={};
long long dis[N+M+100]={};
priority_queue<pair<long long,int>> q;
long long query(long long x,long long y){
	while(q.size()) q.pop();
	for(int i=0;i<N+M+100;i++) vis[i]=0 , dis[i]=1e18;
	dis[x]=0 , q.push(make_pair(dis[x],x));
	while(q.size()){
		int id=q.top().second; q.pop();
//		if(vis[id]) continue;
		vis[id] = 1;
		for(int i=0;i<mp[id].size();i++){
			long long to=mp[id][i].first,v=mp[id][i].second;
			if(dis[to]>dis[id]+v){
				dis[to] = dis[id]+v;
				q.push(make_pair(dis[to],to));
			}
		}
	}
	return (dis[y]+w[x]+w[y]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			mp[a].push_back(make_pair(i+N+1,t));
			mp[i+N+1].push_back(make_pair(a,t));
		}
	}
	while(Q--){
		cin>>x>>y;
		cout<<query(x,y)<<'\n';
	}
	return 0;
}

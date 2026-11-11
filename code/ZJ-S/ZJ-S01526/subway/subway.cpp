#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k,a[M],x,y;
ll w[M],t[M],dis[N+M];
bool vis[N+M];
vector<pair<int,ll>> ve[N+M];
void dijsktra(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	for(int i=1;i<=n+m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	dis[s]=0;
	pq.push({dis[s],s});
	while(!pq.empty()){
		int now=pq.top().second;
		pq.pop();
		if(vis[now]) continue;
		vis[now]=1;
		for(auto it:ve[now])
			if(dis[it.first]>dis[now]+it.second){
				dis[it.first]=dis[now]+it.second;
				pq.push({dis[it.first],it.first});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			ve[m+i].push_back({a[j],t[j]});
			ve[a[j]].push_back({m+i,t[j]});
		}
	}
	while(q--){
		cin>>x>>y;
		dijsktra(x);
		cout<<w[x]+dis[y]+w[y]<<"\n";
	}
	return 0;
}
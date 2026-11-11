#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
	int u,v,w;
	bool operator<(const node fu)const{
		return w<fu.w;
	}
};
vector<node>mp[10005];
int dijstra(int s,int t){
	int dis[10005];
	bool vis[10005]={};
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<node>pq;
	pq.push({s,0});
	while(!pq.empty()){
		node p=pq.top();
		pq.pop();
		if(vis[p.v])continue;
		if(dis[p.u]+p.w<dis[p.v]){
			dis[p.v]=dis[p.u]+p.w;
			vis[p.v]=1;
			for(node q:mp[p.v])pq.push(q);
		}
	}
	return dis[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		int w;
		cin>>w;
		mp[i].push_back({i,m+i,w});
		mp[m+i].push_back({m+i,i,w});
	}
	for(int u=1;u<=n;++u){
		int k,a[5005],b[5005];
		cin>>k;
		for(int i=1;i<=k;++i)cin>>a[i]>>b[i];
		for(int i=1;i<=k;++i)
			for(int j=1;j<=k;++j)mp[a[i]+m].push_back({a[i]+m,a[j]+m,b[i]+b[j]});
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dijstra(x,y)<<"\n";
	}
	return 0;
}
//mima:Oct31==Dec25?

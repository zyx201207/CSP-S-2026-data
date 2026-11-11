#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<pair<ll,ll> >pq;
queue<ll>que;
bool vis[500505];
ll dis[500505];
ll w[500005];
vector<pair<ll,ll> >a[500505];
ll c,n,m,d,q,x,y,k;
ll p;
void solve1(){
	while(!pq.empty())pq.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f,sizeof(dis));
	dis[x]=0;
	pq.push(make_pair(0,x));
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<a[u].size();i++){
			ll v=a[u][i].second;
			ll c=a[u][i].first;
			if(dis[v]>dis[u]+c){
				dis[v]=dis[u]+c;
				pq.push(make_pair(-dis[v],v));
			}
		}
	}
	cout<<w[x]+w[y]+dis[y]<<"\n";
}
void solve2(){
	while(!que.empty())que.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	que.push(x);
	while(!que.empty()){
		ll u=que.front();que.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(u==y)break;
		for(int i=0;i<a[u].size();i++){
			ll v=a[u][i].second;
			dis[v]=dis[u]+p;
			que.push(v);
		}
	}
	cout<<dis[y]+w[x]+w[y]<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll aa,tt;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>tt;
			p=tt;
			a[m+i].push_back(make_pair(tt,aa));
			a[aa].push_back(make_pair(tt,m+i));
		}
	}
	while(q--){
		cin>>x>>y;
		if(12<=c&&c<=19){
			solve2();
			continue;
		}
		solve1();
	}
	return 0;
}

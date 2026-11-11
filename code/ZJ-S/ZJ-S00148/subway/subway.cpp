#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q;
long long W[500005];
struct node{
	int x;
	long long w;
	bool operator<(node b)const{
		return w>b.w;
	}
};
vector<node>v[500505];
vector<int>cnt[500005];
priority_queue<node>q;
long long dis[505][20505],dis1[500505],dis2[3][500505];
bool vis[500505];
void Dij(int st){
	for(int i=1;i<=n+m;i++){
		dis[st][i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[st][st]=0;
	while(!q.empty())q.pop();
	q.push({st,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.x])continue;
		vis[t.x]=1;
		for(int j=0;j<v[t.x].size();j++){
			node e=v[t.x][j];
			if(dis[st][e.x]>dis[st][t.x]+e.w){
				dis[st][e.x]=dis[st][t.x]+e.w;
				q.push({e.x,dis[st][e.x]});
			}
		}
	}
}
void Dij1(int st){
	for(int i=1;i<=n+m;i++){
		dis1[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis1[st]=0;
	while(!q.empty())q.pop();
	q.push({st,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.x])continue;
		vis[t.x]=1;
		for(int j=0;j<v[t.x].size();j++){
			node e=v[t.x][j];
			if(dis1[e.x]>dis1[t.x]+e.w){
				dis1[e.x]=dis1[t.x]+e.w;
				q.push({e.x,dis1[e.x]});
			}
		}
	}
}
void Dij2(int st){
	for(int i=1;i<=n+m;i++){
		dis2[st][i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis2[st][st]=0;
	while(!q.empty())q.pop();
	q.push({st,0});
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.x])continue;
		vis[t.x]=1;
		for(int j=0;j<v[t.x].size();j++){
			node e=v[t.x][j];
			if(dis2[st][e.x]>dis2[st][t.x]+e.w){
				dis2[st][e.x]=dis2[st][t.x]+e.w;
				q.push({e.x,dis2[st][e.x]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int x,w;
		while(k--){
			cin>>x;
			cin>>w;
			v[i].push_back({n+x,w});
			v[n+x].push_back({i,w});
			cnt[x].push_back(i);
		}
	}
	if(c<=8){
		while(Q--){
			int x,y;
			cin>>x>>y;
			Dij1(x+n);
			cout<<W[x]+W[y]+dis1[y+n]<<'\n';
		}
		return 0;
	}
	else if(c<=15){
		for(int i=1;i<=n;i++)Dij(i);
		while(Q--){
			int x,y;
			cin>>x>>y;
			long long ans=0x3f3f3f3f3f3f3f3f;
			for(int j=0;j<cnt[x].size();j++){
				int t=cnt[x][j];
				ans=min(ans,dis[t][x+n]+dis[t][y+n]);
			}
			cout<<W[x]+W[y]+ans<<'\n';
		}
		return 0;
	}
	else if(c>=20&&c<=21){
		for(int i=1;i<=n;i++)Dij2(i);
		while(Q--){
			int x,y;
			cin>>x>>y;
			long long ans=0x3f3f3f3f3f3f3f3f;
			for(int j=0;j<cnt[x].size();j++){
				int t=cnt[x][j];
				ans=min(ans,dis2[t][x+n]+dis2[t][y+n]);
			}
			cout<<W[x]+W[y]+ans<<'\n';
		}
		return 0;
	}
}
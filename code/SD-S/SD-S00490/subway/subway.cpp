#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e4+5;
int c,n,m,d,q;
int w[N];
int k[N];
vector<pii> g[N];
int s,e;
int dis[N];
int f[N];
void dij(){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		pii t=q.top();
		q.pop();
		int u=t.second;
//		cout<<u<<' ';
		if(f[u])continue;
		f[u]=1;
		dis[u]+=w[u];
		for(pii x:g[u]){
			int v=x.first,w=x.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int v,w,vv,ww;
		cin>>k[i];
		if(k[i]==1){
			cin>>v>>w;
			continue;
		}
		cin>>v>>w>>vv>>ww;
		g[v].push_back({vv,w});
		for(int i=1;i<=k[i]-2;i++)cin>>v>>w;
	}
//	for(int i=1;i<=n;i++){
//		int u,w;
//		cin>>k[i];
//		cin>>u>>w;
//		for(int j=1;j<k[i];j++){
//			int v;
//			cin>>v>>w;
//			g[u].push_back({v,w});
//			u=v;
//		}
//	}
	while(q--){
		cin>>s>>e;
		for(int i=1;i<=m;i++)f[i]=0;
		dij();
	//	for(int i=1;i<=m;i++)cout<<dis[i]<<' ';
	//	cout<<'\n';
		cout<<dis[e]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
2 1 2 2 3
2 2 3 4 5
1 2
1 4
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

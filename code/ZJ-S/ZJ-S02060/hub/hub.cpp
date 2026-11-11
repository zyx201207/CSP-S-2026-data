#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,x,y,vis[501];

	ll maxx=0,k=0;
vector<ll>g [500];
int bfs(int s){
	queue<pair<int,int> >q;
	for(int i=1;i<=n;i++)  vis[i]=0;
	maxx=0,k=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.front().second,w=q.front().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(maxx<w){
			maxx=w;
			k=u;
		}
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			q.push({w+1,v});
		}
	}
	return k;
}
int main(){
	/*freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);*/
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int v=bfs(1);
		bfs(v);
		cout<<ceil(maxx/4)<<endl;
	}
	return 0;
}


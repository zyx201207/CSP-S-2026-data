#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,m,n,d,q,a[10010],ans,t[1010][1010],w[100010],vis[10010];
vector <int> g[100010],line[100010];
struct node{
	int id,t,l;
};
int bfs(int x,int y){
	queue <node> q;
	q.push({x,w[x] + t[x][line[x][0]],line[x][0]});
	while(!q.empty()){
		node now = q.front();
		q.pop();
		vis[now.id] = 1;
		if(now.id == y)return now.t + w[now.id] + t[now.id][now.l];
		//cout << now.t + w[now.id] + t[now.id][now.l] << endl;
		for(int v : g[now.l]){
			if(!vis[v]){
				q.push({v,now.t,now.l});
			}
		}
		for(int v : line[now.id]){
			if(v != now.l){
				q.push({v,now.t + t[now.id][now.l] + t[now.id][v],v});
			}
		}
	}
}
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
		int u,v;
		cin >> u >> v;
		line[u].push_back(i);
		g[i].push_back(u);
		t[u][i] = v;
	}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		memset(vis,sizeof(vis),0);
		//cout << x << y << endl;
		cout << bfs(x,y) <<endl;
	}
	return 0;
}


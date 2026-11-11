#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e5+25;

int C;
int n,m;

vector<int> e[N];
void add(int u,int v){
	e[u].push_back(v);
}

int dis[N];
bool vis[N];
priority_queue<pii > q;
void dijks(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push({0,s});
	while (!q.empty()){
		int now=q.top().second;
		q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		for (int v:e[now]){
			if (dis[now]+1<dis[v]){
				dis[v]=dis[now]+1;
				q.push({-dis[v],v});
			}
		}
	}
}

void init(){
	for (int i=1;i<=n;++i)
		e[i].clear();
}

void solve(){
	cin>>n>>m;
	for (int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	dijks(1);
	int s=1;
	for (int k=1;k<=n;++k){
		if (dis[k]>dis[s]){
			s=k;
		}
	}
	dijks(s);
	int t=1;
	for (int k=1;k<=n;++k){
		if (dis[k]>dis[t]) t=k;
	}
	cout<<(dis[t]+3)/4<<'\n';
	init();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>C>>T;
	while (T--) solve();
	return 0;
}//hub

#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

const int N = 2e6+10;

struct node{
	int to,w;
};

int c,n,m,d,Q,k;
int dis[N],vis[N],w[N],a[N],t[N];
vector<node> g[N];

bool operator<(node x,node y){
	return x.w > y.w;
}

priority_queue<node> q;

void dij(int s){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s] = 0;
	q.push({s,0});
	while(!q.empty()){
		node now = q.top();q.pop();
		int u = now.to;
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(auto c : g[u]){
			//cout << 1 << endl;
			int v = c.to,lenn = c.w;
			if(dis[v] > dis[u] + lenn){
				dis[v] = dis[u] + lenn;
				q.push({v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[j] >> t[j];
		}
		for(int i = 1;i <= k;i++){
//			g[a[i]].push_back({a[i-1],t[i]+t[i-1]});
//			g[a[i-1]].push_back({a[i],t[i]+t[i-1]});
			for(int j = i+1;j <= k;j++){
				g[a[i]].push_back({a[j],t[i]+t[j]});
				g[a[j]].push_back({a[i],t[i]+t[j]});
			}
		}
	}
	
	for(int i = 1;i <= m;i++){
		g[i+m].push_back({i,w[i]});
		g[i].push_back({i+m,w[i]});
	}
	
//	for(int i = 1;i <= m+m;i++){
//		for(auto c : g[i]){
//			cout << i << " "<< c.to <<' '<< c.w << endl;
//		}
//	}
	
	while(Q--){
		int x,y;
		cin >> x >> y;
		dij(x+m);
		cout << dis[y+m] << endl;
	}
	return 0;
}
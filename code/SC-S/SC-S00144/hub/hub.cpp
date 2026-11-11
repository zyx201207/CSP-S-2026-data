#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int c,t,n,k,dis[N];bool vis[N];
vector<int>g[N];
inline int getdis(int s){
	int pyc = 0;
	queue<int>q;
	for(int i = 1;i <= n;++i) dis[i] = 0x3f3f3f3f3f3f3f3f,vis[i] = 0;
	for(int i = 1;i <= n;++i) if(s >> (i - 1) & 1){
		dis[i] = 0;vis[i] = 1;
		q.emplace(i);
	}while(!q.empty()){
		int u = q.front();q.pop();
		pyc = max(pyc,dis[u]);
		for(int v : g[u]){
			if(!vis[v]){
				dis[v] = dis[u] + 1;
				vis[v] = 1;
				q.emplace(v);
			}
		}
	}return pyc;
}inline int getPyC(int s){
	int pyc = 0;
	for(int i = 1;i <= n;++i) if(s >> (i - 1) & 1) pyc++;
	return pyc;
}inline int getlt(int s){
	int pyc = 0;
	for(int u = 1;u <= n;++u) if(s >> (u - 1) & 1){
		pyc++;
		for(int v : g[u]) if(s >> (v - 1) & 1){
			pyc--;
		}
	}return pyc;
}signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i <= n;++i) g[i].clear();
		for(int i = 1,u,v;i < n;++i){
			cin >> u >> v;
			g[u].emplace_back(v);g[v].emplace_back(u);
		}int pyc = n;
		for(int s = 1;s < (1ll << n);++s){
			if(getPyC(s) == k && getlt(s) <= 2){
				pyc = min(pyc,getdis(s));
			}
		}cout << pyc << "\n";
	}return 0;
}
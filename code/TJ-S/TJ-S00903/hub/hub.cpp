#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e6+1,inf = 0x3f3f3f3f3f3f3f3f;
int c,t,n,k,ans = inf;
namespace Graph{
	int tot = 0,head[N],nxt[N<<1],to[N<<1];
	inline void connect_head(const int &u,const int &v){
		nxt[++tot] = head[u];
		head[u] = tot;
		to[tot] = v;
	}
}using namespace Graph;
int dist[N];
bitset<N>st,vis;
void bfs(const int &start){
	queue<int>q;
	q.push(start);
	for(int i = 1;i<=n;++i){
		dist[i] = 0;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];i;i = nxt[i]){
			int v = to[i];
			if(st.test(v)&&!vis.test(v)){
				vis.set(v);
				q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
}
void dfs(const int &u){
	if(u == n+1){
		if(st.count()!=k){
			return;
		}
		int cnt = 0;
		for(int i = 1;i<=n;++i){
			vis.set(i,0);
		}
		for(int i = 1;i<=n;++i){
			if(st.test(i)&&!vis.test(i)){
				vis.set(i,1);
				bfs(i);
				++cnt;
			}
		}
		if(cnt>2){
			return;
		}
		for(int i = 1;i<=n;++i){
			vis.set(i,0);
		}
		queue<int>q;
		for(int i = 1;i<=n;++i){
			if(st.test(i)){
				q.push(i);
				vis.set(i);
			}
			dist[i] = 0;
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = head[u];i;i = nxt[i]){
				int v = to[i];
				if(!vis.test(v)){
					vis.set(v);
					q.push(v);
					dist[v] = dist[u]+1;
				}
			}
		}
		int res = 0;
		for(int i = 1;i<=n;++i){
			res = max(res,dist[i]);
		}
		ans = min(ans,res);
		return;
	}
	st.set(u,1);
	dfs(u+1);
	st.set(u,0);
	dfs(u+1);
}
void clear(){
	for(int i = 1;i<=n;++i){
		head[i] = 0;
	}
	tot = 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1;i<n;++i){
			int u,v;
			cin >> u >> v;
			connect_head(u,v);
			connect_head(v,u);
		}
		ans = inf;
		dfs(1);
		cout << ans << '\n';
		clear();
	}
	return 0;
}

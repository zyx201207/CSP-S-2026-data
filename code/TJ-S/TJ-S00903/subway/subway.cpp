#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e2+1,M = 5e5+1,inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,val[M];
vector<pair<int,int> >vec[M];
namespace Graph{
	int tot = 0,head[N+M],nxt[M*20],to[M*20],w[M*20];
	inline void connect_head(const int &u,const int &v,const int &weight){
		nxt[++tot] = head[u];
		head[u] = tot;
		to[tot] = v;
		w[tot] = weight;
	}
}using namespace Graph;
int f[N][N],dist[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >heap;
bitset<N>st;
void dijkstra(const int &start){
	heap.push({0,start-m});
	st.reset();
	memset(dist,0x3f,sizeof(dist));
	dist[start-m] = 0;
	while(!heap.empty()){
		int u = heap.top().second;
		heap.pop();
		if(st.test(u)){
			continue;
		}
		st.set(u);
		for(int i = head[u+m];i;i = nxt[i]){
			int v = to[i]-m,dis = w[i];
			if(dist[v]>dist[u]+dis){
				dist[v] = dist[u]+dis;
				heap.push(make_pair(dist[v],v));
			}
		}
	}
	for(int i = 1;i<=n;++i){
		f[start-m][i] = f[i][start-m] = dist[i];
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;++i){
		cin >> val[i];
	}
	for(int i = 1;i<=n;++i){
		int k;
		cin >> k;
		for(int j = 1;j<=k;++j){
			int a,t;
			cin >> a >> t;
			vec[a].emplace_back(make_pair(i+m,t));
		}
	}
	for(int i = 1;i<=m;++i){
		for(int j = 0;j<vec[i].size();++j){
			for(int k = j+1;k<vec[i].size();++k){
				connect_head(vec[i][j].first,vec[i][k].first,vec[i][j].second+vec[i][k].second);
				connect_head(vec[i][k].first,vec[i][j].first,vec[i][j].second+vec[i][k].second);
			}
		}
	}
	for(int i = 1;i<=n;++i){
		dijkstra(i+m);
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int ans = inf;
		for(pair<int,int> u:vec[x]){
			for(pair<int,int> v:vec[y]){
				ans = min(ans,val[x]+val[y]+u.second+v.second+f[u.first-m][v.first-m]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

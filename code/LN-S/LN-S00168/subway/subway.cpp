#include<bits/stdc++.h>
#define endl '\n'
#define finline inline __attribute__((always_inline))
#define int long long
using namespace std;
const int MAXN = 5e2 + 10,MAXM = 1e5 + 10;
const int INF = 1e15;
struct node{int to,w;};
finline bool operator<(const node &a,const node &b){return a.w > b.w;}
int c,n,m,d,q,w[MAXM],t[MAXN][MAXM],rnk[MAXN][MAXM],dis[MAXN][MAXN];
vector<node> g[MAXN];
vector<int> st[MAXM];
finline void dijkstra(int s){
	priority_queue<node> q;
	q.push({s,0});
	fill(dis[s] + 1,dis[s] + 1 + n,INF);
	dis[s][s] = 0;
	while(!q.empty()){
		int u = q.top().to,cost = q.top().w;
		q.pop();
		if(dis[s][u] != cost) continue;
		for(node e : g[u]){
			int v = e.to,w = e.w;
			if(dis[s][v] > dis[s][u] + w){
				dis[s][v] = dis[s][u] + w;
				q.push({v,dis[s][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1;i <= n;++i){
		int k,x;
		cin >> k;
		for(int j = 1;j <= k;++j){
			cin >> x >> t[i][j];
			st[x].push_back(i);
			rnk[i][x] = j; 
		}
	}
	for(int i = 1;i <= m;++i){
		int sz = (int)st[i].size();
		if(!sz) continue;
		for(int j = 0;j < sz;++j){
			for(int k = j + 1;k < sz;++k){
				int st1 = st[i][j],st2 = st[i][k];
				g[st1].push_back({st2,t[st1][rnk[st1][i]] + t[st2][rnk[st2][i]]});
				g[st2].push_back({st1,t[st1][rnk[st1][i]] + t[st2][rnk[st2][i]]});
			}
		}
	}
	for(int i = 1;i <= n;++i) dijkstra(i);
	while(q--){
		int u,v,res = INF;
		cin >> u >> v;
		for(int i : st[u]){
			for(int j : st[v]){
				res = min(res,dis[i][j] + w[u] + w[v] + t[i][rnk[i][u]] + t[j][rnk[j][v]]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32 
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16
*/

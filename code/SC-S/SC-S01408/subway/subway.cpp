#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 10;
const int N = 500;
const int INF = 1e18 + 10;
struct nod{
	int u, v;
	const operator >(nod b)const{
		return v > b.v;
	}
};
int c, n, m, d, q;
int t[M], dis[N][N];
vector<nod> eage[N], st[M];
void dij(int start){
	priority_queue<nod, vector<nod>, greater<nod> > pq;
	vector<int> vis(n + 1, 0);
	for(int i = 1;i <= n;i++)
		dis[start][i] = INF;
	dis[start][start] = 0;
	pq.push({start, 0});
	while(!pq.empty()){
		nod t = pq.top();
		pq.pop();
		if(vis[t.u] == 1)
			continue;
		for(nod i : eage[t.u]){
			if(t.v + i.v <= dis[start][i.u])
				dis[start][i.u] = t.v + i.v, pq.push({i.u, dis[start][i.u]});
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> t[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k;j++){
			nod inp;
			cin >> inp.u >> inp.v;
			st[inp.u].push_back({i, inp.v});
		}
	}
	
	for(int i = 1;i <= m;i++){
		for(nod l : st[i]){
			for(nod r : st[i]){
				if(l.u == r.u)
					continue;
				eage[l.u].push_back({r.u, l.v + r.v});
			}
		}
	}
	for(int i = 1;i <= n;i++)
		dij(i);
	
	for(int i = 1;i <= q;i++){
		int u, v, ma = INF;
		cin >> u >> v;
		for(nod x:st[u]){
			for(nod y : st[v]){
				int ux = x.u, uy = y.u;
				ma = min(ma, dis[ux][uy] + y.v + x.v);
			}
		}
		cout << ma + t[u] + t[v] << endl;
	}
	return 0;
}/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
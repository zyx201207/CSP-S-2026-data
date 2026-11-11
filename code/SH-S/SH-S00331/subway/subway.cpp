#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

ll c, n, m, d, q, w[500005], k[505], num, x, y;
ll dis[600005], vis[600005];
vector<pii> l[600005];
priority_queue<pii, vector<pii>, greater<pii> > pq, e;

void dij(){
	for(int i = 1;i <= 2 * m + num;i++){
		dis[i] = 1e18;
		vis[i] = 0;
	}
	pq = e;
//	while(pq.size()){
//		pq.pop();
//	}
	dis[x] = 0;
	pq.push({0, x});
	while(!pq.empty()){
		int u = pq.top().second, z = pq.top().first;
		pq.pop();
		if(vis[u]){
			continue;
		}
	//	cout << u << " " << z << ": " <<endl;
		if(u == y){
			return ;
		}
		vis[u] = 1;
		for(int i = 0;i < l[u].size();i++){
			int v = l[u][i].first, w = l[u][i].second;
		//	cout << "  " << v << " " << dis[v];
			if(dis[v] > z + w && vis[v] == 0){
				dis[v] = z + w;
				pq.push({dis[v], v});
			//	cout << "y ";
			}
		}
	//	cout <<endl;
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
		l[i].push_back({i + m, w[i]});
		l[i + m].push_back({i, w[i]});
	//	cout << i <<" " << i +m << endl;
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int a, t;
			cin >> a >> t;
			l[m + a].push_back({2 * m + (++num), t});
			l[2 * m + num].push_back({m + a, t});
		//	cout << m + a << " " << 2 * m + num << " " << t << endl;
			if(j > 1){
				l[2 * m + num - 1].push_back({2 * m + num, 0});
				l[2 * m + num].push_back({2 * m + num - 1, 0});
			//	cout << 2 * m + num << " " << 2 * m + num - 1 <<endl;
			}
		}
	}
//	cout << endl <<"-----------" << endl;
	while(q--){
		cin >> x >> y;
		dij();
		cout << dis[y] << endl;
	}
}


// kou, 1  ~  n    ting, n + 1  ~  2 * n

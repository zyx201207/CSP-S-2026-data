#include <bits/stdc++.h>
#define int long long

using namespace std;

struct node{
	int y, w;
	node (int _y, int _w) {	y = _y, w = _w; };
};

const int M = 500001, N = 501;
int c, n, m, d, Q, w[M], k[N], dist[M + M + N];
vector<node> edge[M + M + N];
set<pair<int, int> > q; 

int dijkstra(int s, int t){//最短路 
	memset(dist, 127, sizeof(dist));
	dist[s] = 0;
	q.clear();
	for (int i = 1; i <= m + n; i++)
	    q.insert(make_pair(dist[i], i));
	while (!q.empty()){
		int x = q.begin()->second;
	    q.erase(q.begin());
	    if (x == t || dist[x] > 1 << 30)
	        break;
	    for (auto i : edge[x])
	        if (dist[x] + i.w < dist[i.y]){
	        	q.erase(make_pair(dist[i.y], i.y));
	        	dist[i.y] = dist[x] + i.w;
	        	q.insert(make_pair(dist[i.y], i.y));
			}
	} 
	return dist[t];
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
	    cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
		    int a, t;
		    cin >> a >> t;
		    edge[a].push_back(node(m + i, t));
			edge[m + i].push_back(node(a, t));
			//连接各站台和线路的站台 
		}
	}
	for (int i = 1; i <= Q; i++){
 	    int x, y;
        cin >> x >> y;
	   	cout << dijkstra(x, y) + w[x] + w[y] << endl;
	   	//for (int j = 1; j <= m + n; j++)
	    //    cout << dist[j] << " ";
	    //cout << endl;
	}
}//第一次场切CSP-ST2！！！CCF pls give me 1=！！！ 
//时间复杂度应该是 O(q(n + m + \sum_{i = 1}^n k_i)) 场切个屁，60pts 

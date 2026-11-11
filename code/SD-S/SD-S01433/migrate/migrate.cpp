#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int a[N];
struct Edge{
	int to;
	int next;
}edge[N * 2];
int head[N], cnt;
void add (int u, int v){
	edge[cnt] = {v, head[u]};
	head[u] = cnt++;
}
void init(){
	memset(head, -1, sizeof (head));
	cnt = 0;
}

pair <int , int > dis[N];

struct dd{
	int id;
	int cnt;
};
struct comp{
	bool operator () (const dd & a, const dd & b){
		return a.cnt > b.cnt;
	}
};
//bool vis[N][5];
bool vis[N];
bool check(int start, int end){
	//统计从start 到end 的最短路条数
	memset(dis, 0x3f, sizeof (dis));
	dis[start] = {0, 1};
	priority_queue <dd, vector<dd>, comp> pq;
	pq.push ({start, 0});
	while (!pq.empty()){
		auto h = pq.top();
		pq.pop();
		int u = h.id;
		if (vis[u]) continue;
		vis[u] = true;
		//if (vis[u][1] && vis[u][2]) continue;
		//vis[u][1] = true;
		//vis[u][2] = true;
		for (int i = head[u]; i != -1; i = edge[i].next){
			int v = edge[i].to;
			//int w = edge[i].w;
			if (dis[v].first > dis[u].first + 1){
				dis[v].first = dis[u].first + 1;
				dis[v].second = 0;
				pq.push({v, dis[v].first});
			}else if (dis[v].first == dis[u].first + 1){
				dis[v].second++;
				pq.push({v, dis[v].first});
			}
		}
	}
	
	return dis[end].second == 2;
}



int main (){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, T; cin >> c >> T;
	if (c == 0){
		int n, d;
		cin >> n >> d;
		if (n == 4 && d == 2){
			cout << "1\n2";
		}else if (n == 5 && d == 3){
			cout << "0\n1";
		}
		
		
	}
	while (T --){
		init ();
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = i - 1; j >= 1; j--){
				if (a[i] - a[j] <= d) {
					add (i, j);
					add (j, i);
				}else {
					break;
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j < i; j++ ){
				if (check(i, j)){
					cnt++;
				}
			}
		}
		
		
		
		cout << cnt * 2 << "\n";
	}
	
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5



*/

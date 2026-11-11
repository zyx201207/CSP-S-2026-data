#include <bits/stdc++.h>
using namespace std;
struct EDGE{
    int to, ne, v;
}e[2000001];
int head[2000001], cnt;
void add_EDGE(int x, int y, int v){
    cnt++;
    e[cnt].v = v;
    e[cnt].to = y;
    e[cnt].ne = head[x];
    head[x] = cnt;
}
struct POS{
    int v, p;
    bool operator < (const POS &x) const{
        return x.v < v;
    }
};
priority_queue <POS> q;
int dis[2000001];
int c, n, m, d, t;
int dijkstra(int s, int en){
    vector <int> dis(2 * m + n + 2, 1e9);
    dis[0] = dis[1] = 0;
    q.push({0, s});
    while(!q.empty()){
        POS f = q.top();
        q.pop();
        if(dis[f.p] < f.v)
            continue;
        for(int i = head[f.p]; i; i = e[i].ne){
            q.push({f.v + e[i].v, e[i].to});
            dis[e[i].to] = min(dis[e[i].to], f.v + e[i].v);
        }
    }
    return dis[en];
}
vector <int> a[501001];
queue <pair <int, int> > p;
int bfs(int s, int en){
	vector <bool> b(n + m + 2, 0);
	while(!p.empty())
		p.pop();
	p.push({s, 0});
	while(!p.empty()){
		int x = p.front().first;
		int y = p.front().second;
		p.pop();
		if(b[x])
			continue;
		b[x] = 1;
		for(auto i : a[x]){
			if(!b[i])
				p.push({i, y + 1});
			if(i == en){
				return y + 1;
			}
		}
	}
}
int entr[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> t;
    if(c >= 12 && c <= 19){
		int z;
		for(int i = 1; i <= m; i++)
			cin >> entr[i];
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			for(int j = 1; j <= x; j++){
				int y;
				cin >> y >> z;
				a[y].push_back(i + m);
				a[i + m].push_back(y);
			}
		}
		for(int i = 1; i <= t; i++){
			int x, y;
			cin >> x >> y;
			cout << bfs(x, y) * z + entr[x] + entr[y] << '\n';
		}
	}
    else{
		for(int i = 1; i <= m; i++){
			int x;
			cin >> x;
			add_EDGE(i, i + m, x);
			add_EDGE(i + m, i, x);
		}
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			for(int j = 1; j <= x; j++){
				int y, z;
				cin >> y >> z;
				add_EDGE(2 * m + i, y + m, z);
				add_EDGE(y + m, 2 * m + i, z);
			}
		}
		for(int i = 1; i <= t; i++){
			int x, y;
			cin >> x >> y;
			cout << dijkstra(x, y) << '\n';
		}
	}
	return 0;
}

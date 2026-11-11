#include<bits/stdc++.h>
using namespace std;
const int MX = 5e5 + 10;
const int NX = 555;
int c, n, m, d, q;
int w[MX];
struct node{
	int id, x;
};
struct ndoe{
	int now, x;
};
int wsn;
vector<node> e[MX]; 
vector<int> v[NX];
vector<int> r;
int step[MX];
void bfs(int x, int y){
	queue<node> q;
	q.push({0, x});
	step[x] = 0;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(auto it : e[t.x]){
			int w;
			if(e[t.x].size() > 1 && t.id != it.id && t.x != x)	w = 2 * wsn;
			else	w = wsn; 
			if(!step[it.x])	step[it.x] = step[t.x] + w;
			else if(step[it.x] > step[t.x] + w && step[it.x]){
				step[it.x] = step[t.x] + w;
				q.push({it.id, it.x});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)	cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		int last = 0;
		for(int j = 1; j <= k; j ++){
			int u, w;
			cin >> u >> w;
			wsn = w;
			e[last].push_back({u, i});
			last = u;
		}
	} 
	for(int i = 1; i <= q; i ++){
		int s, t;
		cin >> s >> t;
		memset(step, 0, sizeof(step));
		bfs(s, t);
		cout << step[t] + w[s] + w[t] << endl;
	}
	return 0;
}


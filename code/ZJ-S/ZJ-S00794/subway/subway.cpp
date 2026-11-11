#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N = 501, M = 500001;
int n, m, d, q, w[N], k[N];
struct point{
	int num, tim;
};
vector<point> sta[N];
struct node{
	int u, step;
};
vector<int> station[M];
void bfs(int st){
	queue<node> q;
	q.push_back(node{st, 0});
	while(!q.empty()){
		int u = q.front().u, step = q.front().step; q.pop();
		for(node it : station[u]){
			
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1, x, t; j <= k[i]; j++){
			cin >> x >> t;
			sta[i].push_back(point{x, t});
			station[x].push_back(i);
		}
	}
	while(q--){
		int st, ed;
		cin >> st >> ed;
		bfs(st);
	}
	return 0;
}

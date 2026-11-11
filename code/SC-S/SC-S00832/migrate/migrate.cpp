#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int N = 2e6 + 5;
int c, T, n;
LL a[N], ans, d;
struct edge{
	int v, next;
};
vector<edge> e;
int top = 0;
int h[N];
void inline init(){
	ans = 0;
	e.clear();
	e.push_back({0,0});
	top = 0;
	for(int i = 1; i <= n; i++)
		h[i] = 0;
}
void add(int u, int v){
	e.push_back({v, h[u]});
	h[u] = ++top;
}
int _d[N], cnt[N];
bool bfs(int start, int end){
	queue <int> q;
	for(int i = start; i <= end; i++){
		_d[i] = N;
		cnt[i] = 0;
	}
	_d[start] = 0;
	cnt[start] = 1;
	q.push(start);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = h[u]; i ; i = e[i].next){
			if(e[i].v <= end){
				if(_d[e[i].v] > _d[u] + 1){
					_d[e[i].v] = _d[u] + 1;
					cnt[e[i].v] = cnt[u];
					q.push(e[i].v);
				}
				else if(_d[e[i].v] == _d[u] + 1){
					cnt[e[i].v] += cnt[u];
				}
			}
		}
	}
	return cnt[end] == 2;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
while(T--){
	cin >> n >> d;
	init();
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[j] - a[i] <= d)
				add(i, j);
			else break;
		}
	}
	for(int i = 1; i < n; i++){
		for(int j = i + 2; j <= n;j++){
			if(a[j] - a[i] > d && bfs(i, j)) ans ++;
		}
	}
	cout << ans << '\n';
}
}
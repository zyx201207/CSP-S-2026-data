#include<bits/stdc++.h>
using namespace std;
int a[510][500510];
int w[500510];
bool locked[500510];
int c , n , m , d , qt;
vector<pair<int,int> > v[500510];
priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > q;
void dijkstra(int x){
	memset(locked , 0 , sizeof(locked));
	for(int i = 1; i <= n + m; i++){
		a[x - m][i] = 0x3f3f3f3f;
	}
	a[x - m][x] = 0;
	q.push(make_pair(0 , x));
	while(!q.empty()){
		int l = q.top().first , t1 = q.top().second;
		q.pop();
		locked[t1] = 1;
		for(int i = 0; i < v[t1].size(); i++){
			int c = v[t1][i].first , t = v[t1][i].second;
			if(locked[c] == 0){
				if(a[x - m][c] > a[x - m][t1] + t){
					a[x - m][c] = a[x - m][t1] + t;
					q.push(make_pair(a[x - m][c] , c));
				}
			}
		}
	}
}
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	scanf("%d %d %d %d %d" , &c , &n , &m , &d , &qt);
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d" , &k);
		while(k--){
			int a , t;
			scanf("%d %d" , &a , &t);
			v[m + i].push_back({a , t});
			v[a].push_back({m + i , t});
		}
	}
	for(int i = 1; i <= n; i++){
		dijkstra(m + i);
	}
	while(qt--){
		int x , y;
		scanf("%d %d" , &x , &y);
		int ans = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++){
			ans = min(ans , a[i][x] + a[i][y]);
		}
		printf("%d\n" , ans + w[x] + w[y]);
	}
} 

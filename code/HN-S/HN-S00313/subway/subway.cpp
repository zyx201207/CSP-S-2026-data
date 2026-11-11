#include <bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n , m;//地铁路数 地铁站数
int d;//每个站最多被d条路线经过 
int q;//问题数量 
map < pair < int , int > , int > ma;
//m[{i , j}]表示i号厅到第j条路线的距离
int w[505];
int dis[505][505];
int a[500005] , t[500005];
//dis[i][j]表示i号站ting到j号站ting的最短距离
vector < pair < int , int > > v[505];
//v[i] . first  表示第i站下一次能走到哪些点  v[i] . second表示是通过哪条路线到的、
void init(){
	cin >> c;
	cin >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i ++){
		cin >> w[i];
	}
	for(int i = 1 ; i <= n ; i ++){
		int k;
		cin >> k;
		for(int j = 1 ; j <= k ; j ++){
			cin >> a[j] >> t[j];
			ma[{a[j] , i}] = t[j];
		}
		for(int j = 1 ; j <= k ; j ++){
			if(j != 1 && j != k){
				v[a[j]] . push_back({a[j - 1] , i});
				v[a[j]] . push_back({a[j + 1] , i});
			}
			else if(j == 1){
				v[a[j]] . push_back({a[j + 1] , i});
			}
			else{
				v[a[j]] . push_back({a[j - 1] , i});
			}
		}
	}
}
bool flag[505];
//f[i]表示以i为起点到其余点的最少用时是否计算过
bool f[505];
void duan(int x){
	for(int i = 1 ; i <= m ; i ++) dis[x][i] = INT_MAX;
	dis[x][x] = 0;
	memset(f , false , sizeof(f));
	priority_queue < pair < int , pair < int , int > > > pq;
	//pq . top() . first 到是第几个站厅的最小值 表示   pq . top() . second . first表示 第几个站台厅 
	//pq . top() . second . second表示第几个站厅的路线
	for(int i = 1 ; i <= n ; i ++){
		if(ma[{x , i}]){
			pq . push({- ma[{x , i}] , {x , i}});
		}
	}
	dis[x][x] = 0;
	while(! pq . empty()){
		int xx = pq . top() . second . first;
		int zhi = - pq . top() . first;
		int templuxian = pq . top() . second . second;
		pq . pop();
		if(f[xx] == true) continue;
		f[xx] = true;
		for(int i = 0 ; i < v[xx] . size() ; i ++){
			int to = v[xx][i] . first;
			int luxian = v[xx][i] . second;
			if(luxian != templuxian){
				if(dis[x][to] > zhi + ma[{to , luxian}] + ma[{xx , luxian}]){
					dis[x][to] = zhi + ma[{to , luxian}] + ma[{xx , luxian}];
					if(f[to] == false) pq . push({- dis[x][to] , {to , luxian}}); 
				}
			}
			else{
				if(xx == x){
					if(dis[x][to] > zhi + ma[{to , luxian}]){
						dis[x][to] = zhi + ma[{to , luxian}];
						if(f[to] == false) pq . push({- dis[x][to] , {to , luxian}}); 
					}
				}
				else{
					if(dis[x][to] > zhi - ma[{xx , templuxian}] + ma[{to , luxian}]){
						dis[x][to] = zhi - ma[{xx , templuxian}] + ma[{to , luxian}];
						if(f[to] == false) pq . push({- dis[x][to] , {to , luxian}}); 
					}
				}
			}
		}
	}
} 
void solve(){
	for(int i = 1 ; i <= q ; i ++){
		int x , y;
		cin >> x >> y;
		if(flag[x] == false){
			duan(x);
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
		else{
			cout << w[x] + w[y] + dis[x][y] << "\n";
		}
	}
}
signed main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
	init();
	solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 4

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

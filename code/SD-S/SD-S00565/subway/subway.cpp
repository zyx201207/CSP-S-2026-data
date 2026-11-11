#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const ll MAX = 1e18;
struct node{
	int to;
	ll w;
	bool operator < (const node y) const{
		w > y.w;
	}
};
int c ,  m , n , d , Q;
ll w[N] , dis[N][N];
vector<node> tmp;
priority_queue<node> q;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	scanf("%d%d%d%d%d" , &c , &m , &n , &d , &Q);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n  ; j++){
			if(i == j) continue;
			dis[i][j] = MAX;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		scanf("%lld" , &w[i]);
	}
	for(int i = 1 ; i <= m ; i++){
		int x , minn , mins;
		tmp.clear();
		scanf("%d" , &x);
		for(int j = 1 ; j <= x ; j++){
			int to , tm;
			scanf("%d%d" , &to , &tm);
			tmp.push_back((node){to , tm});
		}
		for(int j = 0 ; j < tmp.size() ; j++){
			for(int k = 0 ; k < tmp.size() ; k++){
				if(j == k) continue;
				node u = tmp[j] , v = tmp[k];
				dis[u.to][v.to] = min(dis[u.to][v.to] , u.w + v.w);
				dis[v.to][u.to] = min(dis[v.to][u.to] , u.w + v.w);
			}
		}
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(dis[i][k] != MAX && dis[k][j] != MAX)
				dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	while(Q--){
		int x , y;
		scanf("%d%d" , &x , &y);
		printf("%lld\n" , w[x] + w[y] + dis[x][y]);
	}
	return 0;
}

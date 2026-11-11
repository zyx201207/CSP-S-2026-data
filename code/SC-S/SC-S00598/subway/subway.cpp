#include<bits/stdc++.h>
using namespace std;
const long long N = 501 + 10;
const long long M = 5e5 + 10;
inline void read(long long &x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
long long w[M] , k[N] , cost[N][N];
struct node{
	long long id1 , id2;
};
vector < long long > a[N] , t[N];
vector < node > ids[M];
long long dp[N][N];
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	long long c , n , m , d , q;
	read(c) , read(n) , read(m) , read(d) , read(q);
	for(long long i = 1;i <= m;++ i) read(w[i]);
	long long an , tn;
	for(long long i = 1;i <= n;++ i){
		read(k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(long long j = 1;j <= k[i];++ j){
			read(an) , read(tn);
			a[i].push_back(an);
			t[i].push_back(tn);
			ids[an].push_back((node){i , j});
		}
	}
	for(long long i = 1;i <= n;++ i)
	for(long long j = 1;j <= n;++ j) cost[i][j] = 1e18;
	for(long long i = 1;i <= n;++ i) cost[i][i] = 0; 
	for(long long i = 1;i <= n;++ i){
		for(long long j = 1;j <= k[i];++ j){
			for(long long k = 0;k < ids[a[i][j]].size();++ k){
				long long to = ids[a[i][j]][k].id1 , to1 = ids[a[i][j]][k].id2;
				if(i == to) continue;
				cost[i][to] = min(cost[i][to] , t[to][to1] + t[i][j]);
				cost[to][i] = min(cost[to][i] , t[to][to1] + t[i][j]);
			}
		}
	}
	for(long long i = 1;i <= n;++ i)
	for(long long j = 1;j <= n;++ j) dp[i][j] = cost[i][j];
	for(long long i = 1;i <= n;++ i){
		for(long long j = 1;j <= n;++ j){
			if(i == j) continue;
			for(long long k = 1;k <= n;++ k){
				if(i == k || k == j) continue;
				dp[i][j] = min(dp[i][k] + dp[k][j] , dp[i][j]);
			}
		}
	}
	while(q --){
		long long x , y;
		read(x) , read(y);
		long long ans = 1e18;
		for(long long k1 = 0;k1 < ids[x].size();++ k1){
			long long xx = ids[x][k1].id1 , xxx = ids[x][k1].id2;
			for(long long k2 = 0;k2 < ids[y].size();++ k2){
				long long yy = ids[y][k2].id1 , yyy = ids[y][k2].id2;
				ans = min(ans , dp[xx][yy] + t[xx][xxx] + t[yy][yyy]);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
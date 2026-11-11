#include<bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 10;
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
long long x[N];
queue < long long > q;
vector < long long > G[N];
long long num[N] , dist[N];
bool vis[N];
long long n , d;
inline void bfs(long long s){
	for(long long i = 1;i <= n;++ i) vis[i] = 0 , dist[i] = num[i] = 0;
	num[s] = 1;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()){
		long long u = q.front();
		q.pop();
		for(long long i = 0;i < G[u].size();++ i){
			long long v = G[u][i];
			if(dist[u] + 1 == dist[v]) num[v] += num[u];
			if(vis[v]) continue;
			num[v] = num[u];
			vis[v] = 1;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
}
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	long long c , T;
	read(c) , read(T);
	while(T --){
		read(n) , read(d);
		for(long long i = 1;i <= n;++ i){
			read(x[i]);
			G[i].clear();
		}
		if(x[n] - x[1] <= d){
			puts("0");
			continue;
		}
		else{
			for(long long i = 1;i <= n;++ i){
				for(long long j = 1;j <= n;++ j){
					if(i == j) continue;
					if(x[i] - x[j] <= d) G[i].push_back(j);
				}
			}
			long long ans = 0;
			for(long long i = 1;i <= n;++ i){
				bfs(i);
				for(long long j = 1;j < i;++ j){
					if(num[j] == 2){
						++ ans;
					}
				}
			}
			cout << ans << '\n';	
		}
	} 
	return 0;
}
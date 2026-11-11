#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;
const int INF = 1e9;
struct Edge{
	int v, next;
}e[maxn];
int head[5005];
int ecnt;
long long x[maxn];
int dp[5005][5005];
int cnt[5005][5005];
int n;
void init(){
	for(int i = 0; i <= n; i++) head[i] = -1;
	ecnt = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = INF;
		}
	}
}
void add(int u, int v){
	e[ecnt].v = v;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt++;
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	dp[s][s] = 0;
	cnt[s][s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = e[i].next){
			int v = e[i].v;
			if(dp[s][v] > dp[s][u] + 1){
				dp[s][v] = dp[s][u] + 1;
				cnt[s][v] = cnt[s][u];
				q.push(v);
			}else if(dp[s][v] == dp[s][u] + 1){
				cnt[s][v] += cnt[s][u];
			}
		}
	}
}
void solve(){
	
	
	long long d;
	scanf("%d %lld", &n, &d);
	init();
	for(int i = 1; i <= n; i++){
		scanf("%lld",&x[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(x[j] - x[i] <= d){
				add(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		bfs(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 2; j <= n; j++){
			if(dp[i][j] >= INF) continue;
			if(cnt[i][j] == 2) ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	scanf("%d %d", &c, &t);
	while(t--){
		solve();
	}
	return 0;
}

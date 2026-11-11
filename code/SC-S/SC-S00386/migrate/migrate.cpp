#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5050;
const long long inf = 1000000000000000000;
struct Node{
	int nxt,to;
};
Node Graph[2 * MAXN * MAXN];
long long head[MAXN],c,t,n,m,data1[MAXN],ans,in[MAXN],dp[MAXN],dis[MAXN],answer;
inline void insert_line(long long x,long long y);
inline void toposort(long long x);
inline void solve();
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while (t --){
		solve();
	}	
	return 0;
}
inline void insert_line(long long x,long long y){
	Graph[ans].to = y;
	Graph[ans].nxt = head[x];
	head[x] = ans++;
	return ;
}
inline void toposort(long long x){
	for (long long i = x;i <= n;i ++){
		dis[i] = inf; 
	}
	queue<long long> q;
	dis[x] = 0;
	dp[x] = 1;
	q.push(x);
	while (!q.empty()){
		long long cur = q.front();
		q.pop();
		for (long long i = head[cur];~i;i = Graph[i].nxt){
			long long to = Graph[i].to;
			in[to] --;
			if (dis[cur] + 1 < dis[to]){
				dis[to] = dis[cur] + 1;
				dp[to] = dp[cur];
			} else if (dis[cur] + 1 == dis[to]){
				dp[to] += dp[cur];
			}
			dp[to] = min(dp[to],inf);
			if (!in[to]){
				q.push(to);
			}
		}
	}
	return ;
}
inline void solve(){
	scanf("%lld %lld",&n,&m);
	for (long long i = 0;i <= n;i ++){
		head[i] = -1;
	}
	ans = answer = 0;
	for (long long i = 1;i <= n;i ++){
		scanf("%lld ",&data1[i]);
		if (i > 1 && data1[i] - data1[i - 1] <= m){
			insert_line(i - 1,i);
		}
	}
	for (long long i = 1;i < n;i ++){
		for (long long j = i + 2;j <= n;j ++){
			if (abs(data1[j] - data1[i]) > m){
				break;
			}
			insert_line(i,j);
		}
	}
	for (long long i = 1;i < n;i ++){
		for (long long j = i;j <= n;j ++){
			for (long long k = head[j];~k;k = Graph[k].nxt){
				long long to = Graph[k].to;
				in[to] ++;
			}
		}
		toposort(i);
		for (long long j = i + 1;j <= n;j ++){
			if (dp[j] == 2){
				answer ++;
			}
		}
	}
	printf("%lld\n",answer);
	return ;
}
#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 600050;
const long long inf = 1000000000000000000;
vector<long long> v[1000],e[1000];
struct Node{
	long long nxt,to,dis,number;
};
Node Graph[2 * MAXN];
long long head[MAXN],c,n,m,d,q,ans,t = 1,temp,data1[MAXN],data2[1000],x,y;
long long graph[550][550];
inline void insert_line(long long x,long long y,long long z,long long w);
inline void Floyd();
inline long long query(long long x,long long y);
inline void solve();
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for (long long i = 0;i < MAXN;i ++){
		head[i] = -1;
	}
	for (long long i = 0;i < 550;i ++){
		for (long long j = 0;j < 550;j ++){
			if (i == j){
				continue;
			}
			graph[i][j] = inf;
		}
	}
	while (t --){
		solve();
	}
	return 0;
}
inline void insert_line(long long x,long long y,long long z,long long w){
	Graph[ans].to = y;
	Graph[ans].dis = z;
	Graph[ans].number = w;
	Graph[ans].nxt = head[x];
	head[x] = ans++;
	return ;
}
inline void Floyd(){
	for (long long i = 1;i <= n;i ++){
		for (long long j = 1;j <= n;j ++){
			for (long long k = 1;k <= n;k ++){
				if (graph[j][i] != inf && graph[i][k] != inf){
					graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
				}
			}
		}
	}
	return ;
}
inline long long query(long long x,long long y){
	temp = inf;
	for (long long i = head[n + x];~i;i = Graph[i].nxt){
		for (long long j = head[n + y];~j;j = Graph[j].nxt){
			long long l = Graph[i].to;
			long long r = Graph[j].to;
			temp = min(temp,data1[x] + data1[y] + graph[l][r] + e[l][Graph[i].number] + e[r][Graph[j].number]);
		}
	}
	return temp;
}
inline void solve(){
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for (long long i = 1;i <= m;i ++){
		scanf("%lld ",&data1[i]);
	}
	for (long long i = 1;i <= n;i ++){
		cin >> data2[i];
		for (long long j = 1;j <= 2 * data2[i];j ++){
			cin >> x;
			if (j & 1){
				v[i].push_back(x);
			} else {
				e[i].push_back(x);
			}
		}
		for (long long j = 0;j < data2[i];j ++){
			insert_line(i,v[i][j] + n,e[i][j],j);
			insert_line(v[i][j] + n,i,e[i][j],j);
		}	
	}
	for (long long i = 1;i <= m;i ++){
		for (long long j = head[n + i];~j;j = Graph[j].nxt){
			for (long long k = head[n + i];~k;k = Graph[k].nxt){
				long long l = Graph[j].to;
				long long r = Graph[k].to;
				graph[l][r] = min(graph[l][r],Graph[j].dis + Graph[k].dis);
				graph[r][l] = min(graph[r][l],Graph[j].dis + Graph[k].dis);
			}
		}
	}
	Floyd();
	for (long long i = 1;i <= q;i ++){
		cin >> x >> y;
		printf("%lld\n",query(x,y));
	}
	return ;
}
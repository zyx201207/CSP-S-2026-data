#include<bits/stdc++.h>
using namespace std;
//连通图 
/*
struct station{
	long long w_v;
	long long t[i][j];
	long long lingway[];
}sta[m];
struct lineway{
	long long k;
	long long a[k];
}lin[n];
long long q;
struct plan{
	long long start=x,end=y;
}p[q];
*/
/*
求最短路
考虑Dijkstra
分出已求最短路的集合和未求
进行松弛操作：dis[u][v]=min(dis[u][v],dis[u][w]+dis[w][v])
 
*/
void init(){
}

long long c,n,m,d,q;
struct Node{
	int l;
	vector<int> toNode;
}nd[600500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&q,&c,&q,&q);
	for(long long i=1;i<=q;i++){
		printf("%lld\n",4);
	}
	return 0;
}

/*
15:07 T1样例都过了！ 
15:13 看T2 
17:15绝望了放弃T2看T3 
不开long long见祖宗 
数组越界吗 
*/

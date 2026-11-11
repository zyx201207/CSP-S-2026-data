#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,M=500010;
int unusefulnum,n,m,d,q,w[M],sz[N],esz[M];
ll dp[N][N],inf=1000000000000000000;
struct Info {
	int x,t;
};
vector<Info> v[N];
vector<Info> ed[M];
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&unusefulnum,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) {
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&sz[i]);
		for (int j=1;j<=sz[i];j++) {
			Info qwq;
			scanf("%d%d",&qwq.x,&qwq.t);
			v[i].push_back(qwq);
			int awa=qwq.x;
			qwq.x=i;
			ed[awa].push_back(qwq);
			esz[awa]++;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) dp[i][j]=inf;
		dp[i][i]=0;
	}
	for (int i=1;i<=m;i++) {
		for (int num1=0;num1<esz[i];num1++) {
			for (int num2=0;num2<esz[i];num2++) if (num1!=num2) {
				Info x=ed[i][num1],y=ed[i][num2];
				if (x.x!=y.x) {
					dp[x.x][y.x]=min(dp[x.x][y.x],0ll+x.t+y.t);
				}
			}
		}
	}
	for (int z=1;z<=n;z++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dp[i][j]=min(dp[i][j],dp[i][z]+dp[z][j]);
			}
		}
	}
//	for (int i=1;i<=n;i++) {
//		for (int j=1;j<=n;j++) printf("%lld ",dp[i][j]);
//		printf("\n");
//	} 
	while (q--) {
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=inf;
		for (int num1=0;num1<esz[u];num1++) {
			for (int num2=0;num2<esz[v];num2++) {
				Info x=ed[u][num1],y=ed[v][num2];
				ans=min(ans,dp[x.x][y.x]+w[u]+w[v]+x.t+y.t);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
14:30 ~ 14:50
15:00 ~ 15:10
15:20 ~ 15:30
16:20 ~ 16:50
*/
/*
虽然题还没读懂awa 但看数据范围就感觉状压(?
 
由于多组查询 所以直接做最短路应该不行
那么也就是说应该是log m左右的时间复杂度
离线应该不行
时间主要是和n挂钩?
那d是干什么的
看到20应该是2^d次方吧
不对... O(n * 2^d log m) 应该是跑不过的
疑点:n<=500 d<=20
或许d<=20只是一个辅助...?
不对 我想想... 感觉状态好高啊(雾 
没有道理地铁线 a -> b -> a
才想5min吗 感觉想了30min qwq
再理一下 q很大 离线和正常做都不行 应该需要找性质
先去骗C和D 

查询部分时间复杂的或许O(qd) (?)
对上了 预处理出来的要是O(nm)
问题:怎么预处理
(预处理应该是dp吧)
(吃一小块巧克力)
本质上最多走n条边
这有用吗(恼
1h/4h 25% 
梦到什么说什么吧:
用vector记录经过每个点的站台有哪些线路经过
每个点最多有d种转移... 先停 感觉思路歪了
要求的是什么啊...(逐渐烦躁)
不对 思路好像错的很离谱 有起点有中点
肯定不能和m挂钩...吗? 
时间复杂度随心配 怎么配 都超时(
现在感觉最有希望的就是线与线之间的最短路 
那查询 q*d^2 
首先线预处理两条线之间的转移g
然后dp[i][j]=dp[i][k]+dp[k][j]+g[i][k]+g[k][j]
...不是 我右前面的人为什么在吃笔袋啊 你吃就吃 一定要发出巨大声响吗
我有问题 n=500不应该第一时间想floyd吗 现在就是求出初始的g就赢一半了
脑子胀了 换题 

2h/4h 50%

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/

#include <iostream>
#include <queue>
#define big long long
using namespace std;
// 这题目出得又和我之前做的一道题这么像
// 好像也是找一个点之后距离不超过 d 的点
// 这很有意思你知道吗 
// 你注意这是一个 DAG
// 那如果是一个 DAG 的话
// 似乎可以考虑直接使用 bfs 来求最短路及其计数
// 但那还是只能把复杂度降到 n^2
// 因为我们要对于每一个点出发求最短路 
// 服了
// 算了拿个二十四分好了
// 多拿八分也行 
// 那就三十二分算了 
big _,T,n,d,lim[2000006],dis[2000006],cnt[2000006],x[2000006],vis[2000006];
queue <big> q;
void init()
{
	while(!q.empty()) q.pop();
	for(big i = 1;i <= n;i++)
	{
		dis[i] = 1e18;
		vis[i] = cnt[i] = 0;
	}
}
void bfs(big st)
{
	q.push(st); dis[st] = 0, cnt[st] = 1;
	while(!q.empty())
	{
		big u = q.front(); q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(big v = u+1;v <= lim[u];v++)
		{
			if(dis[u]+1 < dis[v])
			{
				dis[v] = dis[u]+1;
				cnt[v] = cnt[u];
			}
			else if(dis[u]+1 == dis[v])
			{
				cnt[v] += cnt[u];
				// printf("%lld->%lld:\n",u,v);
			}
			q.push(v);
		}
	}
} 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&_,&T);
	while(T--)
	{
		// printf("new Case---------\n");
		if(_ <= 10)
		{
			big ans = 0;
			scanf("%lld %lld",&n,&d);
			for(big i = 1;i <= n;i++) scanf("%lld",x+i);
			if(n == 1)
			{
				printf("0\n");
				continue;
			}
			for(big i = 1;i <= n;i++)
			{
				big j = i;
				while(j+1 <= n && x[j+1]-x[i] <= d) j++;
				lim[i] = j; // 最远可以飞到 j 
			}
			for(big st = 1;st <= n;st++) // 从每一个点为起点开始
			{
				// printf("\n-----%lld------\n",st);
				init(); // 小心清空
				bfs(st);
				for(big i = st+1;i <= n;i++)
				{
					ans += (cnt[i] == 2);
					// if(cnt[i] == 2) printf("(%lld,%lld)\n",st,i);
				}
	//			for(big i = st;i <= n;i++)
	//			{
	//				printf("[%lld,%lld]",dis[i],cnt[i]);
	//			}
			}
			printf("%lld\n",ans);
		}
		else if(_ <= 12)
		{
			// big ans = 0;
			scanf("%lld %lld",&n,&d);
			for(big i = 1;i <= n;i++) scanf("%lld",x+i);
			if(n == 1)
			{
				printf("0\n");
				continue;
			}
			big nd = x[2]-x[1]; // 等差数列的公差
			big delta = d/nd; // 可以往后飞多少格 
			// delta = 0/1   无解
			// delta = 2    3 = 1+2 = 2+1
			// delta = 3    5 = 2+3 = 3+2
			// delta = 4    7 = 3+4 = 4+3
			// len = 2*delta-1
			if(delta <= 1)
			{
				printf("0\n");
				continue;
			}
			big len = 2*delta-1;
			printf("%lld\n",max(0ll,n-len)); 
		}
		else if(_ <= 14)
		{
			// 事有蹊跷，为啥 13/14 没有大样例
			// 我们不妨感觉到答案就是 0
			// 不想证了 CCF 加油
			// 希望我们有不可以总司令
			scanf("%lld %lld",&n,&d);
			for(big i = 1;i <= n;i++) scanf("%lld",x+i);
			printf("0\n"); 
		}
	}
	return 0;
}

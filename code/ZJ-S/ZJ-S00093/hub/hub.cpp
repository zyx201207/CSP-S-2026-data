#include <cstdio>
#include <vector>

constexpr int N = 15, INF = 0x3f3f3f3f;

void dfs(int x, int s);
bool check(int u);
void calc(int x, int fa);

int c, t, n, k, u, v, ans, dis[N];
std::vector<int> G[N];
bool vis[N], col[N];

int main(void)
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	
	while (t --> 0)
	{
		scanf("%d %d", &n, &k);
		ans = INF;
		
		for (int i = 1; i <= n; i++)
		{
			vis[i] = col[i] = false;
			G[i].clear();
		}
		
		for (int i = 2; i <= n; i++)
		{
			scanf("%d %d", &u, &v);
			
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		dfs(1, 0);
		printf("%d\n", ans);
	}
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

void dfs(int x, int s)
{
	if (s > k || n - x + 1 + s < k) return;
	
	if (x == n + 1)
	{
		if (s != k) return;
		
		for (int i = 1; i <= n; i++)
		{
			col[i] = false;
			dis[i] = vis[i] ? 0 : INF;
		}
		
		int cnt = 0, x = 0, y = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] && !col[i])
			{
				check(i);
				cnt++;
				
				if (cnt == 1) x = i;
				else if (cnt == 2) y = i;
				else break;
			}
		}
		
		if (cnt > 2) return;
		
		calc(x, x);
		calc(y, y);
		
		int res = 0;
		
		for (int i = 1; i <= n; i++) res = std::max(res, dis[i]);
		
		ans = std::min(ans, res);
		
		return;
	}
	
	dfs(x + 1, s);
	vis[x] = true;
	dfs(x + 1, s + 1);
	vis[x] = false;
}

bool check(int u)
{
	col[u] = true;
	
	for (int v : G[u])
	{
		if (col[v]) continue;
		if (vis[v]) check(v);
	}
}

void calc(int u, int fa)
{
	for (int v : G[u])
	{
		if (v == fa) continue;
		dis[v] = std::min(dis[v], dis[u] + 1);
		calc(v, u);
	}
}

/*
17:25

写完了。不想再写其他神秘部分分了。人有点难受www。

100 + 100 + 40 + 15 = 255 pts 这是我能达到的分数吗？我模拟赛从来没有这么高过。。 

希望不要挂。。给我一个 7 dog 吧！！求你了

我是 ZJ-J00072（？有点忘了）/ZJ-S00093

不会再考 J 组了我要睡懒觉www

考 S 组的时候有点躯体化真的有点难受感觉全身发烫

孩子们千万心态要好不要像我一样中度抑郁了zzz

希望 T2 不要爆空间

能想出 T2 O((m+q)d^2+n^3) 我已经很满意了，我觉得这就是正解                                       Bad 138 News :D

放我过去吧，本地感觉 1+eps second 不会测时间和空间www

T1 别挂虽然我一眼秒了

剩下部分分就算挂了也没事了我够满意了

本来父母让我抱着来玩的心态（两个月躺家里。。）来打，但是我根本做不到。。

祝大家都获得自己想要的成绩！！RP++ 

14:40 AC T1

15:55 AC T2 16:10 卡常卡空间 怎么要 760+ MB??? 还好都开的 1GiB 空间 

16:40 T3 40pts O(n^2)

17:20 T4 15pts O(n2^n)

我感激所有的一切。。谢谢你们口牙

LUOGU 998662 / xk2013 
*/
// 好了不写了，我不想再改文件字节数了，希望不要挂分我已经检查了 1e18 次代码和测试大样例了www 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
// Never Say Goodbye (Rizline) :D


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N=5005;

struct node
{
	int x,w;
};

int n,d,cnt,a[N],dis[N][N],way[N][N];
vector <int> g[N];
queue <int> q;

void bfs(int s)
{
	while (!q.empty()) q.pop();
	q.push(s);
	
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		
		for (int v:g[u])
		{
			if (dis[s][v]>=1e9)
			{
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
}

void dfs(int u,int s,int step)
{
	if (dis[s][u]<step) return ;
	if (dis[s][u]==step)
	{
		way[s][u]++;
	}
	
	for (int v:g[u])
	{
		dfs(v,s,step+1);	
	}	
} 

void solve()
{
	memset(dis,0x3f,sizeof dis);
	memset(way,0,sizeof way);
	
	cnt=0;
	cin >> n >> d;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	for (int i=1;i<=n;i++) 
	{
		g[i].clear();
		dis[i][i]=0;
	}
	
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (abs(a[i]-a[j])<=d)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	
	for (int i=1;i<=n;i++)
	{
		bfs(i);
	}
	
	for (int i=1;i<=n;i++)
	{
		dfs(i,i,0);
	}
	
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (way[i][j]==2)
			{
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	while (t--)
	{
		solve();
	}
	return 0;
}

/*
O(t(n+n+n2+n2+n2+n2))=O((n^2)t)

帮助推广oiermaster.cn 
*/
/*
陌生人，或者说，是迷惑大赏的编辑者，请在这里停留一会，谢谢。
我只是想要说一些真心话。
我今年12岁，初一了。我打OI 4年了（狭义的OI，就是不包括语法阶段：3年） 
曾经的经历，回不来了
曾经的懊悔，道歉不了了
还是希望把我摆在迷惑大赏上，记得给我私信一下。
窗外是夜空，面对白色的亮眼的屏幕，耳边其他考生的键盘声不绝。
无数个夜晚的记忆飞过。
过去，无法重拾。
不知道未来怎么办。
估计S只有卡线2=

哎。
繁重的whk，不支持学OI的一大堆任课老师。
我们坚持的时候在干生命？ 
坚持的住吗？
可以坚持吗？（《坚持三问》）

在cyez上课的时候，
看后排Alex_mumu在打phigros
还有几位在打MC

Worth?
Worth. 

OI让我学会了许多。
感受了许多。
这几句话在许多CSP-S的注释中都有。
我本来以为是一乐。
如今，真的感受到了这样的情况。

“我该在哪里停留？我问我自己。” ——《追忆》
对的，感觉就是这样。

惆怅，忧愁，担心，接踵而来。
t1会爆炸，t2写不出，t3部分分，t4一坨十。
我刚满12岁，这是我第一次打复赛。
向几名在OI中结识的好友敬礼。
向wwq老师敬礼。
向其他几名老师也敬礼。
感觉这是我距离AFO最近的时刻。

手指落在键盘上。
无比惆怅。 

此生无悔打OI，来世还做OIer。 

2026.10.31 18:07
*/ 

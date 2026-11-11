#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],p[N],maxn=INT_MIN;
bool vis[N];
void print()
{
	int ans=a[p[1]];
	for(int i=2;i<=m;i++)
		ans=ans&a[p[i]];
	maxn=max(maxn,ans);
}
void dfs(int x,int k)
{
	p[++k]=x;
	if(k==m)
	{
		print();
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		vis[i]=true;
		dfs(i,k);
		vis[i]=false;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vis[i]=true;
		dfs(i,0);
		vis[i]=false;
	}
	cout<<maxn;
	return 0;
}
/*
diy环节
美： 
战略规划：使友方所有信竞生的rp值和分数翻倍
爱国热忱：使一个信竞生的rp值和分数翻倍
英： 
奥创：敌方获得分数时，使其分数为0。rp++
道钉系统：敌方获得不小于100分时，使其分数为0
权杖号：敌方获得分数时，将其转换为20分
德： 
无心漫谈：敌方进入座位时，使其电脑关机
来自深处：敌方进入座位时，使其电脑死机
老兔子：使一个信竞生分数+50，直到比赛结束 
日：
火力爆发：使一个友方信竞生获得+1rp，分数x2，直到比赛结束
玉碎：使一个友方信竞生获得+4rp和+40分数，比赛结束时，使其睡觉
苏：
红色十月：使一个友方信竞生获得+3rp和+30分数
最后一击：使一个友方信竞生获得+3rp，比赛结束时，使其睡觉
法： 
解放：使友方信竞生获得+6rp，将三个病毒加入敌方电脑
病毒：使友方信竞生rp-1，分数-50，电脑休眠10min
意（天梯的意大利在哪发财呢）：
已发现分数高的信竞生，正在为您派遣最近的意大利人 
单刀直入：压力一个信竞生，若其分数最高，将其分数为0
一日之狮：使一个分数不小于300的信竞生分数为0
波：
喀尔巴仟步兵营：将一个友方蒟蒻转换为巨佬
延长战线：使一个友方信竞生的答题时间延长1h
芬：
白色死神：使所有敌方信竞生的rp值为0，将一个装糖的巨佬加入考场
装糖的巨佬：使看到自己的敌方信竞生rp为0 
澳：
击退进攻：使所有敌方信竞生离开座位
特混舰队：使一个信竞生rp-2，若其是巨佬，改为-3 
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 3e5 + 5;
int n, m, a[MAXN], ans[MAXM], last[MAXM], stack[MAXN];
bool vis[MAXM];
inline void solve(int x)
{
	int head = 0;
	for(int i = x; i <= n; i++)
	{
		if(vis[a[i]])
		{
			while(stack[head] != a[i])
			{
				head--;
			}
			head--;
		}
		stack[++head] = a[i];
		vis[a[i]] = true;
	}
	while(head)
	{
		ans[stack[head]]++;
		head--;
	}
	return ;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] < a[i - 1])
		{
			flag = false;
		}
	}
	if(flag)
	{
		for(int i = 1; i <= n; i++)
		{
			last[a[i]] = i;
		}
		for(int i = 1; i <= m; i++)
		{
			printf("%d ", last[i]);
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				vis[j] = false;
			}
			solve(i);
		}
		for(int i = 1; i <= m; i++)
		{
			printf("%d ", ans[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 11:09 可惜了 T2 卡我太长时间了应该做不完了（啊不我的 AK！） 
// 11:16 决定了，去打36分代码（n <= 500, m <= 200 + 性质A） 
// 11:23 stack 用成 queue 了，笑麻了 
// 11:33 和一位，记错时间了 
// 11:44 好像 MLE 了，手写栈吧 
// 11:47 哦不不不不不我的代码时间复杂度最高似乎是 O(n ^ 3)，通过看命了，不过至少能拿 20pts 不是吗 

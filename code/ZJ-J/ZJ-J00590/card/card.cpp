#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n,m;
int a[N];
int lst[M];
int dp[M];
vector < int > g[M];
struct node
{
	int val,id;
} ovo[M];
bool cmp(node x,node y)
{
	return x.id < y.id;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
//	printf("%d %d\n",n,m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		lst[a[i]] = i;
		g[a[i]].push_back(i);
	}
	for(int i = 1;i <= m;i++)
	{
		ovo[i].val = i;
		ovo[i].id = lst[i];
	}
	sort(ovo + 1,ovo + m + 1,cmp);
	for(int i = 1;i <= m;i++)
	{
		int awa = ovo[i].val;
//		printf("%d\n",awa);
		for(int j = 0;j < g[awa].size();j++)
		{
			int pos = g[awa][j];
			dp[awa]++;
			if(pos > 1)
			{
				if(lst[a[pos - 1]] == pos - 1) 
				{
					dp[awa] += dp[a[pos - 1]];
//					printf("!!%d %d\n",i,pos);
				}
			}
		}
//		printf("(%d) ",dp[i]);
	}
	dp[a[n]] = n;
	for(int i = 1;i <= m;i++) printf("%d ",dp[i]);
	return 0;
}

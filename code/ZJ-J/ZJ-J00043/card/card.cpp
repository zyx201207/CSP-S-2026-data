#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	
	int count[300009];
	int num[500009];
	int ans[300009];
	int pre[500009];
	
	memset(count,sizeof(count),0);
	memset(ans,sizeof(ans),0);
	
	for(int i=1;i<=n;i++)
	{
		int in;
		scanf("%d",&in);
		num[i]=in;
		count[in]++;
		pre[in] = i;
	}
	for(int i=1;i<=n;i++)
	{
		int st=i;
		for(int j=i;j<=n;j++)
		{
			if(count[num[j]] > 1 and j!=pre[num[j]])
			{
				for(int k=st;k<=j;k++)
					ans[num[k]]++;
				st = pre[num[j]]+1;
				j= st-1;
			}
		}
		for(int j=st;j<=n;j++)
		{
			ans[num[j]]++;	
		}
		count[num[i]]--;
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);	
	}
	return 0;
}

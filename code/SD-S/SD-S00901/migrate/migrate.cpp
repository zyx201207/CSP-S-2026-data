#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int st,ed,sum,n,d,cnt,ans;
void dfs(int k)
{
	if(k==ed)
	{
		if(sum==ans) cnt++;
		else if(sum<ans) 
		{
			ans=sum;
			cnt=1;
		}
	}
	int i=k+1;
	while(i<=ed&&x[i]-x[k]<=d) 
	{
		sum++;
		dfs(i);
		sum--;
		i++;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int num=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				st=i,ed=j,sum=0,cnt=1,ans=INT_MAX;
				dfs(st);
				if(cnt==2) num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

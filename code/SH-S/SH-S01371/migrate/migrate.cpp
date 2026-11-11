#include<bits/stdc++.h>
using namespace std;
int arr[2000005];
int n,d;
int check(int lt,int rt)
{
	if(arr[rt]-arr[lt]<=d)
		return 1;
	if(arr[rt]-arr[lt]==d+1)
		return 2;
	int i,j,t=0;
	for(i=lt;i<=rt;)
	{
		if(arr[i]+d<arr[i+1])
			return -1;
		j=i+1;
		while(j<=rt&&arr[j]-arr[i]<=d)
		{
			if(check(i,j)+check(j+1,rt)>2)
				return -1;
			++j;
		}
		i=j-1;
	}
	return 2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	int i,j,ans,t;
	scanf("%d %d",&c,&T);
	while(T--)
	{
		for(i=0;i<n;++i)
			arr[i]=0;
		ans=0;
		scanf("%d %d",&n,&d);
		for(i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n;++i)
		{
			for(j=1;j<n;++j)
			{
				t=check(i,j);
				if(t==2)
					++ans;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

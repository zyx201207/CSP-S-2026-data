#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int n,m,maxn=0,x;
	scanf("%d %d",&n,&m);
	int a[n+1],cnt;
	for(int i=1;i<=n;i++)
	{
		
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		x=m;
		cnt=1;
		for(int j=1;j<=i-1;j++)
		{
			x=x-a[i]+a[j];
			cnt++;
		}
		if(x>=0)
		{
			if(maxn<cnt)
			{
				maxn=cnt;
			}
		}
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

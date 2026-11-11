#include<bits/stdc++.h>
using namespace std;
int isusab[2000005];
int a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int tshinf,T;
	scanf("%d %d",&tshinf,&T);
	for(int TTT=1;TTT<=T;TTT++)
	{
		int n,d;
		scanf("%d %d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n-3;i++)
		{
			if(a[i+3]-a[i+2]<=d&&a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d&&a[i+1]-a[i]<=d)
			{
				isusab[i]=1;	
				ans++;			
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

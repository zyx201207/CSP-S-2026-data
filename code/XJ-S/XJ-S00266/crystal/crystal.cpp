#include<cstdio>
long long a[500010],m;
int n,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j,t;
	scanf("%d",&n);	
	scanf("%lld",&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			if(a[j]<=a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		t=m;
		int max=0;
		for(j=i;j<=n;j++)
		{
			if(a[j]==a[i])
			{
				max++;
			}
			else if(t>=a[i]-a[j])
			{
				max++;
				t=t-a[i]+a[j];
			}
			else
			{
				break;
			}
		}
		if(max>ans) ans=max;
	}
	printf("%d",ans);
	return 0;
} 

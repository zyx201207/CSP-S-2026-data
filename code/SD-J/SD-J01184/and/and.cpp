#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int num[200005];
	int vis[200005];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	if(m==1)
	{
		printf("%d",num[n-1]);
	}
	if(m==n)
	{
		int ans=num[0];
		for(int i=1;i<n;i++)
		{
			ans&=num[i];
		}
		printf("%d",ans);
	}
	if(m==2)
	{
		int max=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(num[i]&num[j]>max)
				{
					max=num[i]&num[j];
				}
			}
		}
		printf("%d",max);
	}
	if(m==n-1)
	{
		long long max=0;
		for(int i=0;i<n;i++){
			int ans=num[0];
			for(int j=0;j<n;j++)
			{
				if(j==i)
				{
					continue;
				}
				ans&=num[i-1];
			}
			if(ans>max)
			{
				max=ans;
			}
		}
		printf("%d",max);
	}
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=20){
		sort(a+1,a+n+1,cmp);
		printf("%d",a[m]);
	}
	else if(m==1){
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			if(a[i]>ans) ans=a[i];
		}
		printf("%d",ans);
	}
	else if(m==n)
	{
		int ans=a[1];
		for (int i=2;i<=n;i++) ans=ans&a[i];
		printf("%d",ans);
	}
	else if(m==2)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				int x=a[i]&a[j];
				if(x>ans) ans=x;
			}
		}
		printf("%d",ans);
	}
	else if(m==n-1)
	{
		int ans=0;
		for (int i=1;i<=n;i++)
		{
			int x=1048575;
			for (int j=1;j<=n;j++)
			{
				if(j==i) continue;
				x=x&a[j];
			}
			if(x>ans) ans=x;
		}
		printf("%d",ans);
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		printf("%d",a[m]);
	}
	return 0;
}

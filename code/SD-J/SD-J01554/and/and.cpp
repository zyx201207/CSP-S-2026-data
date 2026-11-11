#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans=0,vis[N];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=20)
	{
		for(int i=1;i<(1<<n);i++)
		{
			int t=0,t1=0;
			for(int j=0;j<=30;j++)
			{
				if((i>>j)&1)
				{
					t++;
					if(t1==0) t1=a[i+1];
					else t1=t1&a[i+1];
				}
			}
			if(t==m&&t1>ans)
			ans=t1;
		}
		printf("%d",ans);
		return 0;
	}
	else
	{
		int t=n;
		for(int i=31;i>=0;i--)
		{
			for(int j=1;j<=n;j++)
				vis[i]=0;
			
			int tt=0;
			for(int j=1;j<=n;j++)
			{
				if(((a[j]>>i)&1))
				{
					tt++;
					vis[j]=1;
				}
//				printf("%d ",a[j]);
			}
			
			if(tt>=m)
			{
				ans+=(1<<i);
				for(int j=1;j<=n;j++)
				{
					if(vis[j]==0)
						a[j]=0;
				}
			}
//			printf("%d %d\n",tt,ans);
		}
	}
	printf("%d",ans);
	return 0;
}

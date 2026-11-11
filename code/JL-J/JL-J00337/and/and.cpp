#include <stdio.h>
int n,m,maxa;
int s;
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	s=a[1];maxa=a[1];
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s&=a[i];
		maxa=maxa>a[i]?maxa:a[i];
	}
	if(m==1)
	{
		printf("%d",maxa);
		return 0;
	}
	else if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)
					if((a[i]&a[j])>ans)
						ans=a[i]&a[j];
		printf("%d",ans);
		return 0;
	}
	else if(m==n)
	{
		printf("%d",s);
		return 0;
	}
	else
	{
		int ans=0;
		for(int mask=0;mask<=(1<<n);mask++)
		{
			int cnt=0,ss=-1;
			for(int i=0;i<n;i++)
				if((mask>>i)&1)
				{
					cnt++;
					if(cnt>m)
						break;
					if(ss==-1)
						ss=a[i];
					else
						ss&=a[i];
				}
			if(cnt==m)
			{
				ans=ans>ss?ans:ss;
				//printf("%d\n",ans);
			}
		}
		printf("%d",ans);
		return 0;
	}			
}

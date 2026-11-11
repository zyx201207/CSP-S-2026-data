#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],base,cnt[50],f[3][200005];
bool cmp(int a,int b)
{
	for(int i=31;i>=0;i--)
	{
		if((a&(1<<i))!=(b&(1<<i)))return (a&(1<<i))>(b&(1<<i));
	}
	return 0;
}
int read()
{
	char ch=getchar();
	int c=0;
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')c=c*10+ch-'0',ch=getchar();
	return c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);;
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		printf("%d",ans);
		return 0;
	}
	if(m==n-1)
	{
		int ans=0;
		for(int i=1;i<=n;i++){
			int ans00=INT_MAX;
			for(int j=1;j<=n;i++)if(j!=i)ans00&=a[i];
			ans=max(ans,ans00);			
		}
		printf("%d",ans);
		return 0;
	}
	if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans=max(a[i],ans);

		}
					printf("%d",ans);
			return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int last=1-(i%2),now=i%2;
		f[i%2][1]=a[i];
		for(int j=1;j<=m;j++)
		{
			f[now][j]=max(f[now][j],f[last][j-1]&a[i]);
			f[now][j]=max(f[now][j],f[last][j]);
		}
	}
	printf("%d",f[n%2][m]);
	return 0;
}

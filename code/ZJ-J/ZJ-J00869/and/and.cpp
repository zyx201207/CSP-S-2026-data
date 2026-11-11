#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010],c[200010],ans,cnt,n,m,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		b[++k]=a[i];
	}
	for(int i=30;i>=0;i--)
	{
		int tmp=(1<<i);
		cnt=0;
		for(int j=1;j<=k;j++)
			if((b[j]&tmp)==tmp)
				c[++cnt]=b[j];
		if(cnt>=m)
		{
			for(int j=1;j<=cnt;j++)
				b[j]=c[j];
			k=cnt;
			ans|=tmp;
		}
	}
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int bit=(1<<30);bit;bit>>=1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
				continue;
			if(a[i]&bit)
				cnt++;
		}
		if(cnt>=m)
		{
			ans+=bit;
			for(int i=1;i<=n;i++)
			{
				if(vis[i])
					continue;
				if((a[i]&bit)==0)
					vis[i]=1;
			}
		}
	}
	printf("%d\n",ans);
}